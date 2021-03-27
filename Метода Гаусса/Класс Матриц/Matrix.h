#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
	double** matrix;
	int string, columns;
public:
	Matrix(int _string = 3, int _columns = 3);
	Matrix(const Matrix&);
	Matrix(double** massive, int _string, int _columns);
	~Matrix();
	int getstr() const;
	int getcol() const;
	double getval(int pstr, int pcol);
	void setval(int pstr, int pcol, double val);
	Matrix operator+ (const Matrix& m)const;
	Matrix operator* (const Matrix& m)const;
	Matrix operator- (const Matrix& m)const;
	Matrix& operator= (const Matrix& m);
	//печать и ввод матрицы
};

#endif // MATRIX_H_