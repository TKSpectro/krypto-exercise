#ifndef SERIES7_CPP_DES_H
#define SERIES7_CPP_DES_H

struct Point
{
	int x;
	int y;
};

Point calcR(Point p, Point q, int a, int modP);

int ellipticCurve(Point point, int a, int b, int p);

void pointMultiplication(Point point, int d, int p, int a, int b);

#endif //SERIES7_CPP_DES_H