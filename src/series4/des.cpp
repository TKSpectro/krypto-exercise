#include <iostream>
#include "des.h"

#include "des_data.h"
#include <bitset>

std::pair<std::vector<int>, std::vector<int>> startPermutation(std::vector<int> input)
{
	int position;

	std::vector<int> leftVector(32);
	std::vector<int> rightVector(32);

	// Calculate the left vector
	for(int i = 0; i < 32; i++)
	{
		position = IP[i] - 1;
		leftVector[i] = input[position];
	}
	// Calculate the right vector
	for(int i = 32; i < 64; i++)
	{
		position = IP[i] - 1;
		rightVector[i - 32] = input[position];
	}

	// Return both vectors as a pair with the first being the left one
	return std::pair<std::vector<int>, std::vector<int>>(leftVector, rightVector);
}

std::vector<int> endPermutation(std::vector<int> input)
{
	int position;
	std::vector<int> result(64);

	for(int i = 0; i < 64; i++)
	{
		position = FP[i] - 1;
		result[i] = input[position];
	}

	return result;
}

std::vector<int> expandPermutation(std::vector<int> input)
{
	std::vector<int> result(48);

	// Walk through out expansion pattern and reposition the numbers
	// from the clearText array to the right position
	for(int i = 0; i < 48; i++)
	{
		result[i] = input[EXPANSION[i] - 1];
	}

	return result;
}

std::vector<int> sBoxPermutation(std::vector<int> input)
{
	std::vector<int>result(32);

	std::vector<int> currentBlock(6);

	std::bitset<2> rowBits{"00"};
	std::bitset<4> colBits{"0000"};

	for(int i = 0; i < 8; i++)
	{
		currentBlock[0] = input[i * 6 + 0];
		currentBlock[1] = input[i * 6 + 1];
		currentBlock[2] = input[i * 6 + 2];
		currentBlock[3] = input[i * 6 + 3];
		currentBlock[4] = input[i * 6 + 4];
		currentBlock[5] = input[i * 6 + 5];

		//currentBlock[0] = 1;
		//currentBlock[1] = 0;
		//currentBlock[2] = 0;
		//currentBlock[3] = 1;
		//currentBlock[4] = 0;
		//currentBlock[5] = 1;

		rowBits.set(0, currentBlock[5] == 1);
		rowBits.set(1, currentBlock[0] == 1);
		int row = rowBits.to_ulong();

		colBits.set(0, currentBlock[4] == 1);
		colBits.set(1, currentBlock[3] == 1);
		colBits.set(2, currentBlock[2] == 1);
		colBits.set(3, currentBlock[1] == 1);
		int col = colBits.to_ulong();

		int sBoxVal = S_BOXES[i][row * 16 + col];
		std::bitset<4> sBoxBits(sBoxVal);

		result[i * 4 + 0] = sBoxBits[3];
		result[i * 4 + 1] = sBoxBits[2];
		result[i * 4 + 2] = sBoxBits[1];
		result[i * 4 + 3] = sBoxBits[0];
	}

	return result;
}

std::vector<int> pBoxPermutation(std::vector<int> input)
{
	std::vector<int>result(32);

	for(int i = 0; i < 32; i++)
	{
		result[i] = input[P_BOX[i] - 1];
	}

	return result;
}

std::pair<std::vector<int>, std::vector<int>> keyPermutation(std::vector<int> input)
{
	std::vector<int> x0(28);
	std::vector<int> y0(28);

	for(int i = 0; i < 56; i++)
	{
		if(i < 28)
		{
			x0[i] = input[KEY_PERM[i] - 1];
		}
		else
		{
			y0[i - 28] = input[KEY_PERM[i] - 1];
		}
	}

	// Return both vectors as a pair with the first being x0
	return std::pair<std::vector<int>, std::vector<int>>(x0, y0);
}

