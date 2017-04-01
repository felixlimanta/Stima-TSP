#include "reduced_cost_matrix_node.h"
#include <algorithm>

ReducedCostMatrixNode::ReducedCostMatrixNode(int id, const SquareMatrix& m): Node(id,m), subtracted_value(0) {
	reduceMatrix();
	calculateCost();
}

ReducedCostMatrixNode::ReducedCostMatrixNode(int id, const SquareMatrix& m, ReducedCostMatrixNode* parent): Node(id,m,parent), subtracted_value(0) {
	setRowsAndColumnsToInfinite();
	reduceMatrix();
	calculateCost();
}

void ReducedCostMatrixNode::setRowsAndColumnsToInfinite() {
	for (int i = 0; i < matrix.getSize(); ++i) {
		matrix.setData(parent->getID(), i, INF);
		matrix.setData(i, id, INF);
	}
	matrix.setData(id, 0, INF);
}

void ReducedCostMatrixNode::reduceMatrix() {
	// Subtract row
	for (int i = 0; i < matrix.getSize(); ++i) {
		// Find minimum		
		double min = INF;
		for (int j = 0; j < matrix.getSize(); ++j) {
			if (matrix[i][j] != INF && matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
		
		// Subtract row
		if (min != INF) {
			for (int j = 0; j < matrix.getSize(); ++j) {
				if (matrix[i][j] != INF) {
					matrix.setData(i, j, matrix[i][j] - min);
				}
			}
			subtracted_value += min;
		}		
	}
	
	// Subtract column
	for (int i = 0; i < matrix.getSize(); ++i) {
		// Find minimum		
		double min = INF;
		for (int j = 0; j < matrix.getSize(); ++j) {
			if (matrix[j][i] != INF && matrix[j][i] < min) {
				min = matrix[j][i];
			}
		}
		
		// Subtract column
		if (min != INF) {
			for (int j = 0; j < matrix.getSize(); ++j) {
				if (matrix[j][i] != INF) {
					matrix.setData(j, i, matrix[j][i] - min);
				}
			}
			subtracted_value += min;
		}		
	}
}

void ReducedCostMatrixNode::calculateCost() {
	cost = subtracted_value;
	if (parent != NULL) {
		cost += parent->getCost() + parent->getMatrix()[parent->getID()][id];
	}
}

void ReducedCostMatrixNode::expandNode() {
	for (int i = 0; i < matrix.getSize(); ++i) {
		if (visited[i]) {
			child[i] = NULL;
		} else {
			child[i] = new ReducedCostMatrixNode(i,matrix,this);
		}
	}
}