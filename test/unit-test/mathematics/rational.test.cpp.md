---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mathematics/rational.hpp
    title: "\u5B9F\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/mathematics/rational.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/rational.hpp\"\n#include <iostream>\n#include <utility>\n\
    \nstruct rational {\n    long long num, den;\n    static long long gcd(long long\
    \ a, long long b) {\n        if (a < 0) { a = -a; }\n        if (b < 0) { b =\
    \ -b; }\n        while (b) { std::swap(a %= b, b); }\n        return a;\n    }\n\
    \    void reduce() {\n        long long g = gcd(num, den);\n        num /= g,\
    \ den /= g;\n    }\n    rational(long long num_ = 0, long long den_ = 1, bool\
    \ reduction = true) : num(num_), den(den_) {\n        if (reduction) { reduce();\
    \ }\n        if (den < 0) { num = -num, den = -den; }\n    }\n    bool operator==(const\
    \ rational &rhs) const { return num == rhs.num && den == rhs.den; }\n    bool\
    \ operator!=(const rational &rhs) const { return std::rel_ops::operator!=(*this,\
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
    \        return os << rhs.num << \" / \" << rhs.den;\n    }\n};\n#line 3 \"test/unit-test/mathematics/rational.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    assert(rational()\
    \ == rational(0));\n    assert(rational(3340, 810) == rational(334, 81));\n  \
    \  assert(rational(-1, 2) == rational(1, -2));\n    assert(rational(1, 3) + rational(1,\
    \ 6) == rational(1, 2));\n    assert(rational(1, 2) - rational(1, 3) == rational(1,\
    \ 6));\n    assert(rational(1, 2) - rational(1, 3) == rational(1, 6));\n    assert(rational(100,\
    \ 200) * rational(400, 300) == rational(2, 3));\n    assert(rational(100, 200)\
    \ / rational(300, 400) == rational(2, 3));\n    assert(rational(3, 4) > rational(200,\
    \ 300));\n    assert(rational(200, 300) < rational(3, 4));\n    assert(rational(2,\
    \ 3).pow(4) == rational(16, 81));\n    assert(rational(-1, 1).pow(3) == rational(-1,\
    \ 1));\n    assert(rational(2, 1).pow(30) < rational(3, 1).pow(20));\n    assert(rational(1,\
    \ 4).to_double() == 0.25);\n\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/rational.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    assert(rational() == rational(0));\n   \
    \ assert(rational(3340, 810) == rational(334, 81));\n    assert(rational(-1, 2)\
    \ == rational(1, -2));\n    assert(rational(1, 3) + rational(1, 6) == rational(1,\
    \ 2));\n    assert(rational(1, 2) - rational(1, 3) == rational(1, 6));\n    assert(rational(1,\
    \ 2) - rational(1, 3) == rational(1, 6));\n    assert(rational(100, 200) * rational(400,\
    \ 300) == rational(2, 3));\n    assert(rational(100, 200) / rational(300, 400)\
    \ == rational(2, 3));\n    assert(rational(3, 4) > rational(200, 300));\n    assert(rational(200,\
    \ 300) < rational(3, 4));\n    assert(rational(2, 3).pow(4) == rational(16, 81));\n\
    \    assert(rational(-1, 1).pow(3) == rational(-1, 1));\n    assert(rational(2,\
    \ 1).pow(30) < rational(3, 1).pow(20));\n    assert(rational(1, 4).to_double()\
    \ == 0.25);\n\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - mathematics/rational.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/rational.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit-test/mathematics/rational.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/rational.test.cpp
- /verify/test/unit-test/mathematics/rational.test.cpp.html
title: test/unit-test/mathematics/rational.test.cpp
---
