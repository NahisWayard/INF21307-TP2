#include <iostream>
#include "MyFloat.hpp"
#include "MyFixed.hpp"

int main(int ac, char **av) {
    /* MY FIXED */
    typedef MyFixed<uint16_t, 4> FixedForTP;

    auto f = FixedForTP(6.51f);
    auto d = FixedForTP(2.125f);

    auto res = f + d;
    std::cout << res << std::endl;
    res = f - d;
    std::cout << res << std::endl;
    /* END MY FIXED */

    //auto f = MyFloat(0b0000000001110011);
    //auto f = MyFloat(124);
    //auto f = MyFloat(6.51f);
    //auto d = MyFloat(2.125f);

    //auto res = f + d;

    //auto res2 = f-d;
    //auto t = MyFloat(34);

    //uint16_t test = f.testUintToFix(124);
    //uint16_t test = f.testFloatToFix(7.25f);

    //f.testFixToFloat(test);
    //uint16_t test2 = f.testDoubleToFix(7.9);

    //f.testFixToDouble(test + test2);
    // uint16_t testDoubleToFix(double x);
    // double testFixToDouble(uint16_t x);
    //f.testUintToFix(test);
    // uint16_t testFixToInt(uint16_t x);

    //f.testFixToInt(test);
    //f.testFixToDouble(t);

    //std::cout << f-t;

    // f.setSignificand(0b1111);
    // f.setExponent(0b1010);

    // f.setExponent(f.getExponent() + 1);
    // std::cout << f << std::endl;

    // auto f1 = MyFloat(f.getSignificand(), f.getExponent());
    // std::cout << f1 << std::endl;
}