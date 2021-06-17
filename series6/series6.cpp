#include "series6.h"
#include <bitset>
#include <math.h>
#include <iostream>

int squareMultiply(int base, int exponent, int mod)
{
	int result;
	std::bitset<2048> expBits(exponent);
	bool firstOneAlreadyHit = false;
	for(int i = 2047; i >= 0; i--)
	{
		if(firstOneAlreadyHit == true)
		{
			if(expBits[i] == 1)
			{
				result = (result * result * base) % mod;
			}
			else
			{
				result = (result * result) % mod;
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

int CHPHash(int x1, int x2)
{
	int p = 12347;

	int alpha = 2;
	int beta = 8461;

	int a = squareMultiply(alpha, x1, p);
	int b = squareMultiply(beta, x2, p);

	int result = (a * b) % p;

	return result;
}

int main()
{
	std::cout << squareMultiply(8, 27, 55) << std::endl;

	std::cout << CHPHash(5692, 144) << std::endl;
	std::cout << CHPHash(1220, 54) << std::endl;
	std::cout << CHPHash(212, 4214) << std::endl;

	return 0;
}
