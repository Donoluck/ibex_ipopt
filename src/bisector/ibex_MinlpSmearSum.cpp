//============================================================================
//                                  I B E X                                   
// File        : ibex_MinlpSmearSum.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Dec 3, 2018
// Last Update : Apr 3, 2024
//============================================================================
#include "float.h"
#include "ibex_BitSet.h"
#include "ibex_MinlpSmearSum.h"
#include "ibex_NoBisectableVariableException.h"

using namespace std;

namespace ibex {

 
  MinlpSmearSum::MinlpSmearSum(System& sys,  double prec,   LargestFirst& lf, bool gb, bool ps) : SmearFunction(sys,prec, lf,gb,ps)  {

}
  MinlpSmearSum::MinlpSmearSum(System& sys,  const Vector & prec,   LargestFirst& lf, bool gb,bool ps) : SmearFunction(sys,prec, lf,gb,ps)  {

    }


  
  int MinlpSmearSum::var_to_bisect(IntervalMatrix& J, const Cell& cell) const {
    const  IntervalVector& box=cell.box;
    double max_magn = NEG_INFINITY;
    double integer_epsilon=1.e-4;
    int var = -1;
    BitSet& b= *(sys.get_integer_variables());
   
    for (int j=0; j<nbvars; j++) {
      
      if ((!too_small(box,j))&&  (j!= goal_var() && b[j] &&
				  (cell.relax_sol[cell.box.size()-1] == DBL_MAX ||
				   ( cell.relax_sol[j] - std::floor(cell.relax_sol[j]) > integer_epsilon
				     &&
				     std::ceil (cell.relax_sol[j]) - cell.relax_sol[j] > integer_epsilon)
				   )

				  )) {

	double sum_smear=0;
	for (int i=0; i<sys.f_ctrs.image_dim(); i++) {
	  if (constraint_to_consider (i, box))
	    sum_smear+= J[i][j].mag() *box[j].diam();
	}
	if (sum_smear > max_magn) {
	  max_magn = sum_smear;
	  var = j;
	}
      }
    }
    if (var==-1)
      {
	max_magn = NEG_INFINITY;
	for (int j=0; j<nbvars; j++) {
	  if (b[j] &&(!too_small(box,j))&& (goal_to_bisect || j!= goal_var())) { // && (box[j].mag() <1 ||  box[j].diam()/ box[j].mag() >= prec(j))) {
	    double sum_smear=0;
	    for (int i=0; i<sys.f_ctrs.image_dim(); i++) {
	      if (constraint_to_consider (i, box))
		sum_smear+= J[i][j].mag() *box[j].diam();
	    }
	    if (sum_smear > max_magn) {
	      max_magn = sum_smear;
	      var = j;
	    }
	  }
	}
	  
      }

    
    // cout << " integer var " << var << endl;
    if (var==-1)  // no integer variable was chosen
      {
	max_magn = NEG_INFINITY;
	for (int j=0; j<nbvars; j++) {
	  if ((!too_small(box,j))&& (goal_to_bisect || j!= goal_var())) { // && (box[j].mag() <1 ||  box[j].diam()/ box[j].mag() >= prec(j))) {
	    double sum_smear=0;
	    for (int i=0; i<sys.f_ctrs.image_dim(); i++) {
	      if (constraint_to_consider (i, box))
		sum_smear+= J[i][j].mag() *box[j].diam();
	    }
	    if (sum_smear > max_magn) {
	      max_magn = sum_smear;
	      var = j;
	    }
	  }
	}
	  
      }

    // cout << " var " << var << endl;
    return var;
   }




 
} // end namespace ibex
