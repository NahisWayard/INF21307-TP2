#ifndef INF21307_TP2_MYFIXED_HPP
#define INF21307_TP2_MYFIXED_HPP

#include <ostream>

template <typename T, unsigned int P>
class MyFixed {
public:
    explicit MyFixed(float input) {
        data = toFixed(input);
    };

    explicit MyFixed(T input) {
        data = input;
    };

private:
    T data;

    static T toFixed(float f) {
        return f * (float)(1 << P);
    };
    float toFloat() const {
        return (float)data / (float)(1 << P);
    };

public:
    friend MyFixed operator +(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        return MyFixed<T, P>((T) (lhs.data + rhs.data));
    };
    friend MyFixed operator -(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        return MyFixed<T, P>((T) (lhs.data - rhs.data));
    };
    //friend MyFixed operator *(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs);
    //friend MyFixed operator /(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs);

    friend bool operator ==(const MyFixed &lhs, const MyFixed &rhs) {
        return lhs.data == rhs.data;
    };
    friend bool operator !=(const MyFixed &lhs, const MyFixed &rhs) {
        return !(rhs == lhs);
    };

    friend std::ostream &operator <<(std::ostream &os, const MyFixed<T, P> &f) {
        os << f.toFloat();
        return os;
    }
};


#endif
