//============================================================================
//                                  I B E X                                   
// File        : ibex_Bsc.cpp
// Author      : Gilles Chabert
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : May 8, 2012
// Last Update : Jul 6, 2018
//============================================================================

#include "ibex_Bsc.h"
#include "ibex_Exception.h"
#include "ibex_Id.h"

using namespace std;

namespace ibex {

double Bsc::default_ratio() {
	return 0.45;
}

Bsc::Bsc(double prec) : _prec(1,prec) {
	if (prec<0) ibex_error("precision must be a nonnegative number");
	// note: prec==0 allowed with, e.g., LargestFirst
}

Bsc::Bsc(const Vector& prec) : _prec(prec) {
	for (int i=0; i<prec.size(); i++)
		if (prec[i]<0) ibex_error("precision must be a nonnegative number");
}

void Bsc::add_property(const IntervalVector& init_box, BoxProperties& map) {

}
  
void Bsc::set_pseudo_costs(vector<double>* pseudocosts){
    pseudo_costs=pseudocosts;
}

  bool Bsc::integer_relaxation_condition(const Cell & c, int i) const{
    double integer_tolerance=1.e-4;
    return
      c.relax_sol[c.box.size()-1] == DBL_MAX ||
      (c.relax_sol[i] - std::floor(c.relax_sol[i]) > integer_tolerance
       &&
       std::ceil (c.relax_sol[i]) - c.relax_sol[i] > integer_tolerance)
      ;
  }
  
  int Bsc::pseudocost_int_var_to_bisect  (const Cell & c, const BitSet& b) const{
    int var=-1;
    const IntervalVector& box=c.box;
    double minimal_pseudo_cost= 1.e-12;  
    double max_pseudo_cost=0.0;

    for (int i =0; i< box.size()-1; i++){
      if (b[i]
	  && integer_relaxation_condition(c,i)
	  && (i!= c.bisected_var)
	  && (*pseudo_costs)[i] > max_pseudo_cost && !too_small(box,i)
	  && ((*pseudo_costs)[i] > minimal_pseudo_cost) 
	  ){
	max_pseudo_cost=(*pseudo_costs)[i];
	var=i;}
    }
    //    cout << "pseudo cost var " << var << endl;
    return var;
   }


 int Bsc::pseudocost_var_to_bisect  (const Cell & c) const{
    int var=-1;
    const IntervalVector& box=c.box;
    double minimal_pseudo_cost= 1.e-12;// ( epsilon*epsilon in ibex_PseudoCost.cpp avec epsilon=1e-6)
    double max_pseudo_cost=0.0;
   
    for (int i =0; i< box.size()-1; i++){
      if ((i!= c.bisected_var)
	  && (*pseudo_costs)[i] > max_pseudo_cost && !too_small(box,i)
	  && ((*pseudo_costs)[i] > minimal_pseudo_cost)
	  ){
	max_pseudo_cost=(*pseudo_costs)[i];
	var=i;}
    }
    //    cout << "pseudo cost var " << var << endl;
    return var;
   }
 

  
pair<IntervalVector,IntervalVector> Bsc::bisect(const IntervalVector& box) {
	Cell cell(box);
	pair<Cell*,Cell*> p=bisect(cell);
	pair<IntervalVector,IntervalVector> boxes=make_pair(p.first->box,p.second->box);
	delete p.first;
	delete p.second;
	return boxes;
}


  
} // end namespace ibex
