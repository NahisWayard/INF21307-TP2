#include <iostream>
#include <bitset>
#include "MyFixed.hpp"

typedef MyFixed<uint16_t , 4> FixedForTP;
typedef MyFixed<uint64_t , 16> FixedForBestPrecision;

template<typename T>
T newton(size_t n, size_t it) {
    auto res = T((float)n);
    auto nAsFixed = T((float)n);
    auto half = T(0.5f);

    for (size_t i = 0; i < it; i++) {
        res = ((nAsFixed / res) + res) * half;
    }

    return res;
}

void testNewton(size_t n, size_t it) {
    std::cout << "------------N: " << n << " --- IT: " << it <<  "------------" << std::endl;
    std::cout << "MyFixed newton: " << newton<FixedForBestPrecision>(n, it) << std::endl;
    std::cout << "MyFixedTPConditions newton: " << newton<FixedForTP>(n, it) << std::endl;
    std::cout << "System float newton:" << newton<float>(n, it) << std::endl;
}

int main(int ac, char **av) {
    auto lowestNumber = FixedForTP(1.0f);
    lowestNumber.data = 1;

    std::cout << "The lowest number representable is " << lowestNumber << std::endl;
    auto a = FixedForTP(1.1f);
    auto b = FixedForTP(3.0f);
    auto c = FixedForTP (2.5f);

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << b << " - " << a << " = " << b - a << std::endl;
    std::cout << b << " * " << c << " = " << b * c << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;

    std::cout << "Testing Fixed type implementation with Newton's algorithm" << std::endl;
    testNewton(15, 1000);
    testNewton(2, 1000);
}
