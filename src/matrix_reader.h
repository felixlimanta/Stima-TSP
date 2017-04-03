// File		: matrix_reader.h
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "square_matrix.h"
#include <string>
using namespace std;

#ifndef MATRIX_READER_H
#define MATRIX_READER_H

class MatrixReader {
	private:
		SquareMatrix* matrix;
	
	public:
		MatrixReader(const string& fname);
		~MatrixReader();
		
		SquareMatrix getMatrix() const;
};

#endif