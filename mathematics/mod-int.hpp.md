---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mathematics/convolute.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
    title: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/mod-int.test.cpp
    title: test/unit-test/mathematics/mod-int.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/matrix.test.cpp
    title: test/unit-test/mathematics/matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/Power-0.test.cpp
    title: test/AOJ/NTL/Power-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/mod-int.hpp\"\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n#include <cassert>\n\ntemplate<int MOD = 1'000'000'007>\n\
    struct mod_int {\n    int v;\n    mod_int(long long v_ = 0) : v(v_ % MOD) { if\
    \ (v < 0) { v += MOD; }}\n    static int mod() { return MOD; }\n    int val()\
    \ const { return v; }\n    mod_int &operator+=(const mod_int &a) {\n        if\
    \ ((v += a.v) >= MOD) { v -= MOD; }\n        return *this;\n    }\n    mod_int\
    \ &operator-=(const mod_int &a) {\n        if ((v += MOD - a.v) >= MOD) { v -=\
    \ MOD; }\n        return *this;\n    }\n    mod_int &operator*=(const mod_int\
    \ &a) {\n        v = (int) ((long long) v * a.v % MOD);\n        return *this;\n\
    \    }\n    mod_int &operator/=(const mod_int &a) { return *this *= a.inv(); }\n\
    \    mod_int operator+() const { return *this; }\n    mod_int operator-() const\
    \ { return -v; }\n    mod_int operator++() { return *this += 1; }\n    mod_int\
    \ operator--() { return *this -= 1; }\n    mod_int operator++(signed) {\n    \
    \    const mod_int ret(*this);\n        ++*this;\n        return ret;\n    }\n\
    \    mod_int operator--(signed) {\n        const mod_int ret(*this);\n       \
    \ --*this;\n        return ret;\n    }\n    mod_int inv() const {\n        int\
    \ a = v, b = MOD, x = 1, u = 0;\n        while (b) {\n            int t = a /\
    \ b;\n            std::swap(a -= t * b, b), std::swap(x -= t * u, u);\n      \
    \  }\n        return x;\n    }\n    mod_int pow(long long n) const {\n       \
    \ if (n < 0) { return pow(-n).inv(); }\n        mod_int ret = 1, mul = *this;\n\
    \        while (n) {\n            if (n & 1) { ret *= mul; }\n            mul\
    \ *= mul, n >>= 1;\n        }\n        return ret;\n    }\n    friend bool operator==(const\
    \ mod_int &a, const mod_int &b) { return a.v == b.v; }\n    friend bool operator!=(const\
    \ mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a, b); }\n \
    \   friend mod_int operator+(mod_int a, const mod_int &b) { return a += b; }\n\
    \    friend mod_int operator-(mod_int a, const mod_int &b) { return a -= b; }\n\
    \    friend mod_int operator*(mod_int a, const mod_int &b) { return a *= b; }\n\
    \    friend mod_int operator/(mod_int a, const mod_int &b) { return a /= b; }\n\
    \    friend std::istream &operator>>(std::istream &is, mod_int &a) {\n       \
    \ long long v;\n        is >> v, a = v;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const mod_int &a) { return os <<\
    \ a.v; }\n};\n\ntemplate<typename T>\nstruct combination {\n    std::vector<T>\
    \ fact, fact_inv, inv;\n    combination(int n) : fact(n + 1), fact_inv(n + 1),\
    \ inv(n + 1) {\n        fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = inv[1]\
    \ = 1;\n        for (int i = 2; i <= n; i++) {\n            fact[i] = fact[i -\
    \ 1] * i;\n            inv[i] = -inv[T::mod() % i] * (T::mod() / i);\n       \
    \     fact_inv[i] = fact_inv[i - 1] * inv[i];\n        }\n    }\n    T P(int n,\
    \ int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[n - r]); }\n    T C(int\
    \ n, int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[r] * fact_inv[n\
    \ - r]); }\n    T H(int n, int r) { return C(n + r - 1, r); }\n};\n"
  code: "#include <iostream>\n#include <utility>\n#include <vector>\n#include <cassert>\n\
    \ntemplate<int MOD = 1'000'000'007>\nstruct mod_int {\n    int v;\n    mod_int(long\
    \ long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}\n    static int mod()\
    \ { return MOD; }\n    int val() const { return v; }\n    mod_int &operator+=(const\
    \ mod_int &a) {\n        if ((v += a.v) >= MOD) { v -= MOD; }\n        return\
    \ *this;\n    }\n    mod_int &operator-=(const mod_int &a) {\n        if ((v +=\
    \ MOD - a.v) >= MOD) { v -= MOD; }\n        return *this;\n    }\n    mod_int\
    \ &operator*=(const mod_int &a) {\n        v = (int) ((long long) v * a.v % MOD);\n\
    \        return *this;\n    }\n    mod_int &operator/=(const mod_int &a) { return\
    \ *this *= a.inv(); }\n    mod_int operator+() const { return *this; }\n    mod_int\
    \ operator-() const { return -v; }\n    mod_int operator++() { return *this +=\
    \ 1; }\n    mod_int operator--() { return *this -= 1; }\n    mod_int operator++(signed)\
    \ {\n        const mod_int ret(*this);\n        ++*this;\n        return ret;\n\
    \    }\n    mod_int operator--(signed) {\n        const mod_int ret(*this);\n\
    \        --*this;\n        return ret;\n    }\n    mod_int inv() const {\n   \
    \     int a = v, b = MOD, x = 1, u = 0;\n        while (b) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b), std::swap(x -= t * u, u);\n\
    \        }\n        return x;\n    }\n    mod_int pow(long long n) const {\n \
    \       if (n < 0) { return pow(-n).inv(); }\n        mod_int ret = 1, mul = *this;\n\
    \        while (n) {\n            if (n & 1) { ret *= mul; }\n            mul\
    \ *= mul, n >>= 1;\n        }\n        return ret;\n    }\n    friend bool operator==(const\
    \ mod_int &a, const mod_int &b) { return a.v == b.v; }\n    friend bool operator!=(const\
    \ mod_int &a, const mod_int &b) { return std::rel_ops::operator!=(a, b); }\n \
    \   friend mod_int operator+(mod_int a, const mod_int &b) { return a += b; }\n\
    \    friend mod_int operator-(mod_int a, const mod_int &b) { return a -= b; }\n\
    \    friend mod_int operator*(mod_int a, const mod_int &b) { return a *= b; }\n\
    \    friend mod_int operator/(mod_int a, const mod_int &b) { return a /= b; }\n\
    \    friend std::istream &operator>>(std::istream &is, mod_int &a) {\n       \
    \ long long v;\n        is >> v, a = v;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const mod_int &a) { return os <<\
    \ a.v; }\n};\n\ntemplate<typename T>\nstruct combination {\n    std::vector<T>\
    \ fact, fact_inv, inv;\n    combination(int n) : fact(n + 1), fact_inv(n + 1),\
    \ inv(n + 1) {\n        fact[0] = fact[1] = fact_inv[0] = fact_inv[1] = inv[1]\
    \ = 1;\n        for (int i = 2; i <= n; i++) {\n            fact[i] = fact[i -\
    \ 1] * i;\n            inv[i] = -inv[T::mod() % i] * (T::mod() / i);\n       \
    \     fact_inv[i] = fact_inv[i - 1] * inv[i];\n        }\n    }\n    T P(int n,\
    \ int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[n - r]); }\n    T C(int\
    \ n, int r) { return r < 0 || n < r ? 0 : (fact[n] * fact_inv[r] * fact_inv[n\
    \ - r]); }\n    T H(int n, int r) { return C(n + r - 1, r); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/mod-int.hpp
  requiredBy:
  - mathematics/convolute.hpp
  timestamp: '2020-09-28 19:18:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - test/unit-test/mathematics/mod-int.test.cpp
  - test/unit-test/mathematics/matrix.test.cpp
  - test/AOJ/NTL/Power-0.test.cpp
documentation_of: mathematics/mod-int.hpp
layout: document
title: "\u5270\u4F59\u74B0 / \u4F53"
---

## 概要
演算時に自動で剰余をとる整数。

## テンプレートパラメータ
- `int MOD = 1000000007`  
法。

## 内部クラス
- `combination`  
組み合わせ計算のための機能を持つ。