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
    links: []
  bundledCode: "#line 1 \"mathematics/rational.hpp\"\n#include <iostream>\n#include\
    \ <utility>\n\nstruct rational {\n    long long num, den;\n    static long long\
    \ gcd(long long a, long long b) {\n        if (a < 0) { a = -a; }\n        if\
    \ (b < 0) { b = -b; }\n        while (b) { std::swap(a %= b, b); }\n        return\
    \ a;\n    }\n    void reduce() {\n        long long g = gcd(num, den);\n     \
    \   num /= g, den /= g;\n    }\n    rational(long long num_ = 0, long long den_\
    \ = 1, bool reduction = true) : num(num_), den(den_) {\n        if (reduction)\
    \ { reduce(); }\n        if (den < 0) { num = -num, den = -den; }\n    }\n   \
    \ rational &operator+=(const rational &a) {\n        num = num * a.den + a.num\
    \ * den, den *= a.den;\n        reduce();\n        return *this;\n    }\n    rational\
    \ &operator-=(const rational &a) { return *this += -a; }\n    rational &operator*=(const\
    \ rational &a) {\n        num *= a.num, den *= a.den;\n        reduce();\n   \
    \     return *this;\n    }\n    rational &operator/=(const rational &a) { return\
    \ *this *= a.inv(); }\n    rational operator+() const { return *this; }\n    rational\
    \ operator-() const { return rational(-num, den, false); }\n    friend bool operator==(const\
    \ rational &a, const rational &b) { return a.num == b.num && a.den == b.den; }\n\
    \    friend bool operator!=(const rational &a, const rational &b) { return std::rel_ops::operator!=(a,\
    \ b); }\n    friend bool operator<(const rational &a, const rational &b) { return\
    \ a.num * b.den < b.num * a.den; }\n    friend bool operator>(const rational &a,\
    \ const rational &b) { return std::rel_ops::operator>(a, b); }\n    friend bool\
    \ operator<=(const rational &a, const rational &b) { return std::rel_ops::operator<=(a,\
    \ b); }\n    friend bool operator>=(const rational &a, const rational &b) { return\
    \ std::rel_ops::operator>=(a, b); }\n    friend rational operator+(rational a,\
    \ const rational &b) { return a += b; }\n    friend rational operator-(rational\
    \ a, const rational &b) { return a -= b; }\n    friend rational operator*(rational\
    \ a, const rational &b) { return a *= b; }\n    friend rational operator/(rational\
    \ a, const rational &b) { return a /= b; }\n    rational inv() const { return\
    \ rational(den, num, false); }\n    rational pow(long long n) const {\n      \
    \  if (n < 0) { return pow(-n).inv(); }\n        rational ret(1, 1, false), mul\
    \ = *this;\n        while (n > 0) {\n            if (n & 1) { ret.num *= mul.num,\
    \ ret.den *= mul.den; }\n            mul.num *= mul.num, mul.den *= mul.den;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n    double to_double()\
    \ const { return (double) num / den; }\n    friend std::istream &operator>>(std::istream\
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
    \ den = -den; }\n    }\n    rational &operator+=(const rational &a) {\n      \
    \  num = num * a.den + a.num * den, den *= a.den;\n        reduce();\n       \
    \ return *this;\n    }\n    rational &operator-=(const rational &a) { return *this\
    \ += -a; }\n    rational &operator*=(const rational &a) {\n        num *= a.num,\
    \ den *= a.den;\n        reduce();\n        return *this;\n    }\n    rational\
    \ &operator/=(const rational &a) { return *this *= a.inv(); }\n    rational operator+()\
    \ const { return *this; }\n    rational operator-() const { return rational(-num,\
    \ den, false); }\n    friend bool operator==(const rational &a, const rational\
    \ &b) { return a.num == b.num && a.den == b.den; }\n    friend bool operator!=(const\
    \ rational &a, const rational &b) { return std::rel_ops::operator!=(a, b); }\n\
    \    friend bool operator<(const rational &a, const rational &b) { return a.num\
    \ * b.den < b.num * a.den; }\n    friend bool operator>(const rational &a, const\
    \ rational &b) { return std::rel_ops::operator>(a, b); }\n    friend bool operator<=(const\
    \ rational &a, const rational &b) { return std::rel_ops::operator<=(a, b); }\n\
    \    friend bool operator>=(const rational &a, const rational &b) { return std::rel_ops::operator>=(a,\
    \ b); }\n    friend rational operator+(rational a, const rational &b) { return\
    \ a += b; }\n    friend rational operator-(rational a, const rational &b) { return\
    \ a -= b; }\n    friend rational operator*(rational a, const rational &b) { return\
    \ a *= b; }\n    friend rational operator/(rational a, const rational &b) { return\
    \ a /= b; }\n    rational inv() const { return rational(den, num, false); }\n\
    \    rational pow(long long n) const {\n        if (n < 0) { return pow(-n).inv();\
    \ }\n        rational ret(1, 1, false), mul = *this;\n        while (n > 0) {\n\
    \            if (n & 1) { ret.num *= mul.num, ret.den *= mul.den; }\n        \
    \    mul.num *= mul.num, mul.den *= mul.den;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n    double to_double() const { return (double) num\
    \ / den; }\n    friend std::istream &operator>>(std::istream &is, rational &rhs)\
    \ {\n        long long n, d;\n        char s;\n        is >> n >> s >> d;\n  \
    \      rhs = rational(n, d);\n        return is;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const rational &rhs) {\n        return os << rhs.num\
    \ << \" / \" << rhs.den;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/rational.hpp
  requiredBy: []
  timestamp: '2020-09-28 19:18:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/rational.test.cpp
documentation_of: mathematics/rational.hpp
layout: document
title: "\u6709\u7406\u6570"
---

