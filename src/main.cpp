#include <iostream>
#include "MyFloat.hpp"

int main(int ac, char **av) {
    auto f = MyFloat(0b0000000001110011);

    std::cout << f;

    f.setSignificand(0b1111);
    f.setExponent(0b1010);

    f.setExponent(f.getExponent() + 1);
    std::cout << f << std::endl;

    auto f1 = MyFloat(f.getSignificand(), f.getExponent());
    std::cout << f1 << std::endl;
}