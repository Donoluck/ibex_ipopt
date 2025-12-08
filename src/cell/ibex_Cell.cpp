//============================================================================
//                                  I B E X                                   
// File        : ibex_Cell.cpp
// Author      : Gilles Chabert
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : May 10, 2012
// Last Update : Jun 07, 2018
//============================================================================

#include "ibex_Cell.h"
#include "ibex_Bsc.h"
#include <limits.h>
#include "ibex_Bxp.h"
#include "ibex_Bxp.h"

using namespace std;

namespace ibex {

  Cell::Cell(const IntervalVector& box, int var, unsigned int depth, int var_to_bisect) : box(box), prop(this->box), 
  bisected_var(var), 
  depth(depth), 
  var_to_bisect(var_to_bisect), 
  relax_sol(box.size()),
    ipopt_score(0.0),
    ipopt_recent_success(false),
    ipopt_success_count(0),
        ipopt_best_point(box.size()) {        // CORREGIDO: Constructor con tamaño
    // Inicializar ipopt_best_point a valores por defecto
    for (int i = 0; i < box.size(); i++) {
        ipopt_best_point[i] = 0.0;
    } 

}

  Cell::Cell(const Cell& e) : box(e.box), prop(this->box, e.prop), bisected_var(e.bisected_var), depth(e.depth), relax_sol(e.relax_sol),
    ipopt_score(e.ipopt_score),
    ipopt_recent_success(e.ipopt_recent_success),
    ipopt_success_count(e.ipopt_success_count),
    ipopt_best_point(e.ipopt_best_point)  {

}

pair<Cell*,Cell*> Cell::bisect(const BisectionPoint& pt) const {

	Cell* cleft;
	Cell* cright;

	if (pt.rel_pos) {
		pair<IntervalVector,IntervalVector> boxes=box.bisect(pt.var,pt.pos);
		cleft = new Cell(boxes.first, pt.var, depth+1);
		cright = new Cell(boxes.second, pt.var, depth+1);
	} else {
		IntervalVector b1(box);
		IntervalVector b2(box);
		b1[pt.var]=Interval(box[pt.var].lb(), pt.pos);
		b2[pt.var]=Interval(pt.pos, box[pt.var].ub());
		cleft = new Cell(b1, pt.var, depth+1);
		cright = new Cell(b2, pt.var, depth+1);
	}

	prop.update_bisect(Bisection(box, pt, cleft->box, cright->box), cleft->prop, cright->prop);

	return pair<Cell*,Cell*>(cleft,cright);
}

Cell::~Cell() {

}

std::ostream& operator<<(std::ostream& os, const Cell& c) {
	os << c.box;
	return os;
}

} // end namespace ibex
