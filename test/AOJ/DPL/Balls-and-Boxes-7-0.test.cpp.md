---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mathematics/bell-number-table.hpp
    title: mathematics/bell-number-table.hpp
  - icon: ':question:'
    path: mathematics/mod-int.hpp
    title: "\u5270\u4F59\u74B0 / \u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=ja\"\
    \n#line 1 \"mathematics/bell-number-table.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ T> std::vector<std::vector<T>> bell_number_table(int n, int k) {\n    std::vector\
    \ ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0] = 1;\n    for (int i = 1;\
    \ i <= n; i++) {\n        ret[i][1] = 1;\n        for (int j = 2; j <= i && j\
    \ <= k; j++) { ret[i][j] = ret[i][j - 1] + ret[i - 1][j - 1] + j * ret[i - 1][j];\
    \ }\n    }\n    return ret;\n}\n#line 1 \"mathematics/mod-int.hpp\"\n#include\
    \ <iostream>\n#include <utility>\n#line 4 \"mathematics/mod-int.hpp\"\n#include\
    \ <cassert>\n\ntemplate<int MOD = 1'000'000'007>\nstruct mod_int {\n    int v;\n\
    \    mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}\n   \
    \ static int mod() { return MOD; }\n    int val() const { return v; }\n    mod_int\
    \ &operator+=(const mod_int &a) {\n        if ((v += a.v) >= MOD) { v -= MOD;\
    \ }\n        return *this;\n    }\n    mod_int &operator-=(const mod_int &a) {\n\
    \        if ((v += MOD - a.v) >= MOD) { v -= MOD; }\n        return *this;\n \
    \   }\n    mod_int &operator*=(const mod_int &a) {\n        v = (int) ((long long)\
    \ v * a.v % MOD);\n        return *this;\n    }\n    mod_int &operator/=(const\
    \ mod_int &a) { return *this *= a.inv(); }\n    mod_int operator+() const { return\
    \ *this; }\n    mod_int operator-() const { return -v; }\n    mod_int operator++()\
    \ { return *this += 1; }\n    mod_int operator--() { return *this -= 1; }\n  \
    \  mod_int operator++(signed) {\n        const mod_int ret(*this);\n        ++*this;\n\
    \        return ret;\n    }\n    mod_int operator--(signed) {\n        const mod_int\
    \ ret(*this);\n        --*this;\n        return ret;\n    }\n    mod_int inv()\
    \ const {\n        int a = v, b = MOD, x = 1, u = 0;\n        while (b) {\n  \
    \          int t = a / b;\n            std::swap(a -= t * b, b), std::swap(x -=\
    \ t * u, u);\n        }\n        return x;\n    }\n    mod_int pow(long long n)\
    \ const {\n        if (n < 0) { return pow(-n).inv(); }\n        mod_int ret =\
    \ 1, mul = *this;\n        while (n) {\n            if (n & 1) { ret *= mul; }\n\
    \            mul *= mul, n >>= 1;\n        }\n        return ret;\n    }\n   \
    \ friend bool operator==(const mod_int &a, const mod_int &b) { return a.v == b.v;\
    \ }\n    friend bool operator!=(const mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a,\
    \ b); }\n    friend mod_int operator+(mod_int a, const mod_int &b) { return a\
    \ += b; }\n    friend mod_int operator-(mod_int a, const mod_int &b) { return\
    \ a -= b; }\n    friend mod_int operator*(mod_int a, const mod_int &b) { return\
    \ a *= b; }\n    friend mod_int operator/(mod_int a, const mod_int &b) { return\
    \ a /= b; }\n    friend std::istream &operator>>(std::istream &is, mod_int &a)\
    \ {\n        long long v;\n        is >> v, a = v;\n        return is;\n    }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const mod_int &a) { return\
    \ os << a.v; }\n};\n\ntemplate<typename T>\nstruct combination {\n    std::vector<T>\
    \ fact, fact_inv, inv;\n    combination(int n) : fact(n + 1), fact_inv(n + 1),\
    \ inv(n + 1) {\n        fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = inv[1]\
    \ = 1;\n        for (int i = 2; i <= n; i++) {\n            fact[i] = fact[i -\
    \ 1] * i;\n            inv[i] = -inv[T::mod() % i] * (T::mod() / i);\n       \
    \     fact_inv[i] = fact_inv[i - 1] * inv[i];\n        }\n    }\n    T P(int n,\
    \ int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[n - r]); }\n    T C(int\
    \ n, int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[r] * fact_inv[n\
    \ - r]); }\n    T H(int n, int r) { return C(n + r - 1, r); }\n};\n#line 4 \"\
    test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int n, k;\n    cin >> n >> k;\n    cout\
    \ << bell_number_table<mod_int<>>(n, k)[n][k] << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=ja\"\
    \n#include \"../../../mathematics/bell-number-table.hpp\"\n#include \"../../../mathematics/mod-int.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n,\
    \ k;\n    cin >> n >> k;\n    cout << bell_number_table<mod_int<>>(n, k)[n][k]\
    \ << endl;\n}"
  dependsOn:
  - mathematics/bell-number-table.hpp
  - mathematics/mod-int.hpp
  isVerificationFile: true
  path: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
  requiredBy: []
  timestamp: '2020-10-01 10:04:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
- /verify/test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp.html
title: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
---
