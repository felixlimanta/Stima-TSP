// File		: reduced_cost_matrix.h
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "node.h"

#ifndef REDUCED_COST_MATRIX_NODE_H
#define REDUCED_COST_MATRIX_NODE_H

class ReducedCostMatrixNode: public Node {
	private:
		int subtracted_value;
		
	public:
		ReducedCostMatrixNode(int id, const SquareMatrix& m);
		ReducedCostMatrixNode(int id, const SquareMatrix& m, ReducedCostMatrixNode* parent);
		
		void setRowsAndColumnsToInfinite();
		void reduceMatrix();
		void calculateCost();
		void expandNode();
};

#endif