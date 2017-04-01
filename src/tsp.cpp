#include "tsp.h"

TSP::TSP (int method, const SquareMatrix& m) {
	matrix = m;
	if (method == REDUCED_COST_MATRIX) {
		root = new ReducedCostMatrixNode(0, m);
	} else if (method == COMPLETE_TOUR_WEIGHT) {
		root = new CompleteTourWeightNode(0, m);
	}
	queue.push(make_pair(root->getCost(),root));
}

TSP::~TSP() {
	delete root;
}

vector<int>& TSP::getPath() {
	return final_path;
}

double TSP::getCost() {
	return final_cost;
}

void TSP::findPath() {
	Node* curr_node;
	do {
		curr_node = queue.top().second;
		queue.pop();
		
		while (!curr_node->isSolution()) {
			expandNode(*curr_node);
						
			curr_node = queue.top().second;
			queue.pop();
		}
	} while (matrix[curr_node->getID()][0] == INF);
	
	final_path = curr_node->getPath();
	final_cost = curr_node->getCost();
}

void TSP::expandNode(Node& n) {
	n.expandNode();
	
	Node** child = n.getChild();
	for (int i = 0; i < matrix.getSize(); ++i) {
		if (child[i] != NULL)
			queue.push(make_pair(i, child[i]));
	}
}

