//============================================================================
//                                  I B E X                                   
// File        : ibex_MinlpLargestFirst.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Dec 3, 2018
// Last Update : Jun 10, 2024
//============================================================================
#include "float.h"
#include "ibex_BitSet.h"
#include "ibex_MinlpLargestFirst.h"
#include "ibex_NoBisectableVariableException.h"

using namespace std;

namespace ibex {

  // to not bisect very big objectives 
  double objectivebisect_ratiolimit0=1.e10;

  MinlpLargestFirst::MinlpLargestFirst(System& sys, int goal_var,bool choose_obj, double prec, bool ps,  double ratio) : OptimLargestFirst(goal_var,choose_obj,prec, ratio), sys(sys)  {pseudocost=ps;
}

  MinlpLargestFirst::MinlpLargestFirst(System& sys,int goal_var, bool choose_obj,const Vector& prec, bool ps, double ratio) :OptimLargestFirst(goal_var,choose_obj,prec, ratio), sys(sys) {pseudocost=ps;
}
 
  int MinlpLargestFirst::find_largest_var(const Cell& cell, bool relaxvar, bool integervar, double& l){
    const  BitSet& b= *(sys.get_integer_variables());
    const IntervalVector& box=cell.box;
    int var=-1;

    for (int i=0; i< box.size(); i++){

      if (i!= goal_var &&
	  (!integervar || b[i]) &&
	  (!relaxvar ||
	   integer_relaxation_condition(cell,i) )
	  ){
	if ( ! nobisectable (box,i)){
	  if (var==-1) {
	    var=i;
	    l = uniform_prec()? box[i].diam() : (box[i].diam()/prec(i));
	  }
	  else {
	    double l_tmp = uniform_prec()? box[i].diam() : (box[i].diam()/prec(i));
	    if (l_tmp>l) {
	      var = i;
	      l = l_tmp;
	    }
	  }
	}
      }
    }
    return var;
  }
  
  BisectionPoint MinlpLargestFirst::choose_var(const Cell& cell) {
    double integer_epsilon=1.e-4;
    const IntervalVector& box=cell.box;
    const  BitSet& b= *(sys.get_integer_variables());
    int var =-1;
	//	cout << "pseudocost " << pseudocost << endl;
    if (pseudocost)
      var= pseudocost_int_var_to_bisect (cell,b);
	//	cout << " var " << var << " bisected var " << cell.bisected_var << endl;
    double l=0.0;
    if (var==-1)
      var= find_largest_var(cell,true,true,l);
    if (var==-1){
      l=0.0;
      var=find_largest_var(cell,false,true,l);
    }
    if (var!=-1)
      { return BisectionPoint(var,ratio,true);  // if an integer variable was found return it
    }
    /*  pseudocost does not improve solving for continuous variables
    if (var==-1 && pseudocost)
	var= pseudocost_var_to_bisect (cell);
    */
    if (var==-1)
      {l=0.0;
	var=find_largest_var(cell,false,false,l);
      }
    if ((choose_obj == true)
	&&  !(nobisectable (box,goal_var))
	&& (l < box[goal_var].diam())
	&& box[goal_var].diam()/l < objectivebisect_ratiolimit0)
      var=goal_var;
	//	cout << " bisected var " << var  << " l " << l << endl ;
    if (var !=-1){
      return BisectionPoint(var,ratio,true);
    }
    else {
      throw NoBisectableVariableException();
    }
  }
	   
} // end namespace ibex
