#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

const double INF = numeric_limits<double>::infinity();

class SquareMatrix {
	private:
		static const int DEF_SIZE;
		double** data;
		int size;
		
	public:
		class SquareMatrixRow {
			private:
				double* row;
				
			public:
				SquareMatrixRow(double* row): row(row) { }
				
				double operator[](size_t index) const {
					return row[index];
				}
		};
		
		SquareMatrix(int size = DEF_SIZE);	
		SquareMatrix(const SquareMatrix& m);
		~SquareMatrix();
		
		SquareMatrix& operator=(const SquareMatrix& m);
		SquareMatrixRow operator[](size_t index) const {
			return SquareMatrixRow(data[index]);
		}
		friend ostream& operator<<(ostream& os, const SquareMatrix& m);
		
		void setData(size_t i, size_t j, double data);
		double** getData() const;
		double getData(size_t i, size_t j) const;
		int getSize() const;
};

#endif