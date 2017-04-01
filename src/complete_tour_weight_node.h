#include "node.h"
#include <utility>

#ifndef COMPLETE_TOUR_WEIGHT_NODE_H
#define COMPLETE_TOUR_WEIGHT_NODE_H

class CompleteTourWeightNode: public Node {
	private:
		pair<int,int>* edges;
		bool** path_m;
		
	public:
		CompleteTourWeightNode(int id, const SquareMatrix& m);
		CompleteTourWeightNode(int id, const SquareMatrix& m, CompleteTourWeightNode* parent);
		~CompleteTourWeightNode();
		
		void findMinimumEdges();
		void calculateCost();
		void expandNode();
};

#endif