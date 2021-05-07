#include <iostream>
#include "des.h"

#include "des_data.h"

std::pair<std::vector<int>, std::vector<int>> startPermutation(std::vector<int> input) {
    int position;

    std::vector<int> leftVector(32);
    std::vector<int> rightVector(32);

    // Calculate the left vector
    for (int i = 0; i < 32; i++) {
        position = IP[i] - 1;
        leftVector[i] = input[position];
    }
    // Calculate the right vector
    for (int i = 32; i < 64; i++) {
        position = IP[i] - 1;
        rightVector[i - 32] = input[position];
    }

    // Return both vectors as a pair with the first being the left one
    return std::pair<std::vector<int>, std::vector<int>>(leftVector, rightVector);
}

std::vector<int> endPermutation(std::vector<int> input) {
    int position;
    std::vector<int> result(64);

    for (int i = 0; i < 64; i++) {
        position = FP[i] - 1;
        result[i] = input[position];
    }

    return result;
}