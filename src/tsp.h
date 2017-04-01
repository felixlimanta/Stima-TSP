#include "square_matrix.h"
#include "node.h"
#include "complete_tour_weight_node.h"
#include "reduced_cost_matrix_node.h"
#include <queue>
using namespace std;

#ifndef TSP_H
#define TSP_H

#define REDUCED_COST_MATRIX	0
#define COMPLETE_TOUR_WEIGHT 1

typedef pair<double,Node*> QueueElmt;

class QueueElmtComparator {
	public:
		bool operator()(QueueElmt n1, QueueElmt n2) {
			return n1.first < n2.first;
		}
};

class TSP {
	private:
		SquareMatrix matrix;
		Node* root;
		priority_queue<QueueElmt, vector<QueueElmt>, QueueElmtComparator> queue;
		vector<int> final_path;
		double final_cost;
		
	public:
		TSP(int method, const SquareMatrix& m);
		~TSP();
		
		vector<int>& getPath();	
		double getCost();
		
		void findPath();
		void expandNode(Node& n);
};

#endif