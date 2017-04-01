#include "matrix_reader.h"
#include "square_matrix.h"
#include "tsp.h"
#include "graphviz_generator.h"

#include <iostream>
using namespace std;

int main () {	
	SquareMatrix matrix = MatrixReader("matrix.txt").getMatrix();	
	cout << "\nMatrix: \n" << matrix;
	
	/*TSP test = TSP(REDUCED_COST_MATRIX, matrix);
	test.findPath();
	vector<int> path = test.getPath();
	double cost = test.getCost();
	
	cout << "\nPath:" << '\t';
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << " -> ";
	cout << "0\n";
	cout << "Cost: " << cost << '\n';

	GraphVizGenerator gv(matrix,path,"graph",true);
	gv.generateDirectedGraph();
	gv.generatePNG();
	gv.generateSVG();*/
	
	TSP test = TSP(COMPLETE_TOUR_WEIGHT, matrix);
	test.findPath();
	vector<int> path = test.getPath();
	double cost = test.getCost();
	
	cout << "\nPath:" << '\t';
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << " -> ";
	cout << "0\n";
	cout << "Cost: " << (int) cost << '\n';
	
	GraphVizGenerator gv(matrix,path,"graph",false);
	gv.generateUndirectedGraph();
	gv.generatePNG();
	gv.generateSVG();
}