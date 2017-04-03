// File		: main.cpp
// Author	: Felix Limanta
// Date		: April 2, 2017

#include "graphviz_generator.h"
#include "matrix_reader.h"
#include "square_matrix.h"
#include "tsp.h"
#include <chrono>
#include <iostream>
using namespace std;

int main (int argc, char** argv) {
	// Input
	string fname;
	int method = REDUCED_COST_MATRIX;
	if (argc <= 1) {
		cout << "Filename:\t";
		cin >> fname;
	} else {
		fname = argv[1];
	}
	if (argc <= 2) {
		cout << "0. Reduced cost matrix\n"
			<< "1. Complete tour weight\n"
			<< "Method:\t";
		cin >> method;
	} else {
		method = stoi(argv[2]);
	}
	
	SquareMatrix matrix = MatrixReader(fname).getMatrix();
	cout << "Matrix: \n" << matrix << '\n';
	
	// Start execution time measurement
	auto start = chrono::system_clock::now();
	
	// Process
	TSP* tsp;
	if (method == COMPLETE_TOUR_WEIGHT) {
		tsp = new TSP(COMPLETE_TOUR_WEIGHT, matrix);
	} else {
		tsp = new TSP(REDUCED_COST_MATRIX, matrix);
	}
	tsp->findPath();
	vector<int> path = tsp->getPath();
	double cost = tsp->getCost();
	int nb_nodes = tsp->getNumberOfNodes();
	
	// Measure execution time
	auto end = chrono::system_clock::now();
	auto elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
	
	// Output results to terminal
	cout << "Path:" << '\t';
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << " -> ";
	cout << "0\n";
	cout << "Cost: " << cost << '\n';
	cout << "Number of generated nodes: " << nb_nodes << '\n';
	cout << "Elapsed time: " << elapsed.count() << " us\n";
	
	// Generate graph	
	GraphVizGenerator* gv;
	if (method == COMPLETE_TOUR_WEIGHT) {
		gv = new GraphVizGenerator(matrix,path,fname,false);
		gv->generateUndirectedGraph();
	} else {
		gv = new GraphVizGenerator(matrix,path,fname,true);
		gv->generateDirectedGraph();
	}
	gv->generatePNG();
	gv->generateSVG();
	
	// Terminate
	delete tsp;
	delete gv;
	return 0;
}