//                                  I B E X
// File        : ibex_Optimizer.cpp
// Author      : Gilles Chabert, Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : May 14, 2012
// Last Update : Oct 18, 2023
//============================================================================

#include "ibex_Optimizer.h"
#include "ibex_Timer.h"
#include "ibex_Function.h"
#include "ibex_NoBisectableVariableException.h"
#include "ibex_BxpOptimData.h"
#include "ibex_CovOptimData.h"
#include "ibex_LoupFinder.h"

#include <float.h>
#include <stdlib.h>
#include <iomanip>
// Al principio de ibex_Optimizer.cpp:
#include <cmath>    // Para std::sqrt, std::exp, std::fabs
#include <vector>   // Para std::vector



using namespace std;

namespace ibex {

/*
 * TODO: redundant with ExtendedSystem.
 */
void Optimizer::write_ext_box(const IntervalVector& box, IntervalVector& ext_box) {
	int i2=0;
	for (int i=0; i<n; i++,i2++) {
		if (i2==goal_var) i2++; // skip goal variable
		ext_box[i2]=box[i];
	}
}

void Optimizer::read_ext_box(const IntervalVector& ext_box, IntervalVector& box) {
	int i2=0;
	for (int i=0; i<n; i++,i2++) {
		if (i2==goal_var) i2++; // skip goal variable
		box[i]=ext_box[i2];
	}
}

