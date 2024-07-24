//============================================================================
//                                  I B E X                                   
// File        : SmearFunction generic bisector variant for MINLP optimization (abstract class)
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Jul 24, 2024
// Last Update : Jul 24, 2024
//============================================================================

#ifndef __IBEX_MINLP_FUNCTION_H__
#define __IBEX_MINLP_FUNCTION_H__

#include "ibex_Bsc.h"
#include "ibex_SmearFunction.h"
#include "ibex_System.h"
#include "ibex_LargestFirst.h"
#include "ibex_BisectionPoint.h"

namespace ibex {

/**
 * \ingroup bisector
 *
 * \brief smear sum bisector for minlp
 *
 */
class MinlpSmearFunction : public SmearFunction {
public:

	/**
	 * \brief Create a bisector with a smear heuristic for minlp ( called by MinlpSmearSum and MinlpSmearSumRelative constructors 
	 *
	 */
  MinlpSmearFunction(System& sys,  double prec,   LargestFirst& lf, bool gb=true, bool pseudocost=false);

	/**
	 * \brief Create a bisector with SmearFunction heuristic (choosing first among the integer variables, 
         * with the maximum pseudocost is pseudocosts are used and then with a smear function heuristic.
         * If no integer variable could be chosen, choose with this heuristic among the real variables) see ibex_SmearFunction.h for explanation
         * of this heuristic.
	 *
         * \param sys              - the system
	 * \param prec             - see #Bsc::Bsc(double).
	 * \param lf : a largest first bisector to be used when the Smear based heuristic could not choose any variable   * \param gb : boolean indicating if the goal variable can be bisected : default true.
         * TODO . reintroduce param ratio . It is now set to its default value 0.45

	 */

  MinlpSmearFunction(System& sys,  const Vector & prec,   LargestFirst& lf, bool gb=true, bool pseudocost=false);

  virtual int var_to_bisect(IntervalMatrix& J, const Cell& cell) const=0;

  

  BisectionPoint choose_var(const Cell& cell);

  

	  
};

}// end namespace ibex

#endif // __IBEX_MINLP_SMEARFUNCTION_H__
