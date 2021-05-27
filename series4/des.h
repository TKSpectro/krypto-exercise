#ifndef SERIES1_CPP_DES_H
#define SERIES1_CPP_DES_H

#include <cstdint>
#include <vector>

std::pair<std::vector<int>, std::vector<int>> startPermutation(std::vector<int> input);
std::vector<int> endPermutation(std::vector<int> input);

std::vector<int> expandPermutation(std::vector<int> input);

std::vector<int> sBoxPermutation(std::vector<int> input);
std::vector<int> pBoxPermutation(std::vector<int> input);

std::pair<std::vector<int>, std::vector<int>> keyPermutation(std::vector<int> input);
std::vector<std::vector<int>> keyRotation(std::pair<std::vector<int>, std::vector<int>> input);
std::vector<int> keyCompressionPermutation(std::vector<int> input);

std::vector<int> encryptDES(std::vector<int> clearText, std::vector<int> key);
#endif //SERIES1_CPP_DES_H
