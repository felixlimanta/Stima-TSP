// File		: complete_tour_weight_node.cpp
// Author	: Felix Limanta
// Date		: April 1, 2017

#include "complete_tour_weight_node.h"
#include <iostream>

pair<int,int>* CompleteTourWeightNode::minimum_edges;

CompleteTourWeightNode::CompleteTourWeightNode(int id, const SquareMatrix& m): Node(id,m) {
	edges = new pair<int,int>[m.getSize()];
	findEdgesForPath();
	calculateCost();
}

CompleteTourWeightNode::CompleteTourWeightNode(int id, const SquareMatrix& m, CompleteTourWeightNode* parent): Node(id,m,parent) {
	edges = new pair<int,int>[m.getSize()];
	findEdgesForPath();
	calculateCost();
}

CompleteTourWeightNode::~CompleteTourWeightNode() {
	delete [] edges;
}

void CompleteTourWeightNode::findMinimumEdges(const SquareMatrix& m) {
	minimum_edges = new pair<int,int>[m.getSize()];
	pair<int,double> min1, min2;
	
	for (int i = 0; i < m.getSize(); ++i) {
		min1 = make_pair(0,INF);
		min2 = min1;		
		for (int j = 0; j < m.getSize(); ++j) {			
			if (m[i][j] <= min1.second) {
				min2 = min1;
				min1 = make_pair(j,m[i][j]);
			} else if (m[i][j] <= min2.second) {
				min2 = make_pair(j,m[i][j]);
			}
		}
		minimum_edges[i] = make_pair(min1.first, min2.first);
	}
}

void CompleteTourWeightNode::findEdgesForPath() {
	for (int i = 0; i < matrix.getSize(); ++i) {
		edges[i] = minimum_edges[i];
	}
	if (path.size() > 1) {
		if (edges[path[0]].first != path[1])
			edges[path[0]].second = path[1];
		for (int i = 1; i < path.size() - 1; ++i) {
			edges[path[i]].first = path[i-1];
			edges[path[i]].second = path[i+1];
		}
		if (edges[path.back()].first != path.end()[-2])
			edges[path.back()].second = path.end()[-2];
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