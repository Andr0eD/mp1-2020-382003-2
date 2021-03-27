#include "Vector.h"

Vector::Vector(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {
	for (int i = 0; i < n; i++)
	{
		vector[n] = 0.0;
	}
};

Vector::Vector(const Vector& v) : x(v.x), y(v.y), z(v.z){
	for (int i = 0; i < n; i++)
	{
		vector[n] = v.vector[n];
	}
};

Vector::Vector(double* massive, int _x, int _y, int _z) : x(_x), y(_y), z(_z) {
	for (int i = 0; i < n; i++)
	{
		vector[n] = massive[n];
	}
};

Vector :: ~Vector() {
	delete[] vector;
};

void Vector::PrintVect() const {

};

Vector Vector :: operator+(const Vector& v) {
	int dx = x * v.x;
	int dy = y * v.y;
	int dz = z * v.z;
	return Vector(dx, dy, dz);
};

Vector Vector :: operator%(const Vector& v) {
	int dx = x * v.x;
	int dy = y * v.y;
	int dz = z * v.z;
	return Vector((dx + dy + dz), dx * 0, dy * 0);
};

Vector Vector :: operator*(const Vector& v) {
	int dx = y * v.z - z * v.y;
	int dy = z * v.x - x * v.z;
	int dz = x * v.y - y * v.x;
	return Vector((dx + dy + dz), dx * 0, dy * 0);
};




