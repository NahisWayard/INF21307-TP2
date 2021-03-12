#include <iostream>
#include <bitset>
#include "MyFixed.hpp"

typedef MyFixed<uint16_t , 4> FixedForTP;

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
    std::cout << "MyFixed newton: " << newton<MyFixed<uint64_t, 16>>(n, it) << std::endl;
    std::cout << "MyFixedTPConditions newton: " << newton<FixedForTP>(n, it) << std::endl;
    std::cout << "System float newton:" << newton<float>(n, it) << std::endl;
}

int main(int ac, char **av) {

    auto f = FixedForTP(1.1f);
    auto d = FixedForTP(3.0f);

    auto epsilon = FixedForTP(1.0f);
    epsilon.data = 1;

    std::cout << epsilon << std::endl;

    auto res = f * d;
    std::cout << f << "*" << d << "=" << res << std::endl;
    res = f / d;
    std::cout << f << "/" << d << "=" << res << std::endl;

    testNewton(15, 1000);
    testNewton(2, 1000);
}
