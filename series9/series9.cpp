#include "series9.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <bitset>

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
	while(result < 0) result += mod;

	return result;
}

bool millerRabinTest(int n, int d, int s)
{
	int a = 2 + rand() % (n - 2);
	int x = squareMultiply(a, d, n);
	int oldX;

	for(int i = 0; i < s; i++)
	{
		oldX = x;
		x = squareMultiply(oldX, 2, n);

		if(x == 1 && oldX != 1 && oldX != n - 1)
		{
			return true;
		}
	}
	if(x != 1)
	{
		return true;
	}

	return false;
}

bool isPrime(int n, int k)
{
	if(n < 2) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;


	int s = 0;
	int d = n - 1;
	while(d % 2 == 0)
	{
		s++;
		d /= 2;
	}

	for(int i = 0; i < k; i++)
	{
		if(millerRabinTest(n, d, s))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	srand(time(0));

	int comp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
	int number = 0;
	int notFound[100];
	int notFoundCounter = 0;
	for(int i = 0; i < 1000; i++)
	{
		if(comp[number] == i)
		{
			number++;
			if(isPrime(i, 2))
			{
				std::cout << i << ", ";
			}
			else
			{
				notFound[notFoundCounter] = i;
				notFoundCounter++;
			}
		}
	}

	if(notFoundCounter > 0)
	{
		std::cout << "\nNOT FOUND: " << notFoundCounter << " | ";
		for(int i = 0; i < notFoundCounter; i++)
		{
			std::cout << notFound[i] << ", ";
		}
	}
	return 0;
}