std::vector<std::vector<int>> keyRotation(std::pair<std::vector<int>, std::vector<int>> input)
{
	std::vector<std::vector<int>> keys(16);
	std::vector<int> subkey;

	int tempX1;
	int tempX2;

	int tempY1;
	int tempY2;

	std::vector<int> x = input.first;
	std::vector<int> y = input.second;

	for(int i = 0; i < 16; i++)
	{
		if(KEY_ROT[i] == 1)
		{
			tempX1 = x[0];
			tempY1 = y[0];
			for(int i = 0; i < 27; i++)
			{
				x[i] = x[i + 1];
				y[i] = y[i + 1];
			}
			x[27] = tempX1;
			y[27] = tempY1;
		}
		else
		{
			tempX1 = x[0];
			tempX2 = x[1];

			tempY1 = y[0];
			tempY2 = y[1];
			for(int i = 0; i < 26; i++)
			{
				x[i] = x[i + 2];
				y[i] = y[i + 2];
			}
			x[26] = tempX1;
			x[27] = tempX2;

			y[26] = tempY1;
			y[27] = tempY2;
		}


		subkey.reserve(x.size() + y.size());
		subkey.insert(subkey.end(), x.begin(), x.end());
		subkey.insert(subkey.end(), y.begin(), y.end());

		keys[i] = subkey;
	}

	return keys;
}

std::vector<int> keyCompressionPermutation(std::vector<int> input)
{
	std::vector<int> result(48);

	for(int i = 0; i < 48; i++)
	{
		result[i] = input[KEY_COMP_PERM[i] - 1];
	}

	return result;
}

std::vector<int> encryptDES(std::vector<int> clearText, std::vector<int> key)
{
	bool debug = false;
	// put the cleartext into the startPermutation function
	std::pair<std::vector<int>, std::vector<int>> startPermVector = startPermutation(clearText);
	// Extract the left and right vector into their own variables

	std::vector<int> left = startPermVector.first;
	std::vector<int> right = startPermVector.second;

	std::vector<int> rightTemp(32);

	std::pair<std::vector<int>, std::vector<int>> permutatedKey = keyPermutation(key);
	std::vector<std::vector<int>> rotatedKeys = keyRotation(permutatedKey);

	for(int round = 0; round < 16; round++)
	{
		// save the right vector temporary for this round
		rightTemp = right;

		// Ri = Li-1 XOR f(Ri-1,Ki)
		// expand the right vector
		std::vector<int> expanded = expandPermutation(right);
		// get the new key for this round
		std::vector<int> compPermKey = keyCompressionPermutation(rotatedKeys[round]);

		std::bitset<48> expandedBits;
		std::bitset<48> comPermKeyBits;

		for(int i = 0; i < 48; i++)
		{
			expandedBits.set(i, expanded[47 - i] == 1);
			comPermKeyBits.set(i, compPermKey[47 - i] == 1);
		}

		std::bitset<48> XORedBits = (expandedBits ^ comPermKeyBits);
		std::vector<int> XORedVec(48);
		for(int i = 0; i < 48; i++)
		{
			XORedVec[i] = XORedBits[47 - i];
		}

		std::vector<int> sboxed = sBoxPermutation(XORedVec);
		std::vector<int> pboxed = pBoxPermutation(sboxed);


		// rightNew = pboxed XOR lOld
		std::bitset<32> pboxedBits;
		std::bitset<32> lOldBits;
		for(int i = 0; i < 32; i++)
		{
			pboxedBits.set(i, pboxed[31 - i] == 1);
			lOldBits.set(i, left[31 - i] == 1);
		}
		std::bitset<32> rightNewBits = (pboxedBits ^ lOldBits);
		for(int i = 0; i < 32; i++)
		{
			right[i] = rightNewBits[31 - i];
		}

		// Li = Ri-1
		left = rightTemp;
	}


	// For the endPerm we have to combine the left and right vector
	std::vector<int> finishedVector;
	finishedVector.reserve(left.size() + right.size());
	finishedVector.insert(finishedVector.end(), left.begin(), left.end());
	finishedVector.insert(finishedVector.end(), right.begin(), right.end());

	std::vector<int> endPermVector = endPermutation(finishedVector);

	if(debug)
	{
		// Output first the left vector and then the right one
		std::cout << "startPermutation:\n";
		for(int i : left)
		{
			std::cout << i << " ";
		}
		for(int i : right)
		{
			std::cout << i << " ";
		}

		std::cout << "\n\nexpandPermutation:\n";
		for(int i = 0; i < 48; i++)
		{
			//std::cout << expanded[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "\nendPermutation:\n";
		// Output the endPermutated vector
		for(int i : endPermVector)
		{
			;
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	return endPermVector;
}
