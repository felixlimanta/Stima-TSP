#include "graphviz_generator.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>

const string GraphVizGenerator::DEF_FNAME = "graph";

GraphVizGenerator::GraphVizGenerator(const SquareMatrix& m, const vector<int>& path, string fname, bool directed): directed(directed), fname(fname) {
	matrix = m;
	path_m = new bool*[m.getSize()];
	for (int i = 0; i < m.getSize(); ++i) {
		path_m[i] = new bool[m.getSize()];
		for (int j = 0; j < m.getSize(); ++j) {
			path_m[i][j] = false;
		}
	}
	
	for (int i = 0; i < path.size() - 1; ++i) {
		path_m[path[i]][path[i + 1]] = true;
	}
	path_m[path.back()][0] = true;
	
	min_len = INF;
	max_len = 0;
	avg_len = 0;
	n_edge = 0;
	for (int i = 0; i < m.getSize(); ++i) {
		for (int j = 0; j < m.getSize(); ++j) {
			if (matrix[i][j] < min_len)
				min_len = matrix[i][j];
			if (matrix[i][j] > max_len)
				max_len = matrix[i][j];
			if (matrix[i][j] != INF) {
				avg_len += matrix[i][j];
				n_edge++;
			}
		}
	}
	avg_len /= n_edge;
}

GraphVizGenerator::~GraphVizGenerator() {
	for (int i = 0; i < matrix.getSize(); ++i)
		delete [] path_m[i];
	delete [] path_m;
}

void GraphVizGenerator::generateDirectedGraph() {
	ofstream outf;
	outf.open(fname + ".gv", ios::out);
		
	outf << "digraph {\n";	
	outf << "\tgraph [layout=circo, overlap=scale, splines=true, mindist=2.5];\n";
	outf << "\tnode [shape=circle];\n";	
	outf << "\t0 [peripheries=2];";
	for (int i = 0; i < matrix.getSize(); ++i) {
		for (int j = 0; j < matrix.getSize(); ++j) {
			if (matrix[i][j] != INF) {
				outf << '\t' << i << " -> " << j << " [len=" << matrix[i][j]/avg_len * pow(matrix.getSize(),1.5) << ", label=\"" << matrix[i][j];
				if (path_m[i][j]) {
					outf << "\", color=red, penwidth=3.0];\n";
				} else {
					outf << "\"];\n";
				}
			}
		}
	}
	
	outf << "}";
	outf.close();
}

void GraphVizGenerator::generateUndirectedGraph() {
	ofstream outf;
	outf.open(fname + ".gv", ios::out);
	
	outf << "graph {\n";	
	outf << "\tgraph [layout=circo, overlap=scale, splines=true, mindist=2.5];\n";
	outf << "\tnode [shape=circle];\n";	
	outf << "\t0 [peripheries=2];";
	for (int i = 0; i < matrix.getSize(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (matrix[i][j] != INF) {
				outf << '\t' << i << " -- " << j << " [len=" << matrix[i][j]/avg_len * pow(matrix.getSize(),1.5) << ", label=\"" << matrix[i][j];
				if (path_m[i][j] || path_m[j][i]) {
					outf << "\", color=red, penwidth=3.0];\n";
				} else {
					outf << "\"];\n";
				}
			}
		}
	}
	
	outf << "}";
	outf.close();
}

void GraphVizGenerator::generatePNG() {
	ostringstream command;
	command << "neato -Tpng " << fname << ".gv -o " << fname << ".png";	
	system(command.str().c_str());
}

void GraphVizGenerator::generateSVG() {
	ostringstream command;
	command << "neato -Tsvg " << fname << ".gv -o " << fname << ".svg";	
	system(command.str().c_str());
}