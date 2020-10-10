---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/mod-int.hpp
    title: "\u5270\u4F59\u74B0 / \u4F53"
  - icon: ':heavy_check_mark:'
    path: mathematics/partition-table.hpp
    title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=ja\"\
    \n#line 1 \"mathematics/partition-table.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ T> std::vector<std::vector<T>> partition_table(int n, int k) {\n    std::vector\
    \ ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0] = 1;\n    for (int i = 0;\
    \ i <= n; i++) {\n        for (int j = 1; j <= k; j++) {\n            ret[i][j]\
    \ = ret[i][j - 1];\n            if (j <= i) { ret[i][j] += ret[i - j][j]; }\n\
    \        }\n    }\n    return ret;\n}\n#line 1 \"mathematics/mod-int.hpp\"\n#include\
    \ <iostream>\n#include <utility>\n#line 4 \"mathematics/mod-int.hpp\"\n#include\
    \ <cassert>\n\ntemplate<int MOD = 1000000007>\nstruct mod_int {\n    int v;\n\
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
    \ os << a.v; }\n};\n\ntemplate<int &MOD>\nstruct runtime_mod_int {\n    int v;\n\
    \    runtime_mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD;\
    \ }}\n    static int mod() { return MOD; }\n    int val() const { return v; }\n\
    \    runtime_mod_int &operator+=(const runtime_mod_int &a) {\n        if ((v +=\
    \ a.v) >= MOD) { v -= MOD; }\n        return *this;\n    }\n    runtime_mod_int\
    \ &operator-=(const runtime_mod_int &a) {\n        if ((v += MOD - a.v) >= MOD)\
    \ { v -= MOD; }\n        return *this;\n    }\n    runtime_mod_int &operator*=(const\
    \ runtime_mod_int &a) {\n        v = (int) ((long long) v * a.v % MOD);\n    \
    \    return *this;\n    }\n    runtime_mod_int &operator/=(const runtime_mod_int\
    \ &a) { return *this *= a.inv(); }\n    runtime_mod_int operator+() const { return\
    \ *this; }\n    runtime_mod_int operator-() const { return -v; }\n    runtime_mod_int\
    \ operator++() { return *this += 1; }\n    runtime_mod_int operator--() { return\
    \ *this -= 1; }\n    runtime_mod_int operator++(signed) {\n        const runtime_mod_int\
    \ ret(*this);\n        ++*this;\n        return ret;\n    }\n    runtime_mod_int\
    \ operator--(signed) {\n        const runtime_mod_int ret(*this);\n        --*this;\n\
    \        return ret;\n    }\n    runtime_mod_int inv() const {\n        int a\
    \ = v, b = MOD, x = 1, u = 0;\n        while (b) {\n            int t = a / b;\n\
    \            std::swap(a -= t * b, b), std::swap(x -= t * u, u);\n        }\n\
    \        return x;\n    }\n    runtime_mod_int pow(long long n) const {\n    \
    \    if (n < 0) { return pow(-n).inv(); }\n        runtime_mod_int ret = 1, mul\
    \ = *this;\n        while (n) {\n            if (n & 1) { ret *= mul; }\n    \
    \        mul *= mul, n >>= 1;\n        }\n        return ret;\n    }\n    friend\
    \ bool operator==(const runtime_mod_int &a, const runtime_mod_int &b) { return\
    \ a.v == b.v; }\n    friend bool operator!=(const runtime_mod_int &a, const runtime_mod_int\
    \ &b) {\n        return std::rel_ops::operator!=(a, b);\n    }\n    friend runtime_mod_int\
    \ operator+(runtime_mod_int a, const runtime_mod_int &b) { return a += b; }\n\
    \    friend runtime_mod_int operator-(runtime_mod_int a, const runtime_mod_int\
    \ &b) { return a -= b; }\n    friend runtime_mod_int operator*(runtime_mod_int\
    \ a, const runtime_mod_int &b) { return a *= b; }\n    friend runtime_mod_int\
    \ operator/(runtime_mod_int a, const runtime_mod_int &b) { return a /= b; }\n\
    \    friend std::istream &operator>>(std::istream &is, runtime_mod_int &a) {\n\
    \        long long v;\n        is >> v, a = v;\n        return is;\n    }\n  \
    \  friend std::ostream &operator<<(std::ostream &os, const runtime_mod_int &a)\
    \ { return os << a.v; }\n};\n\ntemplate<typename T>\nstruct combination {\n  \
    \  std::vector<T> fact, finv, inv;\n    combination(int n) : fact(n + 1), finv(n\
    \ + 1), inv(n + 1) {\n        fact[0] = fact[1] = finv[0] = finv[1] = inv[1] =\
    \ 1;\n        for (int i = 2; i <= n; i++) {\n            fact[i] = fact[i - 1]\
    \ * i;\n            inv[i] = -inv[T::mod() % i] * (T::mod() / i);\n          \
    \  finv[i] = finv[i - 1] * inv[i];\n        }\n    }\n    T P(int n, int r) {\
    \ return r < 0 || n < r ? 0 : (fact[n] * finv[n - r]); }\n    T C(int n, int r)\
    \ { return P(n, r) * finv[r]; }\n    T H(int n, int r) { return C(n + r - 1, r);\
    \ }\n    T catalan(int n) { return C(2 * n, n) * inv[n + 1]; }\n};\n#line 4 \"\
    test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int n, k;\n    cin >> n >> k;\n    cout\
    \ << partition_table<mod_int<>>(n, k)[n][k] << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=ja\"\
    \n#include \"../../../mathematics/partition-table.hpp\"\n#include \"../../../mathematics/mod-int.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n,\
    \ k;\n    cin >> n >> k;\n    cout << partition_table<mod_int<>>(n, k)[n][k] <<\
    \ endl;\n}"
  dependsOn:
  - mathematics/partition-table.hpp
  - mathematics/mod-int.hpp
  isVerificationFile: true
  path: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 19:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
- /verify/test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp.html
title: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
---
