// File		: graphviz_gnerator.h
// Author	: Felix Limanta
// Date		: March 31, 2017

#include "square_matrix.h"
#include <string>
#include <vector>

#ifndef GRAPHVIZ_GENERATOR_H
#define GRAPHVIZ_GENERATOR_H

class GraphVizGenerator {
	private:
		static const string DEF_FNAME;
		SquareMatrix matrix;
		bool** path_m;
		bool directed;
		string fname;
		double min_len;
		double max_len;
		double avg_len;
		int n_edge;

	public:
		GraphVizGenerator(const SquareMatrix& m,
							const vector<int>& path,
							string fname = DEF_FNAME,
							bool directed = true);
		~GraphVizGenerator();

		void generateDirectedGraph();
		void generateUndirectedGraph();
		void generatePNG();
		void generateSVG();
};

#endif