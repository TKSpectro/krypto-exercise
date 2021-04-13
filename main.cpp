#include <iostream>

#include "./src/series1.h"

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

int main() {
    series1(93, 42);

    return 0;
}
