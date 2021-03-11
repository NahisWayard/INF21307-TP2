#include <bitset>
#include <iostream>
#include "MyFloat.hpp"

MyFloat::MyFloat(uint16_t data) :
        data(data) {
}

MyFloat::MyFloat(uint16_t significand, uint16_t exponent) : data(0) {
    data = (((significand) << 4) & SIGNIFICAND_MASK) | (exponent & EXPONENT_MASK);
}

uint16_t MyFloat::getSignificand() const {
    return (data & SIGNIFICAND_MASK) >> 4;
}

uint16_t MyFloat::getExponent() const {
    return data & EXPONENT_MASK;
}

std::ostream &operator <<(std::ostream &os, const MyFloat &aFloat) {
    //TODO Display as floating point thing (ex: 13.234)
    os << "RAW: " << std::bitset<16>(aFloat.data) <<  std::endl <<
        "Significand: " << std::bitset<12>(aFloat.getSignificand()) << "(" << aFloat.getSignificand() << ")" << std::endl <<
        "Exponent: " << std::bitset<4>(aFloat.getExponent()) << "(" << aFloat.getExponent() << ")"<< std::endl;
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

bool operator ==(const MyFloat &lhs, const MyFloat &rhs) {
    return lhs.data == rhs
            .data;
}

bool operator !=(const MyFloat &lhs, const MyFloat &rhs) {
    return !(rhs == lhs);
}

MyFloat operator +(const MyFloat &lhs, const MyFloat &rhs) {
    return MyFloat(0);//TODO
}

MyFloat operator -(const MyFloat &lhs, const MyFloat &rhs) {
    return MyFloat(0);//TODO
}

MyFloat operator *(const MyFloat &lhs, const MyFloat &rhs) {
    return MyFloat(0);//TODO
}

MyFloat operator /(const MyFloat &lhs, const MyFloat &rhs) {
    return MyFloat(0);//TODO
}

bool MyFloat::isInf() const {
    if ((data & EXPONENT_MASK) == MAX_EXPONENT && (data & SIGNIFICAND_MASK) == 0)
        return true;
    return false;
}

bool MyFloat::isNaN() const {
    if ((data & EXPONENT_MASK) == MAX_EXPONENT && (data & SIGNIFICAND_MASK) != 0)
        return true;
    return false;
}

