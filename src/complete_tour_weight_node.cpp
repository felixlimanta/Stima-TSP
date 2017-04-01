#include "complete_tour_weight_node.h"
#include <iostream>

CompleteTourWeightNode::CompleteTourWeightNode(int id, const SquareMatrix& m): Node(id,m) {
	edges = new pair<int,int>[m.getSize()];
	findMinimumEdges();
	calculateCost();
}

CompleteTourWeightNode::CompleteTourWeightNode(int id, const SquareMatrix& m, CompleteTourWeightNode* parent): Node(id,m,parent) {
	edges = new pair<int,int>[m.getSize()];
	findMinimumEdges();
	calculateCost();
}

CompleteTourWeightNode::~CompleteTourWeightNode() {
	delete [] edges;
}

void CompleteTourWeightNode::findMinimumEdges() {
	pair<int,double> min1, min2;
	
	for (int i = 0; i < matrix.getSize(); ++i) {
		min1 = make_pair(0,INF);
		min2 = min1;		
		for (int j = 0; j < matrix.getSize(); ++j) {			
			if (matrix[i][j] <= min1.second) {
				min2 = min1;
				min1 = make_pair(j,matrix[i][j]);
			} else if (matrix[i][j] <= min2.second) {
				min2 = make_pair(j,matrix[i][j]);
			}
		}
		edges[i] = make_pair(min1.first, min2.first);
	}
	for (int i = 0; i < path.size() - 1; ++i) {
		if (edges[path[i]].first != path[i+1])
			edges[path[i]].second = path[i+1];
		if (edges[path[i+1]].first != path[i])
			edges[path[i+1]].second = path[i];
	}
}

void CompleteTourWeightNode::calculateCost() {
	cost = 0;
	for (int i = 0; i < matrix.getSize(); ++i) {
		cost += matrix[i][edges[i].first];
		cost += matrix[i][edges[i].second];
	}	
	cost /= 2;
}

void CompleteTourWeightNode::expandNode() {
	for (int i = 0; i < matrix.getSize(); ++i) {
		if (visited[i]) {
			child[i] = NULL;
		} else {
			child[i] = new CompleteTourWeightNode(i,matrix,this);
		}
	}
}