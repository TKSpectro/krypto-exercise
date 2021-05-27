#include <cmath>
#include <iostream>
#include "series1.h"

int ggT(int a, int b)
{
	int rest = b;

	while(rest != 0)
	{
		rest = a % b;
		a = b;
		b = rest;
	}

	return a;
}

axyReturn extendedEuclideanAlgorithm(int a0, int a1)
{
	axyReturn result{};

	int xOld = 1;
	int xCurrent = 0;
	int xNew;

	int yOld = 0;
	int yCurrent = 1;
	int yNew;

	int aOld = a0;
	int aCurrent = a1;
	int aNew;

	int q;

	while(aCurrent != 0)
	{
		q = floor(aOld / aCurrent);

		aNew = aOld - q * aCurrent;
		xNew = xOld - q * xCurrent;
		yNew = yOld - q * yCurrent;

		aOld = aCurrent;
		xOld = xCurrent;
		yOld = yCurrent;

		aCurrent = aNew;
		xCurrent = xNew;
		yCurrent = yNew;
	}

	result.a = aOld;
	result.x = xOld;
	result.y = yOld;
	return result;
}

void print_axyReturn(axyReturn axy)
{
	std::cout << "  a:" << axy.a << std::endl;
	std::cout << "  x:" << axy.x << std::endl;
	std::cout << "  y:" << axy.y << std::endl;
}

int main()
{
	int a = 93;
	int b = 42;

	std::cout << "--- Series 1 ---" << std::endl;
	std::cout << "Input values" << std::endl;
	std::cout << "  a: " << a << std::endl;
	std::cout << "  b: " << b << std::endl << std::endl;
	std::cout << "ggT: " << ggT(a, b) << std::endl;
	std::cout << "extendedEuclideanAlgorithm" << std::endl;

	print_axyReturn(extendedEuclideanAlgorithm(a, b));

	std::cout << "--- Series 1 END ---" << std::endl;

	return 0;
}