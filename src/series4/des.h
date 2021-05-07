#ifndef SERIES1_CPP_DES_H
#define SERIES1_CPP_DES_H

#include <cstdint>
#include <vector>

#define ui64 uint64_t
#define ui32 uint32_t
#define ui8 uint8_t

std::pair<std::vector<int>, std::vector<int>> startPermutation(std::vector<int> input);

std::vector<int> endPermutation(std::vector<int> input);

ui64 encrypt(ui64 block);

ui64 decrypt(ui64 block);

#endif //SERIES1_CPP_DES_H
