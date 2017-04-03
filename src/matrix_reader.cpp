// File		: matrix_reader.cpp
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "matrix_reader.h"
#include <fstream>
#include <sstream>

MatrixReader::MatrixReader(const string& fname) {
	ifstream inf;
	inf.open(fname, ios::in);
	string instr;
	
	// Read number of nodes
	int size;
	getline(inf, instr);	
	istringstream(instr) >> size;
	
	// Read matrix
	matrix = new SquareMatrix(size);
	for (int i = 0; i < size; ++i) {		
		getline(inf, instr);
		istringstream row_in(instr);
		for (int j = 0; j < size; ++j) {
			double n;
			row_in >> n;
			if (i == j || n <= 0)
				n = INF;
			matrix->setData(i, j, n);
		}		
	}
	
	inf.close();
}

MatrixReader::~MatrixReader() {
	delete matrix;
}

SquareMatrix MatrixReader::getMatrix() const {
	return *matrix;
}