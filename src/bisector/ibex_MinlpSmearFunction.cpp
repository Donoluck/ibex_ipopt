//============================================================================
//                                  I B E X                                   
// File        : ibex_MinlpSmearFunction.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Jul 24, 2024
// Last Update : Jul 24, 2024
//============================================================================
#include "float.h"
#include "ibex_BitSet.h"
#include "ibex_MinlpSmearFunction.h"


using namespace std;

namespace ibex {

 
  MinlpSmearFunction::MinlpSmearFunction(System& sys,  double prec,   LargestFirst& lf, bool gb, bool ps) : SmearFunction(sys,prec, lf,gb,ps)  {

}
  MinlpSmearFunction::MinlpSmearFunction(System& sys,  const Vector & prec,   LargestFirst& lf, bool gb,bool ps) : SmearFunction(sys,prec, lf,gb,ps)  {

  }

  BisectionPoint MinlpSmearFunction::choose_var(const Cell& cell) {
    int var=-1;
    const IntervalVector& box=cell.box;
    const  BitSet& b= *(sys.get_integer_variables());
    if (pseudocost)
      var= pseudocost_int_var_to_bisect (cell,b );
    /*  pseudocosts do not improve for continuous variables
    if (pseudocost && var==-1)
      var=pseudocost_var_to_bisect(cell);
    */
    if (var==-1)
      return SmearFunction::choose_var(cell);
    else   
      return BisectionPoint(var,lf->ratio,true);
  }
  
  

 
} // end namespace ibex
