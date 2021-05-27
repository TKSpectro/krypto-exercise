#include <iostream>
#include "series3.h"

int blumBlumShubGenerator(int p, int q, int s, int amount)
{
	int n = p * q;

	int xOld = (s * s) % n;
	int xCurrent;
	int bCurrent;
	for(int i = 0; i < amount; ++i)
	{
		xCurrent = (xOld * xOld) % n;
		bCurrent = xCurrent % 2;
		std::cout << bCurrent;

		xOld = xCurrent;
	}

	std::cout << std::endl;

	return 0;
}

int main()
{
	std::cout << "--- Series 3 ---" << std::endl;

	std::cout << "p: 7, q: 19, s: 2" << std::endl;
	blumBlumShubGenerator(7, 19, 2, 100);
	std::cout << "repeating number:\"010110\" " << std::endl;

	std::cout << "p: 47, q: 67, s: 6" << std::endl;
	blumBlumShubGenerator(47, 67, 6, 100);

	std::cout << "--- Series 3 END ---" << std::endl;

	return 0;
}