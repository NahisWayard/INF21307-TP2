#include <bitset>
#include <iostream>
#include "MyFloat.hpp"

MyFloat::MyFloat(uint16_t data) :
        data(data) {
}

uint16_t MyFloat::getSignificand() const {
    return (data & SIGNIFICAND_MASK) >> 4;
}

uint16_t MyFloat::getExponent() const {
    return data & EXPONENT_MASK;
}

std::ostream &operator <<(std::ostream &os, const MyFloat &aFloat) {
    os << "RAW: " << std::bitset<16>(aFloat.data) <<  std::endl <<
        "Significand: " << std::hex << std::bitset<12>(aFloat.getSignificand()) << std::endl <<
        "Exponent: " << std::hex << std::bitset<4>(aFloat.getExponent()) << std::endl;
    return os;
}

uint16_t MyFloat::getData() const {
    return data;
}

void MyFloat::setSignificand(uint16_t s) {
    data = (data & EXPONENT_MASK) | (((s) << 4) & SIGNIFICAND_MASK);
}

void MyFloat::setExponent(uint16_t e) {
    data = (data & SIGNIFICAND_MASK) | (e & EXPONENT_MASK);
}

MyFloat::MyFloat(uint16_t significand, uint16_t exponent) : data(0) {
    setExponent(exponent);
    setSignificand(significand);
}
