#ifndef KRYPTO_EXERCISE_SERIES2_H
#define KRYPTO_EXERCISE_SERIES2_H


#include <string>

std::string encodeVigenere(std::string plaintext, std::string secret);

int *countLetterFrequency(std::string text, int letterFrequency[26]);

void outputLetterFrequencies(int letterFrequency[26], bool onlyOutputPresentOnes);

#endif //KRYPTO_EXERCISE_SERIES2_H
