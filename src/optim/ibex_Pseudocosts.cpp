//                                  I B E X
// File        : ibex_Pseudocosts.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : May 18, 2024
// Last Update : May 18, 2024

/* code to manage pseudocosts representing the effect of a variable bisection wrt the lower bound of the objective : 
is used in Minlp bisection strategies with pseudocosts
code added in bisectors MinlpLargestFirst and SmearFunction
*/

#include "ibex_Optimizer.h"

using namespace std;

namespace ibex {

  void Optimizer::update_pseudocosts(const Cell& c, double ymin, double diam, int var,bool direction){
    double gain =c.box[goal_var].lb()-ymin;
    double pseudocost=gain/diam;
    if (direction)
      bisection_count_left[var]++;
    else
      bisection_count_right[var]++;
    
    // cout << "var " << var << " gain " << gain << " rel gain " << gain /fabs(ymin) << endl;
    if (gain < abs_eps_f || gain /fabs(ymin) <  rel_eps_f || pseudocost < 1.e-4){
      pseudocost=0;}
    if (direction){
       	  //	  cout << " var0 " << var << " gain " << gain << " diam " << diam << " pseudocost " << pseudocost << endl;
	  bisection_pseudocosts_left[var]=( pseudocost + ( bisection_count_left[var]-1) *bisection_pseudocosts_left[var] )/ bisection_count_left[var];
      }
      else{
	  //	  cout << " var1 " << var << " gain " << gain << " diam " << diam << " pseudocost " << pseudocost << endl;
	  bisection_pseudocosts_right[var]=( pseudocost + ( bisection_count_right[var]-1) *bisection_pseudocosts_right[var] )/ bisection_count_right[var];
      }
  }


  /* initilization of pseudo costs by computing the effects of all variables;
  does not seem to improve : this function is not called 
  */
  
  void Optimizer::init_pseudocosts(const Cell& c){
    double ymin=c.box[goal_var].lb();
    for (int i=0; i< c.box.size()-1; i++){
      Cell c1(c);
      //  cout << " box1 " << c1.box[i] << endl;
      double diam=c1.box[i].diam();
      //  cout << i << " diam " << diam << endl;
      c1.box[i]=Interval(c1.box[i].lb(), (c1.box[i].ub()+c1.box[i].lb())/2);
      contract(c1);
      if (!(c1.box.is_empty())) update_pseudocosts(c1,ymin,diam,i,true);
    }
    for (int i=0; i< c.box.size()-1; i++){
      Cell c1(c);
      //  cout << " box2 " << c1.box[i] << endl;
      double diam=c1.box[i].diam();
      c1.box[i]=Interval ((c1.box[i].ub()+c1.box[i].lb())/2,c1.box[i].ub());
      contract(c1);
      if (!(c1.box.is_empty())) update_pseudocosts(c1,ymin,diam,i,false);
    }
  }
      
   void Optimizer::pseudocosts_initialization(){
     for (int i=0 ; i< n+1;i++){
	  bisection_count_right.push_back(0);
	  bisection_pseudocosts_right.push_back(0);
	  bisection_count_left.push_back(0);
	  bisection_pseudocosts_left.push_back(0);
	  bisection_pseudocosts_score.push_back(0);
	}
  }

  /* Three variants for computing the pseudo-cost score :
see Achterberg thesis
1 the product of left and right pseudocosts with a threshold of 1.e-6
2 a weighted sum (1/6; 5/6) for max and min left and right pseudocosts
3 the average of left and right pseudocost
  */
  
  void Optimizer::update_pseudocosts_score(int var){
  	if (var  != -1){
	  double epsilon=1.e-6;
	  bisection_pseudocosts_score[var]=
	    std::max(epsilon,bisection_pseudocosts_left[var])*
	    std::max(epsilon,bisection_pseudocosts_right[var]);
	}
  }
 
 
  /*
  
void Optimizer::update_pseudocosts_score(int var){
  	if (var  != -1){
	  double mu=1.0/6.0;
	  bisection_pseudocosts_score[var]=
	    mu* std::max(bisection_pseudocosts_right[var],bisection_pseudocosts_left[var])  +
	    (1-mu)* std::min(bisection_pseudocosts_right[var],bisection_pseudocosts_left[var]) ;
	    }
}
  
  
  
void Optimizer::update_pseudocosts_score(int var){
       if (var  != -1 && bisection_count_right[var]+bisection_count_left[var] >0)
	 bisection_pseudocosts_score[var]=
	   (bisection_pseudocosts_right[var]*bisection_count_right[var]
	    +bisection_pseudocosts_left[var]*bisection_count_left[var])/
	   (bisection_count_right[var]+bisection_count_left[var]);
}
  */
}
