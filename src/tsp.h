// File		: tsp.cpp
// Author	: Felix Limanta
// Date		: March 31, 2017

#include "square_matrix.h"
#include "node.h"
#include "complete_tour_weight_node.h"
#include "reduced_cost_matrix_node.h"
#include <algorithm>
using namespace std;

#ifndef TSP_H
#define TSP_H

#define REDUCED_COST_MATRIX	0
#define COMPLETE_TOUR_WEIGHT 1

struct Leaf {
	double cost;
	Node* node_addr;
	
	Leaf(double cost, Node* node_addr): cost(cost), node_addr(node_addr) {};
};

struct LeafComparator {
	bool operator()(const Leaf& lhs, const Leaf& rhs) {
		return lhs.cost > rhs.cost;
	}
};

class TSP {
	private:
		SquareMatrix matrix;
		Node* root;
		vector<Leaf> leaves;
		vector<int> final_path;
		double final_cost;
		int no_of_generated_nodes;
		
	public:
		TSP(int method, const SquareMatrix& m);
		~TSP();
		
		vector<int>& getPath();	
		double getCost();
		int getNumberOfNodes();
		
		void findPath();
		void expandNode(Node& n);
};

#endif