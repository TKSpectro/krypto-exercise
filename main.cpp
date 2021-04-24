#include <iostream>

#include "./src/series1.h"
#include "./src/series2.h"
#include "./src/series3.h"


void series1(int a, int b) {
    std::cout << "--- Series 1 ---" << std::endl;
    std::cout << "Input values" << std::endl;
    std::cout << "  a: " << a << std::endl;
    std::cout << "  b: " << b << std::endl << std::endl;
    std::cout << "ggT: " << ggT(a, b) << std::endl;
    std::cout << "extendedEuclideanAlgorithm" << std::endl;

    print_axyReturn(extendedEuclideanAlgorithm(a, b));

    std::cout << "--- Series 1 END ---" << std::endl;
}

void series2() {
    std::cout << "--- Series 2 ---" << std::endl;

    std::string plaintext = "ANGEWANDTEINFORMATIK";
    std::cout << "Klartext: " << plaintext << std::endl;
    std::string key = "KEY";
    std::cout << "Schluessel: " << key << std::endl;

    std::string encodedText = encodeVigenere(plaintext, key);
    std::cout << "Geheimtext: " << encodedText << std::endl;

    std::cout << "Frequency Check:" << std::endl;

    int *frequencyArray = new int[26];
    frequencyArray = countLetterFrequency("JA MOIN WAS GEHT", frequencyArray);
    outputLetterFrequencies(frequencyArray, true);

    std::cout << "--- Series 2 END ---" << std::endl;
}

void series3() {
    std::cout << "--- Series 3 ---" << std::endl;

    std::cout << "p: 7, q: 19, s: 2" << std::endl;
    blumBlumShubGenerator(7, 19, 2, 100);
    std::cout << "repeating number:\"010110\" " << std::endl;

    std::cout << "p: 47, q: 67, s: 6" << std::endl;
    blumBlumShubGenerator(47, 67, 6, 100);

    std::cout << "--- Series 3 END ---" << std::endl;
}


int main() {
    //series1(93, 42);
    //series2();
    series3();

    return 0;
}
