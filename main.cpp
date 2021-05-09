#include <iostream>

#include "./src/series1.h"
#include "./src/series2.h"
#include "./src/series3.h"
#include "./src/series4/des.h"

void series1(int a, int b)
{
	std::cout << "--- Series 1 ---" << std::endl;
	std::cout << "Input values" << std::endl;
	std::cout << "  a: " << a << std::endl;
	std::cout << "  b: " << b << std::endl << std::endl;
	std::cout << "ggT: " << ggT(a, b) << std::endl;
	std::cout << "extendedEuclideanAlgorithm" << std::endl;

	print_axyReturn(extendedEuclideanAlgorithm(a, b));

	std::cout << "--- Series 1 END ---" << std::endl;
}

void series2()
{
	std::cout << "--- Series 2 ---" << std::endl;

	std::string plaintext = "ANGEWANDTEINFORMATIK";
	std::cout << "Klartext: " << plaintext << std::endl;
	std::string key = "KEY";
	std::cout << "Schluessel: " << key << std::endl;

	std::string encodedText = encodeVigenere(plaintext, key);
	std::cout << "Geheimtext: " << encodedText << std::endl;

	std::cout << "Frequency Check:" << std::endl;

	int* frequencyArray = new int[26];
	frequencyArray = countLetterFrequency("JA MOIN WAS GEHT", frequencyArray);
	outputLetterFrequencies(frequencyArray, true);

	std::cout << "--- Series 2 END ---" << std::endl;
}

void series3()
{
	std::cout << "--- Series 3 ---" << std::endl;

	std::cout << "p: 7, q: 19, s: 2" << std::endl;
	blumBlumShubGenerator(7, 19, 2, 100);
	std::cout << "repeating number:\"010110\" " << std::endl;

	std::cout << "p: 47, q: 67, s: 6" << std::endl;
	blumBlumShubGenerator(47, 67, 6, 100);

	std::cout << "--- Series 3 END ---" << std::endl;
}

void series4()
{
	// Fill a vector with the numbers from 1..64
	std::vector<int> input(64);
	for(int i = 0; i < 64; i++)
	{
		input[i] = i + 1;
	}

	std::pair<std::vector<int>, std::vector<int>> startPermVector = startPermutation(input);
	// Extract the left and right vector into their own variables
	std::vector<int> left = startPermVector.first;
	std::vector<int> right = startPermVector.second;
	// Output first the left vector and then the right one
	std::cout << "startPermutation:\n";
	for(int i : left)
	{
		;
		std::cout << i << " ";
	}
	for(int i : right)
	{
		;
		std::cout << i << " ";
	}

	// For the endPerm we have to combine the left and right vector
	std::vector<int> input2;
	input2.reserve(left.size() + right.size());
	input2.insert(input2.end(), left.begin(), left.end());
	input2.insert(input2.end(), right.begin(), right.end());

	std::vector<int> endPermVector = endPermutation(input2);
	std::cout << "\nendPermutation:\n";
	// Output the endPermutated vector
	for(int i : endPermVector)
	{
		;
		std::cout << i << " ";
	}
	std::cout << "\n";
}


int main()
{
	//series1(93, 42);
	//series2();
	//series3();
	series4();

	return 0;
}
