#include "series8.h"
#include <iostream>
#include <math.h>

Pair extendedEuclideanAlgorithm(int a0, int a1)
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

	return {xOld, yOld};
}

int encodeRabin(int p, int q, int m)
{
	if(p % 4 != 3 || q % 4 != 3)
	{
		printf("p or q not ok");
	}

	int n = p * q;

	if(m >= n)
	{
		printf("message to big");
	}

	int cipher = (m * m) % n;
	return cipher;
}

RabinDecode decodeRabin(int c, int p, int q)
{
	int n = p * q;

	int mp = (int)pow(c, (p + 1) / 4) % p;
	int mq = (int)pow(c, (q + 1) / 4) % q;

	Pair pair = extendedEuclideanAlgorithm(p, q);

	int yp = pair.yp;
	int yq = pair.yq;

	int r = (yp * p * mq + yq * q * mp) % n;
	while(r < 0)
	{
		r = r + n;
	}
	int nr = n - r;

	int s = (yp * p * mq - yq * q * mp) % n;
	while(s < 0)
	{
		s = s + n;
	}
	int ns = n - s;

	return {r, nr, s, ns};
}

int main()
{
	int message = 40;
	int p = 7;
	int q = 11;

	int c = encodeRabin(p, q, message);
	std::cout << "Cipher: " << c << std::endl;

	RabinDecode decoded = decodeRabin(c, p, q);
	std::cout << "Decoded: " << std::endl;
	std::cout << "   r: " << decoded.r << std::endl;
	std::cout << "  -r: " << decoded.nr << std::endl;
	std::cout << "   s: " << decoded.s << std::endl;
	std::cout << "  -s: " << decoded.ns << std::endl;



	return 0;
}