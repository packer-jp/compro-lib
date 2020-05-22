#include <iostream>
#include <utility>

/*
 * @title 有理数
 * @docs docs/mathematics/rational.md
 */

struct rational {
    long long num, den;
    static long long gcd(long long a, long long b) {
        if (a < 0) { a = -a; }
        if (b < 0) { b = b; }
        while (b) { std::swap(a %= b, b); }
        return a;
    }
    void reduce() {
        long long g = gcd(num, den);
        num /= g, den /= g;
    }
    rational(long long num_ = 0, long long den_ = 1, bool reduction = true) : num(num_), den(den_) {
        if (reduction) { reduce(); }
        if (den < 0) { num = -num, den = -den; }
    }
    bool operator==(const rational &rhs) const { return num == rhs.num && den == rhs.den; }
    bool operator!=(const rational &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    bool operator<(const rational &rhs) const { return num * rhs.den < rhs.num * den; }
    bool operator>(const rational &rhs) const { return std::rel_ops::operator>(*this, rhs); }
    bool operator<=(const rational &rhs) const { return std::rel_ops::operator<=(*this, rhs); }
    bool operator>=(const rational &rhs) const { return std::rel_ops::operator>=(*this, rhs); }
    rational &operator+=(const rational &rhs) {
        num = num * rhs.den + rhs.num * den, den *= rhs.den;
        reduce();
        return *this;
    }
    rational &operator-=(const rational &rhs) { return *this += -rhs; }
    rational &operator*=(const rational &rhs) {
        num *= rhs.num, den *= rhs.den;
        reduce();
        return *this;
    }
    rational &operator/=(const rational &rhs) { return *this *= rhs.inv(); }
    rational operator+() const { return *this; }
    rational operator-() const { return rational(-num, den, false); }
    rational operator+(const rational &rhs) const { return rational(*this) += rhs; }
    rational operator-(const rational &rhs) const { return rational(*this) -= rhs; }
    rational operator*(const rational &rhs) const { return rational(*this) *= rhs; }
    rational operator/(const rational &rhs) const { return rational(*this) /= rhs; }
    rational inv() const { return rational(den, num, false); }
    rational pow(long long n) const {
        if (n < 0) { return pow(-n).inv(); }
        rational ret(1, 1, false), mul = *this;
        while (n > 0) {
            if (n & 1) { ret.num *= mul.num, ret.den *= mul.den; }
            mul.num *= mul.num, mul.den *= mul.den;
            n >>= 1;
        }
        return ret;
    }
    double to_double() const { return (double) num / den; }
    friend std::istream &operator>>(std::istream &is, rational &rhs) {
        long long n, d;
        char s;
        is >> n >> s >> d;
        rhs = rational(n, d);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const rational &rhs) {
        return os << rhs.num << " / " << rhs.den;
    }
};