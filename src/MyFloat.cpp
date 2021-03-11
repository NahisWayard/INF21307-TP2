#include <bitset>
#include <iostream>
#include <cmath>
#include "MyFloat.hpp"

// MyFloat::MyFloat(uint16_t data) :
//         data(data) {
// }

MyFloat::MyFloat(float data) {
    this->data = this->testFloatToFix(data);
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

uint16_t MyFloat::testFloatToFix(float x) {
    uint16_t tmp = x * (float)(1 << this->scale); // 2^4 = 16
    //uint16_t tmp = x * (float)pow(2, this->scale);
    
    //std::cout << "x : " << x << " || Fixed x : " << tmp << std::endl;

    return tmp;
}

float MyFloat::testFixToFloat(uint16_t x) {
    float tmp = (float)x / (float)(1 << this->scale);
    //float tmp2 = (float)(1 << this->scale);

    //std::cout << "Fixed x : " << x << " || x : " << tmp << std::endl;

    return tmp;
}

uint16_t MyFloat::testUintToFix(uint16_t x) {
    uint16_t tmp = x << this->scale;
    //std::cout << "Uint16 x : " << x << " || Fixed x : " << tmp << std::endl;

    return tmp;
}

uint16_t MyFloat::testFixToInt(uint16_t x) {
    uint16_t tmp = x >> this->scale;
    //std::cout << "Fixed x : " << x << " || Uint16 x : " << tmp << std::endl;

    return tmp;
}


std::ostream &operator <<(std::ostream &os, const MyFloat &aFloat) {
    //TODO Display as floating point thing (ex: 13.234)
    os << "RAW: " << std::bitset<16>(aFloat.data) <<  std::endl <<
        "Significand: " << std::bitset<12>(aFloat.getSignificand()) << "(" << aFloat.getSignificand() << ")" << std::endl <<
        "Exponent: " << std::bitset<4>(aFloat.getExponent()) << "(" << aFloat.getExponent() << ")"<< std::endl;
    return os;
}

void MyFloat::setData(uint16_t d) {
    this->data = d;
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

    auto tmp = MyFloat(0);

    tmp.setData(lhs.getData() + rhs.getData());

    std::cout << tmp.testFixToFloat(lhs.getData()) << " + " << tmp.testFixToFloat(rhs.getData()) << " = " << tmp.testFixToFloat(tmp.getData()) << std::endl;

    return (tmp);//TODO
}

MyFloat operator -(const MyFloat &lhs, const MyFloat &rhs) {

    auto tmp = MyFloat(0);

    tmp.setData(lhs.getData() - rhs.getData());

    std::cout << tmp.testFixToFloat(lhs.getData()) << " - " << tmp.testFixToFloat(rhs.getData()) << " = " << tmp.testFixToFloat(tmp.getData()) << std::endl;

    return (tmp);//TODO
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

