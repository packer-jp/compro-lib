---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/rational.test.cpp
    title: test/unit-test/mathematics/rational.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/rational.hpp\"\n#include <iostream>\n#include\
    \ <utility>\n\nstruct rational {\n    long long num, den;\n    static long long\
    \ gcd(long long a, long long b) {\n        if (a < 0) { a = -a; }\n        if\
    \ (b < 0) { b = -b; }\n        while (b) { std::swap(a %= b, b); }\n        return\
    \ a;\n    }\n    void reduce() {\n        long long g = gcd(num, den);\n     \
    \   num /= g, den /= g;\n    }\n    rational(long long num_ = 0, long long den_\
    \ = 1, bool reduction = true) : num(num_), den(den_) {\n        if (reduction)\
    \ { reduce(); }\n        if (den < 0) { num = -num, den = -den; }\n    }\n   \
    \ bool operator==(const rational &rhs) const { return num == rhs.num && den ==\
    \ rhs.den; }\n    bool operator!=(const rational &rhs) const { return std::rel_ops::operator!=(*this,\
    \ rhs); }\n    bool operator<(const rational &rhs) const { return num * rhs.den\
    \ < rhs.num * den; }\n    bool operator>(const rational &rhs) const { return std::rel_ops::operator>(*this,\
    \ rhs); }\n    bool operator<=(const rational &rhs) const { return std::rel_ops::operator<=(*this,\
    \ rhs); }\n    bool operator>=(const rational &rhs) const { return std::rel_ops::operator>=(*this,\
    \ rhs); }\n    rational &operator+=(const rational &rhs) {\n        num = num\
    \ * rhs.den + rhs.num * den, den *= rhs.den;\n        reduce();\n        return\
    \ *this;\n    }\n    rational &operator-=(const rational &rhs) { return *this\
    \ += -rhs; }\n    rational &operator*=(const rational &rhs) {\n        num *=\
    \ rhs.num, den *= rhs.den;\n        reduce();\n        return *this;\n    }\n\
    \    rational &operator/=(const rational &rhs) { return *this *= rhs.inv(); }\n\
    \    rational operator+() const { return *this; }\n    rational operator-() const\
    \ { return rational(-num, den, false); }\n    rational operator+(const rational\
    \ &rhs) const { return rational(*this) += rhs; }\n    rational operator-(const\
    \ rational &rhs) const { return rational(*this) -= rhs; }\n    rational operator*(const\
    \ rational &rhs) const { return rational(*this) *= rhs; }\n    rational operator/(const\
    \ rational &rhs) const { return rational(*this) /= rhs; }\n    rational inv()\
    \ const { return rational(den, num, false); }\n    rational pow(long long n) const\
    \ {\n        if (n < 0) { return pow(-n).inv(); }\n        rational ret(1, 1,\
    \ false), mul = *this;\n        while (n > 0) {\n            if (n & 1) { ret.num\
    \ *= mul.num, ret.den *= mul.den; }\n            mul.num *= mul.num, mul.den *=\
    \ mul.den;\n            n >>= 1;\n        }\n        return ret;\n    }\n    double\
    \ to_double() const { return (double) num / den; }\n    friend std::istream &operator>>(std::istream\
    \ &is, rational &rhs) {\n        long long n, d;\n        char s;\n        is\
    \ >> n >> s >> d;\n        rhs = rational(n, d);\n        return is;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const rational &rhs) {\n\
    \        return os << rhs.num << \" / \" << rhs.den;\n    }\n};\n"
  code: "#include <iostream>\n#include <utility>\n\nstruct rational {\n    long long\
    \ num, den;\n    static long long gcd(long long a, long long b) {\n        if\
    \ (a < 0) { a = -a; }\n        if (b < 0) { b = -b; }\n        while (b) { std::swap(a\
    \ %= b, b); }\n        return a;\n    }\n    void reduce() {\n        long long\
    \ g = gcd(num, den);\n        num /= g, den /= g;\n    }\n    rational(long long\
    \ num_ = 0, long long den_ = 1, bool reduction = true) : num(num_), den(den_)\
    \ {\n        if (reduction) { reduce(); }\n        if (den < 0) { num = -num,\
    \ den = -den; }\n    }\n    bool operator==(const rational &rhs) const { return\
    \ num == rhs.num && den == rhs.den; }\n    bool operator!=(const rational &rhs)\
    \ const { return std::rel_ops::operator!=(*this, rhs); }\n    bool operator<(const\
    \ rational &rhs) const { return num * rhs.den < rhs.num * den; }\n    bool operator>(const\
    \ rational &rhs) const { return std::rel_ops::operator>(*this, rhs); }\n    bool\
    \ operator<=(const rational &rhs) const { return std::rel_ops::operator<=(*this,\
    \ rhs); }\n    bool operator>=(const rational &rhs) const { return std::rel_ops::operator>=(*this,\
    \ rhs); }\n    rational &operator+=(const rational &rhs) {\n        num = num\
    \ * rhs.den + rhs.num * den, den *= rhs.den;\n        reduce();\n        return\
    \ *this;\n    }\n    rational &operator-=(const rational &rhs) { return *this\
    \ += -rhs; }\n    rational &operator*=(const rational &rhs) {\n        num *=\
    \ rhs.num, den *= rhs.den;\n        reduce();\n        return *this;\n    }\n\
    \    rational &operator/=(const rational &rhs) { return *this *= rhs.inv(); }\n\
    \    rational operator+() const { return *this; }\n    rational operator-() const\
    \ { return rational(-num, den, false); }\n    rational operator+(const rational\
    \ &rhs) const { return rational(*this) += rhs; }\n    rational operator-(const\
    \ rational &rhs) const { return rational(*this) -= rhs; }\n    rational operator*(const\
    \ rational &rhs) const { return rational(*this) *= rhs; }\n    rational operator/(const\
    \ rational &rhs) const { return rational(*this) /= rhs; }\n    rational inv()\
    \ const { return rational(den, num, false); }\n    rational pow(long long n) const\
    \ {\n        if (n < 0) { return pow(-n).inv(); }\n        rational ret(1, 1,\
    \ false), mul = *this;\n        while (n > 0) {\n            if (n & 1) { ret.num\
    \ *= mul.num, ret.den *= mul.den; }\n            mul.num *= mul.num, mul.den *=\
    \ mul.den;\n            n >>= 1;\n        }\n        return ret;\n    }\n    double\
    \ to_double() const { return (double) num / den; }\n    friend std::istream &operator>>(std::istream\
    \ &is, rational &rhs) {\n        long long n, d;\n        char s;\n        is\
    \ >> n >> s >> d;\n        rhs = rational(n, d);\n        return is;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const rational &rhs) {\n\
    \        return os << rhs.num << \" / \" << rhs.den;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/rational.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/rational.test.cpp
documentation_of: mathematics/rational.hpp
layout: document
redirect_from:
- /library/mathematics/rational.hpp
- /library/mathematics/rational.hpp.html
title: mathematics/rational.hpp
---