  Optimizer::Optimizer(int n, Ctc& ctc, Bsc& bsc, LoupFinder& finder,
		CellBufferOptim& buffer,
	       int goal_var, double eps_x, double rel_eps_f, double abs_eps_f) :   n(n), goal_var(goal_var),
										ctc(ctc), bsc(bsc), loup_finder(finder), buffer(buffer),
											   eps_x(n,eps_x), rel_eps_f(rel_eps_f), abs_eps_f(abs_eps_f),
										trace(0), timeout(-1), extended_COV(true), anticipated_upper_bounding(true),
										status(SUCCESS),
										uplo(NEG_INFINITY), uplo_of_epsboxes(POS_INFINITY), loup(POS_INFINITY),
										loup_point(IntervalVector::empty(n)), initial_loup(POS_INFINITY), loup_changed(false),
										time(0), nb_cells(0), cov(NULL),loup_updates(0), loup_updates_ipopt(0) {
    pseudocosts_initialization();
    if (trace) cout.precision(12);
}


Optimizer::Optimizer(OptimizerConfig& config) :
		n           (config.nb_var()),
		goal_var    (config.goal_var()),
		ctc         (config.get_ctc()),
		bsc         (config.get_bsc()),
		loup_finder (config.get_loup_finder()),
		integerobj  (config.with_integerobj()),
		buffer      (config.get_cell_buffer()),
		eps_x       (config.get_eps_x()),
		rel_eps_f   (config.get_rel_eps_f()),
		abs_eps_f   (config.get_abs_eps_f()),
		trace       (config.get_trace()),
		timeout     (config.get_timeout()),
		extended_COV(config.with_extended_cov()),
		anticipated_upper_bounding(config.with_anticipated_upper_bounding()),
		status(SUCCESS),
		uplo(NEG_INFINITY), uplo_of_epsboxes(POS_INFINITY), loup(POS_INFINITY),
		loup_point(IntervalVector::empty(n)), initial_loup(POS_INFINITY), loup_changed(false),
		time(0), nb_cells(0), cov(NULL),loup_updates(0), loup_updates_ipopt(0) {
  pseudocosts_initialization();
}

Optimizer::~Optimizer() {
	if (cov) delete cov;
}

// compute the value ymax (decreasing the loup with the precision)
// the heap and the current box are contracted with y <= ymax
double Optimizer::compute_ymax() {
      if (integerobj)
  	 return (loup-1);
      else
      if (anticipated_upper_bounding) {
		//double ymax = loup - rel_eps_f*fabs(loup); ---> wrong :the relative precision must be correct for ymax (not loup)
		double ymax = loup>0 ?
				1/(1+rel_eps_f)*loup
		:
				1/(1-rel_eps_f)*loup;

		if (loup - abs_eps_f < ymax)
			ymax = loup - abs_eps_f;
		//return ymax;
		return next_float(ymax);
	} else
		return loup;
}

// NO necesitas incluir ibex_LoupFinderIpoptB.h

bool Optimizer::update_loup(const IntervalVector& box, BoxProperties& prop) {
    double old_loup = loup;

    try {
        auto p = loup_finder.find(box, loup_point, loup, prop);
        loup = p.second;
        loup_point = p.first;

        if (loup < old_loup) {
            loup_updates++;   // Contador general

			            // DEBUG: Siempre mostrar cuando hay mejora
            cout << " [LOUP UPDATE #" << loup_updates 
                 << " improvement: " << (old_loup - loup) 
                 << " new loup=" << loup << "]" << endl;
            
            // ¡NO necesita dynamic_cast! Usamos el método virtual
            if (loup_finder.is_ipopt()) {
                loup_updates_ipopt++;
                
                // Intentar obtener el punto solución específico de Ipopt
                // Usamos loup_point por defecto, pero podríamos intentar
                // obtener el punto específico si el finder lo proporciona
                
                if (!loup_point.is_empty()) {
                    record_ipopt_success(loup_point.mid(), loup);
                }
                
                if (trace) {
                    cout << " [Ipopt improvement: " << (old_loup - loup) 
                         << ", total Ipopt successes: " << loup_updates_ipopt << "]" << endl;
                }
            }
        }

        if (trace) {
            cout << "                    ";
            cout << "\033[32m loup= " << loup << "\033[0m" << endl;
        }

        return true;

    } catch (LoupFinder::NotFound&) {
        return false;
    }
}



//bool Optimizer::update_entailed_ctr(const IntervalVector& box) {
//	for (int j=0; j<m; j++) {
//		if (entailed->normalized(j)) {
//			continue;
//		}
//		Interval y=sys.ctrs[j].f.eval(box);
//		if (y.lb()>0) return false;
//		else if (y.ub()<=0) {
//			entailed->set_normalized_entailed(j);
//		}
//	}
//	return true;
//}

void Optimizer::update_uplo() {
        double new_uplo=POS_INFINITY;
	//	cout << " buffer empty "  << buffer.empty() << " uplo " << uplo << endl;
	if (! buffer.empty()) {
 		new_uplo= buffer.minimum();
		//		cout << " new_uplo " << new_uplo <<  " loup " << loup << endl;
		if (new_uplo > loup && uplo_of_epsboxes > loup) {
		        cout << " loup = " << loup << " new_uplo=" << new_uplo <<  " uplo_of_epsboxes=" << uplo_of_epsboxes << endl;
			ibex_error("optimizer: new_uplo>loup (please report bug)");
		}
		if (new_uplo < uplo) {
			cout << "uplo= " << uplo << " new_uplo=" << new_uplo << endl;
			ibex_error("optimizer: new_uplo<uplo (please report bug)");
		}

		// uplo <- max(uplo, min(new_uplo, uplo_of_epsboxes))
		if (new_uplo < uplo_of_epsboxes) {
			if (new_uplo > uplo) {
				uplo = new_uplo;

				if (trace)
					cout << "\033[33m uplo= " << uplo << "\033[0m" << endl;
			}
		}
		else uplo = uplo_of_epsboxes;
	}
	else if (buffer.empty() && loup != POS_INFINITY) {
		// empty buffer : new uplo is set to ymax (loup - precision) if a loup has been found
                new_uplo=compute_emptybuffer_uplo();

		//	        cout << " new uplo buffer empty " << new_uplo << " uplo " << uplo << endl;
		//              cout << "uplo of epsboxes" << uplo_of_epsboxes << endl;
		double m = (new_uplo < uplo_of_epsboxes) ? new_uplo :  uplo_of_epsboxes;
		double olduplo=uplo;
		if (uplo < m) uplo = m; // warning: hides the field "m" of the class

		if (trace && uplo > olduplo) cout << "\033[33m uplo= " << uplo << "\033[0m" << endl;
		// note: we always have uplo <= uplo_of_epsboxes but we may have uplo > new_uplo, because
		// ymax is strictly lower than the loup.
	}

}

double Optimizer::compute_emptybuffer_uplo(){
  if (integerobj)
    return loup;
  else
    return compute_ymax()+1.e-15; // not new_uplo=loup, because constraint y <= ymax was enforced
  }

  
void Optimizer::update_uplo_of_epsboxes(double ymin) {

	// the current box cannot be bisected.  ymin is a lower bound of the objective on this box
	// uplo of epsboxes can only go down, but not under uplo : it is an upperbound for uplo,
	// that indicates a lowerbound for the objective in all the small boxes
	// found by the precision criterion
	assert (uplo_of_epsboxes >= uplo);
	assert(ymin >= uplo);
	if (uplo_of_epsboxes > ymin) {
		uplo_of_epsboxes = ymin;
		if (ymin < loup)
		  if (trace) {
		    cout << " unprocessable tiny box: now uplo<=" << setprecision(12) <<  uplo_of_epsboxes << " uplo=" << uplo << endl;
		  }
	}
}

void Optimizer::handle_cell(Cell& c, bool direction) {
    contract_and_bound(c, direction);
    
    if (c.box.is_empty()) {
        delete &c;
    } else {
        if (integerobj) {
            c.box[goal_var] = integer(c.box[goal_var]);
            if (c.box[goal_var].is_empty()) {
                delete &c;
                return;
            }
        }
        
        // CALCULAR BONUS DE IPOPT PARA ESTA CELDA
        IntervalVector tmp_box(n);
        read_ext_box(c.box, tmp_box);
        
        double ipopt_bonus = compute_ipopt_bonus(tmp_box);
        
        // DEBUG
        if (trace >= 2 && ipopt_bonus > 0) {
            cout << " [Ipopt bonus for cell: " << ipopt_bonus 
                 << ", old score: " << c.ipopt_score
                 << ", new score: " << (c.ipopt_score + ipopt_bonus) << "]" << endl;
        }
        
        c.ipopt_score += ipopt_bonus;
        
        if (ipopt_bonus > 0.01) {
            c.ipopt_success_count++;
            c.ipopt_recent_success = true;
            
            if (!loup_point.is_empty() && c.ipopt_best_point.size() == 0) {
                c.ipopt_best_point = loup_point.mid();
            }
        }
        
        // Resto del código original...
        buffer.push(&c);
    }
}
  void Optimizer::contract_and_bound(Cell& c, bool direction) {

	/*======================== contract y with y<=loup ========================*/

	Interval& y=c.box[goal_var];
	double ymin=y.lb();
        double diam= compute_diam_for_pseudocost(c,direction,c.bisected_var);   // for pseudocost
	
	//	cout << " box before contract " << c.box << endl;
	double ymax;
	if (loup==POS_INFINITY) ymax = POS_INFINITY;
	// ymax is slightly increased to favour subboxes of the loup
	// TODO: useful with double heap??
	else ymax = compute_ymax()+1.e-15;

	y &= Interval(NEG_INFINITY,ymax);
        if (integerobj) y=integer(y);
	if (y.is_empty()) {
	  c.box.set_empty();
	  return;
	}
	else {
	  c.prop.update(BoxEvent(c.box,BoxEvent::CONTRACT,BitSet::singleton(n+1,goal_var)));
	}

        contract(c);

	if (c.box.is_empty()) return;
	
	//	cout << " [contract]  x after=" << c.box << endl;
	//	cout << " [contract]  y after=" << y << endl;
	/*====================================================================*/

	/*========================= update loup =============================*/



	
	IntervalVector tmp_box(n);
	read_ext_box(c.box,tmp_box);

	c.prop.update(BoxEvent(c.box,BoxEvent::CHANGE));

	bool loup_ch=update_loup(tmp_box, c.prop);

	// update of the upper bound of y in case of a new loup found
	if (loup_ch) {
		y &= Interval(NEG_INFINITY,compute_ymax());
		c.prop.update(BoxEvent(c.box,BoxEvent::CONTRACT,BitSet::singleton(n+1,goal_var)));
	}

	//TODO: should we propagate constraints again?

	loup_changed |= loup_ch;

	if (y.is_empty()) { // fix issue #44
		c.box.set_empty();
		return;
	}
	
	/*====================================================================*/
	// Note: there are three different cases of "epsilon" box,
	// - NoBisectableVariableException raised by the bisector (---> see optimize(...)) which
	//   is independent from the optimizer
	// - the width of the box is less than the precision given to the optimizer ("prec" for the original variables
	//   and "goal_abs_prec" for the goal variable)
	// - the extended box has no bisectable domains (if prec=0 or <1 ulp)
	if (((tmp_box.diam().max()-eps_x.max())<0 && y.diam() <=abs_eps_f)
	    || (!c.box.is_bisectable())) {
	  //	  cout << tmp_box.max_diam() <<  " eps_x.max() " << eps_x.max() << endl;
	  //	  cout << "  box  " << c.box << endl;
	  //	  cout << " is_bisectable : " << c.box.is_bisectable() << endl;
	  if (tmp_box.diam().max()>0) // there is an eps box only if max diam is positive
	    update_uplo_of_epsboxes(y.lb());
	  c.box.set_empty();
	  return;
	}

	// ** important: ** must be done after upper-bounding
	//kkt.contract(tmp_box);
	
	if (tmp_box.is_empty()) {
		c.box.set_empty();
		
	}/*
	else {
	      the current extended box in the cell is updated     POURQUOI BN ???
	  		write_ext_box(tmp_box,c.box);
	}
	*/
        if (c.bisected_var!=-1)
	  update_pseudocosts(c,ymin,diam, c.bisected_var,direction);


}
  	
 
void  Optimizer::contract(Cell & c){
  	/*================ contract x with f(x)=y and g(x)<=0 ================*/
	//cout << " [contract]  x before=" << c.box << endl;
	//cout << " [contract]  y before=" << y << endl;

	ContractContext context(c.prop);
	if (c.bisected_var!=-1) {
		context.impact.clear();
		context.impact.add(c.bisected_var);
		context.impact.add(goal_var);
	}
	//	cout << " before ctc contract " << c.box << endl;
	ctc.contract(c.box, context);
	//        cout << " after ctc contract " << c.box << endl;
	//cout << c.prop << endl;
  }

Optimizer::Status Optimizer::optimize(const IntervalVector& init_box, double obj_init_bound) {
	start(init_box, obj_init_bound);
	return optimize();
}


Optimizer::Status Optimizer::optimize(const CovOptimData& data, double obj_init_bound) {
	start(data, obj_init_bound);
	return optimize();
}

Optimizer::Status Optimizer::optimize(const char* cov_file, double obj_init_bound) {
	CovOptimData data(cov_file);
	start(data, obj_init_bound);
	return optimize();
}

  
 void Optimizer::start(const IntervalVector& init_box, double obj_init_bound) {

	loup=obj_init_bound;
        
	// Just to initialize the "loup" for the buffer
	// TODO: replace with a set_loup function
	buffer.contract(loup);

	uplo=NEG_INFINITY;
	uplo_of_epsboxes=POS_INFINITY;
	//	if (loup_point.is_empty())	loup_point = init_box; //.set_empty();

	nb_cells=0;

	buffer.flush();

	Cell* root=new Cell(IntervalVector(n+1));

	write_ext_box(init_box, root->box);
	root->box[goal_var]=Interval(uplo,loup);
	//	cout << "root->box[goal_var]" <<  root->box[goal_var] << endl; 
	// add data required by the bisector
	bsc.add_property(init_box, root->prop);

	// add data required by the contractor
	ctc.add_property(init_box, root->prop);

	// add data required by the buffer
	buffer.add_property(init_box, root->prop);

	// add data required by the loup finder
	loup_finder.add_property(init_box, root->prop);

	//cout << "**** Properties ****\n" << root->prop << endl;

	loup_changed=false;
	initial_loup=obj_init_bound;
	
       

	time=0;

	if (cov) delete cov;
	cov = new CovOptimData(extended_COV? n+1 : n, extended_COV);
	cov->data->_optim_time = 0;
	cov->data->_optim_nb_cells = 0;
        Timer timer;
	timer.start();

	handle_cell(*root,true);

	timer.stop();
	time+= timer.get_time();
	if (trace) cout << " root time " << timer.get_time() << endl;
}

void Optimizer::start(const CovOptimData& data, double obj_init_bound) {

	loup=obj_init_bound;

	// Just to initialize the "loup" for the buffer
	// TODO: replace with a set_loup function
	buffer.contract(loup);

	uplo=data.uplo();
	loup=data.loup();
	loup_point=data.loup_point();
	uplo_of_epsboxes=POS_INFINITY;

	nb_cells=0;

	buffer.flush();

	for (size_t i=loup_point.is_empty()? 0 : 1; i<data.size(); i++) {

		IntervalVector box(n+1);

		if (data.is_extended_space())
			box = data[i];
		else {
			write_ext_box(data[i], box);
			//			cout << " init box " << box << endl;
			box[goal_var] = Interval(uplo,loup);
			//			cout << " contracted box " << box << endl;
			ctc.contract(box);
			if (box.is_empty()) continue;
		}

		Cell* cell=new Cell(box);

		// add data required by the cell buffer
		buffer.add_property(box, cell->prop);

		// add data required by the bisector
		bsc.add_property(box, cell->prop);

		// add data required by the contractor
		ctc.add_property(box, cell->prop);

		// add data required by the loup finder
		loup_finder.add_property(box, cell->prop);

		buffer.push(cell);
	}

	loup_changed=false;
	initial_loup=obj_init_bound;

	time=0;

	if (cov) delete cov;
	cov = new CovOptimData(extended_COV? n+1 : n, extended_COV);
	cov->data->_optim_time = data.time();
	cov->data->_optim_nb_cells = data.nb_cells();
}





Optimizer::Status Optimizer::optimize() {
	Timer timer;
	timer.start();

	update_uplo();
	/*   does not work : init_pseudocosts does not improve the solving"
        if (!buffer.empty())
	  init_pseudocosts(*(buffer.top()));
	*/
	try {
	  
	     while (!buffer.empty()) {

			loup_changed=false;
			// for double heap , choose randomly the buffer : top  has to be called before pop
			Cell *c = buffer.top();
			update_pseudocosts_score(*c);
			if (trace >= 2) cout << " current box " << c->box << endl;

			try {
			        bsc.set_pseudo_costs (&bisection_pseudocosts_score);
				pair<Cell*,Cell*> new_cells=bsc.bisect(*c);
				buffer.pop();
				delete c; // deletes the cell.

				nb_cells+=1;  // counting the cells handled ( in previous versions nb_cells was the number of cells put into the buffer after being handled)

				int var=(new_cells.first)->bisected_var;
				//	cout << "bisected var " << var << endl;
				Cell& cell1=*(new_cells.first);
				handle_cell(cell1, true);
				nb_cells+=1;
				Cell& cell2=*(new_cells.second);
				handle_cell(cell2, false);

				if (uplo_of_epsboxes == NEG_INFINITY) {
					break;
				}
				if (loup_changed) {
					// In case of a new upper bound (loup_changed == true), all the boxes
					// with a lower bound greater than (loup - goal_prec) are removed and deleted.
					// Note: if contraction was before bisection, we could have the problem
					// that the current cell is removed by contractHeap. See comments in
					// older version of the code (before revision 284).

					double ymax=compute_ymax();

					buffer.contract(ymax);

					//cout << " now buffer is contracted and min=" << buffer.minimum() << endl;

					// TODO: check if happens. What is the return code in this case?
					if (ymax <= NEG_INFINITY) {
						if (trace) cout << " infinite value for the minimum " << endl;
						break;
					}
				}
				update_uplo();

				if (!anticipated_upper_bounding) // useless to check precision on objective if 'true'
					if (get_obj_rel_prec()<rel_eps_f || get_obj_abs_prec()<abs_eps_f)
						break;
				if (timeout>0)
				  timer.check(timeout-loup_finder.ampltime-loup_finder.ipopttime); // TODO: not reentrant, JN: done ; integrating external solvers time BN
				//			time = timer.get_time();

			}
			catch (NoBisectableVariableException& ) {
			  //              cout << "box " << c->box << endl;
			  //		  cout << "NoBisectableVariableException" << endl;
				update_uplo_of_epsboxes((c->box)[goal_var].lb());
				buffer.pop();
				delete c; // deletes the cell.
				update_uplo(); // the heap has changed -> recalculate the uplo (eg: if not in best-first search)

			}
	     }
	     

	 	timer.stop();
	 	time += timer.get_time();
		// No solution found and optimization stopped with empty buffer
		// before the required precision is reached => means infeasible problem
	 	if (uplo_of_epsboxes == NEG_INFINITY)
	 		status = UNBOUNDED_OBJ;
	 	else if (uplo_of_epsboxes == POS_INFINITY && (loup==POS_INFINITY || (loup==initial_loup && abs_eps_f==0 && rel_eps_f==0)))
	 		status = INFEASIBLE;
	 	else if (loup==initial_loup)
	 		status = NO_FEASIBLE_FOUND;
	 	else if (get_obj_rel_prec()>rel_eps_f && get_obj_abs_prec()>abs_eps_f)
	 		status = UNREACHED_PREC;
	 	else
	 		status = SUCCESS;
	}
	catch (TimeOutException& ) {
		status = TIME_OUT;
		time = timer.get_time();
	}

	/* TODO: cannot retrieve variable names here. */
	for (int i=0; i<(extended_COV ? n+1 : n); i++)
		cov->data->_optim_var_names.push_back(string(""));

	cov->data->_optim_optimizer_status = (unsigned int) status;
	cov->data->_optim_uplo = uplo;
	cov->data->_optim_uplo_of_epsboxes = uplo_of_epsboxes;
	cov->data->_optim_loup = loup;

	cov->data->_optim_time += time;
	cov->data->_optim_nb_cells += nb_cells;
	cov->data->_optim_loup_point = loup_point;

	// for conversion between original/extended boxes
	IntervalVector tmp(extended_COV ? n+1 : n);

	// by convention, the first box has to be the loup-point.
	if (extended_COV) {
		write_ext_box(loup_point, tmp);
		tmp[goal_var] = Interval(uplo,loup);
		cov->add(tmp);
	}
	else {
		cov->add(loup_point);
	}

	while (!buffer.empty()) {
		Cell* cell=buffer.top();
		if (extended_COV)
			cov->add(cell->box);
		else {
			read_ext_box(cell->box,tmp);
			cov->add(tmp);
		}
		delete buffer.pop();
	}

	return status;
}

namespace {
const char* green() {
#ifndef _WIN32
	return "\033[32m";
#else
	return "";
#endif
}

const char* red(){
#ifndef _WIN32
	return "\033[31m";
#else
	return "";
#endif
}

const char* white() {
#ifndef _WIN32
	return "\033[0m";
#else
	return "";
#endif
}

}

void Optimizer::report() {

	if (!cov || !buffer.empty()) { // not started
		cout << " not started." << endl;
		return;
	}

	switch(status) {
	case SUCCESS:
		cout << green() << " optimization successful!" << endl;
		break;
	case INFEASIBLE:
		cout << red() << " infeasible problem" << endl;
		break;
	case NO_FEASIBLE_FOUND:
	  if (loup_point.is_empty())
		cout << red() << " no feasible point found (the problem may be infeasible)" << endl;
	  break;
	case UNBOUNDED_OBJ:
		cout << red() << " possibly unbounded objective (f*=-oo)" << endl;
		break;
	case TIME_OUT:
		cout << red() << " time limit " << timeout << "s. reached " << endl;
		break;
	case UNREACHED_PREC:
		cout << red() << " unreached precision" << endl;
		break;
	}
	cout << white() <<  endl;

	// No solution found and optimization stopped with empty buffer
	// before the required precision is reached => means infeasible problem
	if (status==INFEASIBLE) {
		cout << " infeasible problem " << endl;
	}
	else {

	  cout << " f* in\t[" << uplo << "," << loup << "]" << endl;
	  cout << "\t(best bound)" << endl << endl;

	  if (loup==initial_loup && loup_point.is_empty())
	    cout << " x* =\t--\n\t(no feasible point found)" << endl;
	  else {
	    if (loup_finder.rigorous())
	      cout << " x* in\t" << loup_point << endl;
	    else
	      cout << " x* =\t" << loup_point.lb() << endl;
	    cout << "\t(best feasible point)" << endl;
	  }
	  cout << endl;
	  double rel_prec=get_obj_rel_prec();
	  double abs_prec=get_obj_abs_prec();
	  if (integerobj) {  // with the integrality tolerance it is possible to obtain an objective lower than uplo
	    rel_prec = fabs(rel_prec);
	    abs_prec = fabs(abs_prec);
	  }
		  

	  cout << " relative precision on f*:\t" << rel_prec;
	  if (rel_prec <= rel_eps_f)
	    cout << green() << " [passed] " << white();
	  cout << endl;
	  
	  cout << " absolute precision on f*:\t" << abs_prec;
	  if (abs_prec <= abs_eps_f)
	    cout << green() << " [passed] " << white();
	  cout << endl;
	}

	cout << " cpu time used:\t\t\t" << time << "s";
	if (cov->time()!=time)
		cout << " [total=" << cov->time() << "]";
	cout << endl;
	cout << " number of cells:\t\t" << nb_cells;
	if (cov->nb_cells()!=nb_cells)
		cout << " [total=" << cov->nb_cells() << "]";
	cout << endl << endl;
}

void Optimizer::record_ipopt_success(const Vector& point, double loup_value) {
    IpoptSuccess success(point, loup_value, nb_cells, time);
    
    ipopt_success_history.push_back(success);
    
    // Limitar tamaño del historial
    if (ipopt_success_history.size() > MAX_IPOPT_HISTORY) {
        ipopt_success_history.erase(ipopt_success_history.begin());
    }
    
    if (trace) {
        cout << " [Ipopt success recorded: loup=" << loup_value 
             << ", history size=" << ipopt_success_history.size() << "]" << endl;
    }
}

double Optimizer::compute_ipopt_bonus(const IntervalVector& box) const {
    if (ipopt_success_history.empty()) {
        return 0.0;
    }
    
    double total_bonus = 0.0;
    Vector box_center = box.mid();
    double box_diag = box.max_diam();
    
    // Si la caja es muy grande, reducir el bonus
    if (box_diag > 100.0) {
        return 0.0;  // No dar bonus en cajas muy grandes
    }
    
    for (const auto& success : ipopt_success_history) {
        // 1. Calcular qué tan cerca está el centro de la caja del punto de éxito
        double squared_distance = 0.0;
        bool inside_box = true;
        
        for (int i = 0; i < box_center.size(); i++) {
            double diff = box_center[i] - success.point[i];
            squared_distance += diff * diff;
            
            // Verificar si el punto está dentro de la caja
            if (success.point[i] < box[i].lb() || success.point[i] > box[i].ub()) {
                inside_box = false;
            }
        }
        
        double distance = std::sqrt(squared_distance);
        
        // 2. Bonus base por estar dentro de la caja
        double base_bonus = inside_box ? 1.0 : 0.0;
        
        // 3. Bonus por distancia (inversamente proporcional)
        double distance_bonus = 1.0 / (1.0 + distance);
        
        // 4. Bonus por calidad de la solución
        double quality_bonus = 0.0;
        if (initial_loup != POS_INFINITY && initial_loup != 0.0) {
            // Normalizar mejora entre 0 y 1
            double max_possible_improvement = std::fabs(initial_loup);
            if (max_possible_improvement > 1e-10) {
                double actual_improvement = initial_loup - success.loup_value;
                if (actual_improvement > 0) {
                    quality_bonus = actual_improvement / max_possible_improvement;
                }
            }
        }
        
        // 5. Combinar todos los bonuses
        double combined_bonus = (base_bonus * 0.5 + distance_bonus * 0.3 + quality_bonus * 0.2);
        
        // 6. Aplicar decaimiento temporal (éxitos recientes valen más)
        double time_decay = 1.0;
        if (time > 0) {
            double time_since_success = time - success.timestamp;
            if (time_since_success > 0) {
                time_decay = 1.0 / (1.0 + time_since_success / 10.0); // Decae en 10 segundos
            }
        }
        
        total_bonus += combined_bonus * time_decay;
    }
    
    // Limitar el bonus máximo
    const double MAX_BONUS = 10.0;
    return std::min(total_bonus, MAX_BONUS);
}
void Optimizer::propagate_ipopt_score(Cell& parent, Cell& child1, Cell& child2) {
    const double DECAY_FACTOR = 0.6;  // 60% del score se hereda
    
    child1.ipopt_score = parent.ipopt_score * DECAY_FACTOR;
    child2.ipopt_score = parent.ipopt_score * DECAY_FACTOR;
    
    child1.ipopt_success_count = parent.ipopt_success_count;
    child2.ipopt_success_count = parent.ipopt_success_count;
    
    child1.ipopt_recent_success = false;
    child2.ipopt_recent_success = false;
    
    // Copiar el mejor punto si existe
    if (parent.ipopt_best_point.size() == parent.box.size() - 1) { // -1 porque box incluye variable objetivo
        child1.ipopt_best_point = parent.ipopt_best_point;
        child2.ipopt_best_point = parent.ipopt_best_point;
    }
}


} // end namespace ibex
