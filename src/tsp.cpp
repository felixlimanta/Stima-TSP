#include "tsp.h"

TSP::TSP (int method, const SquareMatrix& m) {
	matrix = m;
	if (method == REDUCED_COST_MATRIX) {
		root = new ReducedCostMatrixNode(0, m);
	} else if (method == COMPLETE_TOUR_WEIGHT) {
		root = new CompleteTourWeightNode(0, m);
	}
	leaves.push_back(Leaf(root->getCost(),root));	
	make_heap(leaves.begin(),leaves.end(),LeafComparator());
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
		curr_node = leaves.front().node_addr;
		pop_heap(leaves.begin(),leaves.end(),LeafComparator());
		leaves.pop_back();
				
		
		while (!curr_node->isSolution()) {
			expandNode(*curr_node);
						
			curr_node = leaves.front().node_addr;
			pop_heap(leaves.begin(),leaves.end(),LeafComparator());
			leaves.pop_back();
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
			leaves.push_back(Leaf(child[i]->getCost(), child[i]));
			push_heap(leaves.begin(),leaves.end(),LeafComparator());
	}	
}

