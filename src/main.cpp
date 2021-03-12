#include <iostream>
#include <bitset>
#include "MyFixed.hpp"

int main(int ac, char **av) {
    typedef MyFixed<uint16_t, 4> FixedForTP;

    auto f = FixedForTP(1.1f);
    auto d = FixedForTP(1.25f);

    auto epsilon = FixedForTP(1.0f);
    epsilon.data = 1;

    std::cout << epsilon << std::endl;

    auto res = f * d;
    std::cout << f << "*" << d << "=" << res << std::endl;
    res = f / d;
    std::cout << f << "/" << d << "=" << res << std::endl;
}