#include "series7.h"
#include <iostream>
int extendedEuclideanAlgorithm(int a0, int a1)
{
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

	return xOld;
}

int ellipticCurve(Point point, int a, int b, int p)
{
	int x = point.x;
	int y = point.y;

	return y * y == ((x * x * x) + a * x + b) % p;
}

Point calcR(Point p, Point q, int a, int modP)
{
	int m = 0;
	if(p.x != q.x || p.y != q.y)
	{
		//m = (q.y - p.y) / (q.x - p.x);
		m = ((q.y - p.y) + modP) * extendedEuclideanAlgorithm(((q.x - p.x) + modP), modP);
	}
	else
	{
		//m = (3 * p.x * p.x + a) / (2 * p.y);
		m = (3 * (p.x * p.x) + a) * extendedEuclideanAlgorithm((2 * p.y), modP);
	}

	int x3 = (m * m - p.x - q.x) % modP;
	int y3 = (m * (p.x - x3) - p.y) % modP;

	while(x3 < 0)
	{
		x3 += modP;
	}
	while(y3 < 0)
	{
		y3 += modP;
	}

	return {x3,y3};
}

void pointMultiplication(Point point, int d, int p, int a, int b)
{
	Point save = point;
	for(int i = 0; i < d; i++)
	{
		if(save.x == point.x && p == save.y + point.y)
		{
			std::cout << "Inverse found at round: " << i << std::endl;
			exit(0);
		}

		save = calcR(save, point, a, p);
	}

	std::cout << save.x << " " << save.y << std::endl;
}

int main()
{
	for(int i = 0; i < 23; i++)
	{
		std::cout << i + 2 << "P: ";
		pointMultiplication({5,1}, i, 17, 2, 2);
	}


	return 0;
}