#include "rsa.h"
#include <bitset>

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

int squareMultiply(int base, int exponent, int mod)
{
	int result;
	std::bitset<256> expBits(exponent);
	bool firstOneAlreadyHit = false;
	for(int i = 255; i >= 0; i--)
	{
		if(firstOneAlreadyHit == true)
		{
			if(expBits[i] == 1)
			{
				result = (result * result * base) % mod;
				printf("");
			}
			else
			{
				result = (result * result) % mod;
				printf("");
			}
		}

		if(firstOneAlreadyHit == false && expBits[i] == 1)
		{
			firstOneAlreadyHit = true;
			result = (1 * 1 * base) % mod;
		}
	}

	return result;
}

rsaReturn rsaEncode(int p, int q, int M)
{
	rsaReturn result;

	result.n = p * q;
	result.phi = (p - 1) * (q - 1);

	bool worked = false;
	int counter = 3;
	while(!worked)
	{
		if(ggT(counter, result.phi) == 1)
		{
			worked = true;
			result.e = counter;
		}
		counter++;
	}

	result.d = extendedEuclideanAlgorithm(result.e, result.phi);

	result.C = squareMultiply(M, result.e, result.n);

	return result;
}

int main()
{
	//Vorlesungs Beispiel
	rsaReturn encodedMessage1 = rsaEncode(13, 23, 212);
	// Übungs Beispiel 1
	rsaReturn encodedMessage3 = rsaEncode(11, 13, 15);
	// Übungs Beispiel 2
	rsaReturn encodedMessage2 = rsaEncode(23, 67, 15);

	return 0;
}