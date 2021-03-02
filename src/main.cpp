#include <iostream>
#include "MyFloat.hpp"

int main(int ac, char **av) {
    auto f = MyFloat(0b0000000001110011);

    std::cout << f;

    f.setSignificand(0b1111);
    f.setExponent(0b1010);

    std::cout << f;
}