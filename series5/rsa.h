#ifndef SERIES5_CPP_DES_H
#define SERIES5_CPP_DES_H

#include <cstdint>
#include <vector>

struct rsaReturn
{
	int d;
	int e;
	int phi;
	int n;
	int C;
};

int ggT(int a, int b);
int extendedEuclideanAlgorithm(int a, int b);

int squareMultiply(int base, int exponent, int mod);

rsaReturn rsaEncode(int p, int q, int M);

#endif //SERIES5_CPP_DES_H