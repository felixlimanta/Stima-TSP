// File		: complete_tour_weight_node.h
// Author	: Felix Limanta
// Date		: April 1, 2017

#include "node.h"
#include <utility>

#ifndef COMPLETE_TOUR_WEIGHT_NODE_H
#define COMPLETE_TOUR_WEIGHT_NODE_H

class CompleteTourWeightNode: public Node {
	private:
		static pair<int,int>* minimum_edges;
		pair<int,int>* edges;
		
	public:
		CompleteTourWeightNode(int id, const SquareMatrix& m);
		CompleteTourWeightNode(int id, const SquareMatrix& m, CompleteTourWeightNode* parent);
		~CompleteTourWeightNode();
		
		static void findMinimumEdges(const SquareMatrix& m);
		void findEdgesForPath();
		void calculateCost();
		void expandNode();
};

#endif