#include <iostream>
#include "Vector.h"
#include <cmath>



int main()
{
	int x, y, z, n, m, k;
	Vector a, b, c;
	std::cout << "Enter first vector" << endl;
	std::cin >> x >> y >> z;
	std::cout << "Enter second vector" << endl;
	std::cin >> n >> m >> k;
	a = Vector(x, y, z);
	b = Vector(n, m, k);
	c = a + b;
}