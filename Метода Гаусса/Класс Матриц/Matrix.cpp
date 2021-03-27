#include "Matrix.h"

Matrix::Matrix(int _string, int _columns) : string(_string), columns(_columns) {
	matrix = new double* [string];
	for (int i = 0; i < string; i++)
	{
		matrix[i] = new double[columns];
	}
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = i * _columns + j; //0.0;
		}
	}

};

Matrix::Matrix(const Matrix& m) : string(m.string), columns(m.columns) {
	matrix = new double* [string];
	for (int i = 0; i < string; i++)
	{
		matrix[i] = new double[columns];
	}
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
};


Matrix::Matrix(double** massive, int _string, int _columns) : string(_string), columns(_columns) {
	matrix = new double* [string];
	for (int i = 0; i < string; i++)
	{
		matrix[i] = new double[columns];
	}
	for (int i = 0; i < string; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix[i][j] = massive[i][j];
		}
	}

}


Matrix :: ~Matrix() {

	for (int i = 0; i < string; i++)
	{
		delete[] matrix[i];
	}
	delete []matrix;

}

int Matrix::getstr() const {
	return string;
}

int Matrix::getcol() const {
	return columns;
};


double Matrix::getval(int pstr, int pcol) {
	return matrix[pstr][pcol];
};

void Matrix::setval(int pstr, int pcol, double val) {
	matrix[pstr][pcol] = val;
};

Matrix Matrix :: operator+(const Matrix& m) const {
	if (string == m.string && columns == m.columns)
	{
		Matrix step(string, columns);
		for (int i = 0; i < string; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				step.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
			}
		}
		return step;
	}

};

Matrix Matrix :: operator-(const Matrix& m) const{
	if (string == m.string && columns == m.columns)
	{
		Matrix step(string, columns);
		for (int i = 0; i < string; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				step.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
			}
		}
		return step;
	}

};

Matrix Matrix :: operator*(const Matrix& m) const{
	if (columns == m.string)
	{
		Matrix step(string, m.columns);
		for (int i = 0; i < string; i++)
		{
			for (int j = 0; j < m.columns; j++)
			{
				for (int k = 0; k < columns; k++)
				{
					step.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}
		return step;
	}

};

Matrix& Matrix :: operator=(const Matrix& m) {
	if (this != &m)
	{
		for (int i = 0; i < string; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		string = m.string;
		columns = m.columns;
		matrix = new double* [string];
		for (int i = 0; i < string; i++)
		{
			matrix[i] = new double[columns];
		}
		for (int i = 0; i < string; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matrix[i][j] = m.matrix[i][j];
			}
		}
		return* this;
	}
};

