//============================================================================
//                                  I B E X                                   
// File        : ibex_MinlpLargestFirst.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Dec 3, 2018
// Last Update : Oct 17, 2019
//============================================================================
#include "float.h"
#include "ibex_BitSet.h"
#include "ibex_MinlpLargestFirst.h"
#include "ibex_NoBisectableVariableException.h"

using namespace std;

namespace ibex {

  // to not bisect very big objectives 
  double objectivebisect_ratiolimit0=1.e10;

  MinlpLargestFirst::MinlpLargestFirst(System& sys, int goal_var,bool choose_obj, double prec, bool ps,  double ratio) : OptimLargestFirst(goal_var,choose_obj,prec, ratio), pseudocost(ps), sys(sys)  {
}

  MinlpLargestFirst::MinlpLargestFirst(System& sys,int goal_var, bool choose_obj,const Vector& prec, bool ps, double ratio) :OptimLargestFirst(goal_var,choose_obj,prec, ratio), pseudocost(ps), sys(sys) {

}
  /*
 int MinlpLargestFirst::pseudocost_int_var_to_bisect  (const Cell & c) const{
    int var=-1;
    const IntervalVector& box=c.box;
    double max_pseudo_cost=0;
    BitSet& b= *(sys.get_integer_variables());
    
    for (int i =0; i< box.size()-1; i++){
      if (b[i] && (*pseudo_costs)[i] > max_pseudo_cost && !too_small(box,i)){
	  max_pseudo_cost=(*pseudo_costs)[i];
	  var=i;}
    }
    if (var==c.bisected_var) var=-1;
    return var;
   }
  */
 int MinlpLargestFirst::pseudocost_int_var_to_bisect  (const Cell & c) const{
    int var=-1;
    const IntervalVector& box=c.box;
    double max_pseudo_cost=0.0;
    double integer_epsilon=1.e-4;
    BitSet& b= *(sys.get_integer_variables());
    for (int i =0; i< box.size()-1; i++){
      if (b[i]
	  
	  	  && (c.relax_sol[c.box.size()-1] == DBL_MAX ||
		      ( c.relax_sol[i] - std::floor(c.relax_sol[i]) > integer_epsilon
	    &&
			std::ceil (c.relax_sol[i]) - c.relax_sol[i] > integer_epsilon)
		   )
	  
	  &&
	  
	  (*pseudo_costs)[i] > max_pseudo_cost && !too_small(box,i)){
	  max_pseudo_cost=(*pseudo_costs)[i];
	  var=i;}
    }
    if (var==c.bisected_var) var=-1;
    //    cout << "pseudo cost var " << var << endl;
    return var;
   }
  

  
BisectionPoint MinlpLargestFirst::choose_var(const Cell& cell) {
  double integer_epsilon=1.e-4;
        const IntervalVector& box=cell.box;
	int var =-1;
	//	cout << "pseudocost " << pseudocost << endl;
	if (pseudocost)
	  var= pseudocost_int_var_to_bisect (cell);
	//	cout << " var " << var << " bisected var " << cell.bisected_var << endl;
	BitSet& b= *(sys.get_integer_variables());
	double l=0.0;
	
	if (var==-1){
	


	//	cout << " b" << b << endl ;
	  for (int i=0; i< box.size(); i++){

	  if (i!= goal_var && b[i] &&
	      (cell.relax_sol[cell.box.size()-1] == DBL_MAX ||
		      ( cell.relax_sol[i] - std::floor(cell.relax_sol[i]) > integer_epsilon
	    &&
			std::ceil (cell.relax_sol[i]) - cell.relax_sol[i] > integer_epsilon)
	       )
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
	}
	//	cout << " bisected var " << var  << " l " << l << endl ;
	
	if (var !=-1){
	  return BisectionPoint(var,ratio,true);
	}
	else{
	  l=0.0;
	  for (int i=0; i< box.size(); i++){

	    //	  if (i!= goal_var && !b[i]){
	    if (i!= goal_var && b[i]){
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
	}
	if (var==-1){
	  l=0.0;
	  for (int i=0; i< box.size(); i++){

	    if (i!= goal_var){
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
