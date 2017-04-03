// File		: node.h
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "square_matrix.h"
#include <vector>

#ifndef NODE_H
#define NODE_H

class Node {
	protected:
		int id;
		Node* parent;
		Node** child;
		vector<int> path;
		bool* visited;
		SquareMatrix matrix;
		double cost;
		
	public:
		Node(int id, const SquareMatrix& m);
		Node(int id, const SquareMatrix& m, Node* parent);
		virtual ~Node();
		
		int getID() const;
		Node* getParent() const;
		Node** getChild() const;
		vector<int>& getPath();
		bool* getVisited() const;
		SquareMatrix& getMatrix();
		double getCost() const;		
		
		virtual void calculateCost() = 0;
		virtual void expandNode() = 0;
		bool isSolution();
};

#endif