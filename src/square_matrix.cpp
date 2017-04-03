// File		: square_matrix.cpp
// Author	: Felix Limanta
// Date		: March 30, 2017

#include "square_matrix.h"
#include <iostream>
using namespace std;

const int SquareMatrix::DEF_SIZE = 20;

SquareMatrix::SquareMatrix(int size): size(size) {
	data = new double*[size];
	for(int i = 0; i < size; ++i) {
		data[i] = new double[size];
		for (int j = 0; j < size; ++j)
			data[i][j] = 0;
	}
}

SquareMatrix::SquareMatrix(const SquareMatrix& m): size(m.size) {
	data = new double*[size];
	for(int i = 0; i < size; ++i) {
		data[i] = new double[size];
		for (int j = 0; j < size; ++j)
			data[i][j] = m.data[i][j];
	}
}

SquareMatrix::~SquareMatrix() {
	for (int i = 0; i < size; ++i)
		delete [] data[i];
	delete [] data;
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& m) {
	if (this != &m) {
		// dtor
		for (int i = 0; i < size; ++i)
			delete [] data[i];
		delete [] data;
		
		// cctor
		size = m.size;
		data = new double*[size];
		for(int i = 0; i < size; ++i) {
			data[i] = new double[size];
			for (int j = 0; j < size; ++j)
				data[i][j] = m.data[i][j];
		}
	}
	return *this;
}

ostream& operator<<(ostream& os, const SquareMatrix& m) {
	for (int i = 0; i < m.size; ++i) {
		for (int j = 0; j < m.size; ++j) {
			os << m.data[i][j] << '\t';
		}
		os << '\n';
	}
	return os;
}

void SquareMatrix::setData(size_t i, size_t j, double data) {
	this->data[i][j] = data;
}

double** SquareMatrix::getData() const {
	return data;
}

double SquareMatrix::getData(size_t i, size_t j) const {
	return data[i][j];
}

int SquareMatrix::getSize() const {
	return size;
}