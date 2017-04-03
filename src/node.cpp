// File		: node.cpp
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "node.h"

Node::Node(int id, const SquareMatrix& m): id(id), parent(NULL), cost(0) {	
	matrix = m;
	child = new Node*[m.getSize()];
	
	path.push_back(id);
	visited = new bool[m.getSize()];
	for (int i = 0; i < m.getSize(); ++i) {
		visited[i] = false;
	}
	visited[id] = true;
}

Node::Node(int id, const SquareMatrix& m, Node* parent): id(id), parent(parent), cost(0) {
	matrix = m;
	child = new Node*[m.getSize()];
	
	path = parent->path;	
	path.push_back(id);
	visited = new bool[m.getSize()];
	for (int i = 0; i < m.getSize(); ++i) {
		visited[i] = parent->visited[i];
	}
	visited[id] = true;
}

Node::~Node() {
	for (int i = 0; i < path.size() - 1; ++i)
		delete child[i];
	delete [] child;
}

int Node::getID() const {
	return id;
}

Node* Node::getParent() const {
	return parent;
}

Node** Node::getChild() const {
	return child;
}

vector<int>& Node::getPath() {
	return path;
}

bool* Node::getVisited() const {
	return visited;
}

SquareMatrix& Node::getMatrix() {
	return matrix;
}

double Node::getCost() const {
	return cost;
}

bool Node::isSolution() {
	return (path.size() == matrix.getSize());
}
