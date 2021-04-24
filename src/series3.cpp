#include <iostream>
#include "series3.h"

int blumBlumShubGenerator(int p, int q, int s, int amount) {
    int n = p * q;

    int xOld = (s * s) % n;
    int xCurrent;
    int bCurrent;
    for (int i = 0; i < amount; ++i) {
        xCurrent = (xOld * xOld) % n;
        bCurrent = xCurrent % 2;
        std::cout << bCurrent;

        xOld = xCurrent;
    }

    std::cout << std::endl;

    return 0;
}
