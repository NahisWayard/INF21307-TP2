#ifndef INF21307_TP2_MYFLOAT_HPP
#define INF21307_TP2_MYFLOAT_HPP

#include <cstdint>
#include <ostream>

#define SIGNIFICAND_MASK 0b1111111111110000
#define EXPONENT_MASK 0b0000000000001111

class MyFloat {
    uint16_t data;

public:
    MyFloat(uint16_t data);
    MyFloat(uint16_t significand, uint16_t exponent);
    uint16_t getSignificand() const;
    uint16_t getExponent() const;
    void setSignificand(uint16_t s);
    void setExponent(uint16_t e);
    uint16_t getData() const;

    friend std::ostream &operator <<(std::ostream &os, const MyFloat &aFloat);

private:
};

#endif
