#ifndef INF21307_TP2_MYFIXED_HPP
#define INF21307_TP2_MYFIXED_HPP

#include <ostream>

template <typename T, unsigned int P>
class MyFixed {
public:
    explicit MyFixed(float input) {
        data = toFixed(input);
    }

    explicit MyFixed(T input) {
        data = input;
    }

    T data;
private:

    static T toFixed(float f) {
        return f * (float)(1 << P);
    }

    float toFloat() const {
        return (float)data / (float)(1 << P);
    }

public:
    friend MyFixed operator +(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        return MyFixed<T, P>((T) (lhs.data + rhs.data));
    }

    friend MyFixed operator -(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        return MyFixed<T, P>((T) (lhs.data - rhs.data));
    }

    friend MyFixed operator *(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        size_t offset = (P / 2);
        T a = (lhs.data >> offset);
        T b = (rhs.data >> offset);
        T r = (a * b) >> (P - (offset * 2));

        return MyFixed<T, P>(r);
    }

    friend MyFixed operator /(const MyFixed<T, P> &lhs, const MyFixed<T, P> &rhs) {
        size_t offset = (P / 2);
        T a = (lhs.data >> offset);
        T b = (rhs.data >> offset);
        T r = (a / b) >> (P - (offset * 2));

        return MyFixed<T, P>(r);
    }

    friend bool operator ==(const MyFixed &lhs, const MyFixed &rhs) {
        return lhs.data == rhs.data;
    }

    friend bool operator !=(const MyFixed &lhs, const MyFixed &rhs) {
        return !(rhs == lhs);
    }

    friend std::ostream &operator <<(std::ostream &os, const MyFixed<T, P> &f) {
        os << f.toFloat();
        return os;
    }

    explicit operator float () const {
        return toFloat();
    }
};


#endif
