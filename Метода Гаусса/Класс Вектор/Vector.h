#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
using namespace std;
class Vector
{
private:
	double* vector;
	int x, y, z;
	int n = 3;
public:
	Vector(int _x = 3, int _y = 3, int _z = 3);
	Vector(const Vector& v);
	Vector(double* massive, int _x, int _y, int _z);
	~Vector();
	void PrintVect() const;
	Vector operator+(const Vector& v);	
	Vector operator*(const Vector& v);
	Vector operator%(const Vector& v);
};


#endif
