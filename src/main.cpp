#include <iostream>
#include <bitset>
#include "MyFixed.hpp"

int main(int ac, char **av) {
    typedef MyFixed<uint32_t , 16> FixedForTP;

    auto f = FixedForTP(0.125f);
    auto d = FixedForTP(3.0f);

    auto epsilon = FixedForTP(1.0f);
    epsilon.data = 1;

    std::cout << epsilon << std::endl;

    auto res = f * d;
    std::cout << f << "*" << d << "=" << res << std::endl;
    res = f / d;
    std::cout << f << "/" << d << "=" << res << std::endl;
}