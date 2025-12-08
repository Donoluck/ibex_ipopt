//============================================================================
//                                  I B E X                                   
// File        : ibex_CellBeamSearch.cpp
// Author      : Bertrand Neveu
// Copyright   : IMT Atlantique (France)
// License     : See the LICENSE file
// Created     : Aug 29, 2017
// Modified    : Sep 07, 2017
//============================================================================

#include "ibex_CellBeamSearch.h"

using namespace std;

namespace ibex {

CellBeamSearch::CellBeamSearch(CellHeap& currentbuffer, CellHeap& futurebuffer, const ExtendedSystem & sys, unsigned int beamsize) : CellHeap (sys), beamsize(beamsize), currentbuffer(currentbuffer), futurebuffer (futurebuffer) {

}

CellBeamSearch::~CellBeamSearch() {

}

bool CellBeamSearch::empty() const {
	return (currentbuffer.empty()  && futurebuffer.empty() && CellHeap::empty());
}

unsigned int  CellBeamSearch::size() const {
	return (currentbuffer.size()+ futurebuffer.size() + CellHeap::size());
}

void CellBeamSearch::flush() {
	currentbuffer.flush();
	futurebuffer.flush();
	CellHeap::flush();
}

void CellBeamSearch::contract(double new_loup) {

	if (!(CellHeap::empty()))	Heap<Cell>::contract(new_loup);

	if (!(currentbuffer.empty()))
		currentbuffer.contract(new_loup);

	if (!(futurebuffer.empty())) {
		futurebuffer.contract(new_loup);

	}
}

void CellBeamSearch::push(Cell* cell) {
	futurebuffer.push(cell);
}

// En ibex_CellBeamSearch.cpp, modificar cell_cost:
double CellBeamSearch::cell_cost(const Cell& cell) const {
    // Costo original: lower bound del objetivo
    double original_cost = cell.box[sys.goal_var()].lb();
    
    // DEBUG: Mostrar información de la celda
    static int cell_count = 0;
    if (cell_count++ % 100 == 0) {  // Cada 100 celdas
        std::cout << "DEBUG Cell #" << cell_count 
                  << " ipopt_score=" << cell.ipopt_score
                  << " recent_success=" << cell.ipopt_recent_success
                  << " count=" << cell.ipopt_success_count
                  << " original_cost=" << original_cost << std::endl;
    }
    
    // BONUS POR SCORE DE IPOPT
    double ipopt_bonus = 0.0;
    const double IPOPT_WEIGHT = 100.0;
    
    if (cell.ipopt_score > 0) {
        double depth_factor = 1.0 / (1.0 + cell.depth * 0.05);
        ipopt_bonus = cell.ipopt_score * IPOPT_WEIGHT * depth_factor;
        
        if (cell.ipopt_recent_success) {
            ipopt_bonus *= 1.2;
        }
        
        // DEBUG para celdas con bonus
        if (ipopt_bonus > 0.1) {
            std::cout << "DEBUG IPOPT BONUS: cell has ipopt_score=" << cell.ipopt_score
                      << " bonus=" << ipopt_bonus
                      << " adjusted_cost=" << (original_cost - ipopt_bonus) << std::endl;
        }
    }
    
    double depth_bias = cell.depth * 1e-12;
    return original_cost - ipopt_bonus + depth_bias;
}
// returns the cell to handled
Cell* CellBeamSearch::pop() {
	if (! (currentbuffer.empty()) )
		return currentbuffer.pop();
	else if (! (futurebuffer.empty()) ) {
		Cell * c= futurebuffer.pop();
		move_buffers();
		return c;
	}
	else return CellHeap::pop();
}

// emptying the futurebuffer : buffersize-1 cells are put into
// the currentbuffer , the remaining into the global heap
void CellBeamSearch::move_buffers() {
	while (! (futurebuffer.empty())) {
		if (currentbuffer.size() < beamsize-1)
			currentbuffer.push(futurebuffer.pop());
		else
			CellHeap::push(futurebuffer.pop());
	}
}

Cell* CellBeamSearch::top() const {
	if (! (currentbuffer.empty()) ) {
		return currentbuffer.top();
	}
	else
		if (! (futurebuffer.empty()) ) {
			return futurebuffer.top();
		}
		else {
			return CellHeap::top();
		}
}

// the minimum of all open nodes
double CellBeamSearch::minimum() const {
	assert (!(empty()));
	if  (! (currentbuffer.empty()) && !(futurebuffer.empty()) &&  (!CellHeap::empty())){
		//      cout << "minimum " << currentbuffer.minimum() << "  " << futurebuffer.minimum() <<  " " << CellHeap::minimum() << endl;
		return std::min (currentbuffer.minimum(), std::min( futurebuffer.minimum(),  CellHeap::minimum()));
	}
	else if (! (currentbuffer.empty()) && !CellHeap::empty())
		return std::min(currentbuffer.minimum(), CellHeap::minimum());
	else if (! (futurebuffer.empty()) && !CellHeap::empty())
		return std::min(futurebuffer.minimum(), CellHeap::minimum());
	else if  (! (futurebuffer.empty()) && !currentbuffer.empty())
		return std::min(futurebuffer.minimum(), currentbuffer.minimum());
	else if  (! (futurebuffer.empty()))
		return futurebuffer.minimum();
	else if  (!(currentbuffer.empty()))
		return currentbuffer.minimum();
	else
		return CellHeap::minimum();
}

} // end namespace
