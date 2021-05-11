---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mathematics/convolute.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/Power-0.test.cpp
    title: test/AOJ/NTL/Power-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
    title: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/matrix.test.cpp
    title: test/unit-test/mathematics/matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/mod-int.test.cpp
    title: test/unit-test/mathematics/mod-int.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/mod-int.hpp\"\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n#include <cassert>\n\ntemplate<int MOD = 1000000007>\n\
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
    \ a.v; }\n};\n\ntemplate<int &MOD>\nstruct runtime_mod_int {\n    int v;\n   \
    \ runtime_mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}\n\
    \    static int mod() { return MOD; }\n    int val() const { return v; }\n   \
    \ runtime_mod_int &operator+=(const runtime_mod_int &a) {\n        if ((v += a.v)\
    \ >= MOD) { v -= MOD; }\n        return *this;\n    }\n    runtime_mod_int &operator-=(const\
    \ runtime_mod_int &a) {\n        if ((v += MOD - a.v) >= MOD) { v -= MOD; }\n\
    \        return *this;\n    }\n    runtime_mod_int &operator*=(const runtime_mod_int\
    \ &a) {\n        v = (int) ((long long) v * a.v % MOD);\n        return *this;\n\
    \    }\n    runtime_mod_int &operator/=(const runtime_mod_int &a) { return *this\
    \ *= a.inv(); }\n    runtime_mod_int operator+() const { return *this; }\n   \
    \ runtime_mod_int operator-() const { return -v; }\n    runtime_mod_int operator++()\
    \ { return *this += 1; }\n    runtime_mod_int operator--() { return *this -= 1;\
    \ }\n    runtime_mod_int operator++(signed) {\n        const runtime_mod_int ret(*this);\n\
    \        ++*this;\n        return ret;\n    }\n    runtime_mod_int operator--(signed)\
    \ {\n        const runtime_mod_int ret(*this);\n        --*this;\n        return\
    \ ret;\n    }\n    runtime_mod_int inv() const {\n        int a = v, b = MOD,\
    \ x = 1, u = 0;\n        while (b) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b), std::swap(x -= t * u, u);\n        }\n        return\
    \ x;\n    }\n    runtime_mod_int pow(long long n) const {\n        if (n < 0)\
    \ { return pow(-n).inv(); }\n        runtime_mod_int ret = 1, mul = *this;\n \
    \       while (n) {\n            if (n & 1) { ret *= mul; }\n            mul *=\
    \ mul, n >>= 1;\n        }\n        return ret;\n    }\n    friend bool operator==(const\
    \ runtime_mod_int &a, const runtime_mod_int &b) { return a.v == b.v; }\n    friend\
    \ bool operator!=(const runtime_mod_int &a, const runtime_mod_int &b) {\n    \
    \    return std::rel_ops::operator!=(a, b);\n    }\n    friend runtime_mod_int\
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
    \ }\n    T catalan(int n) { return C(2 * n, n) * inv[n + 1]; }\n};\n"
  code: "#include <iostream>\n#include <utility>\n#include <vector>\n#include <cassert>\n\
    \ntemplate<int MOD = 1000000007>\nstruct mod_int {\n    int v;\n    mod_int(long\
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
    \ a.v; }\n};\n\ntemplate<int &MOD>\nstruct runtime_mod_int {\n    int v;\n   \
    \ runtime_mod_int(long long v_ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}\n\
    \    static int mod() { return MOD; }\n    int val() const { return v; }\n   \
    \ runtime_mod_int &operator+=(const runtime_mod_int &a) {\n        if ((v += a.v)\
    \ >= MOD) { v -= MOD; }\n        return *this;\n    }\n    runtime_mod_int &operator-=(const\
    \ runtime_mod_int &a) {\n        if ((v += MOD - a.v) >= MOD) { v -= MOD; }\n\
    \        return *this;\n    }\n    runtime_mod_int &operator*=(const runtime_mod_int\
    \ &a) {\n        v = (int) ((long long) v * a.v % MOD);\n        return *this;\n\
    \    }\n    runtime_mod_int &operator/=(const runtime_mod_int &a) { return *this\
    \ *= a.inv(); }\n    runtime_mod_int operator+() const { return *this; }\n   \
    \ runtime_mod_int operator-() const { return -v; }\n    runtime_mod_int operator++()\
    \ { return *this += 1; }\n    runtime_mod_int operator--() { return *this -= 1;\
    \ }\n    runtime_mod_int operator++(signed) {\n        const runtime_mod_int ret(*this);\n\
    \        ++*this;\n        return ret;\n    }\n    runtime_mod_int operator--(signed)\
    \ {\n        const runtime_mod_int ret(*this);\n        --*this;\n        return\
    \ ret;\n    }\n    runtime_mod_int inv() const {\n        int a = v, b = MOD,\
    \ x = 1, u = 0;\n        while (b) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b), std::swap(x -= t * u, u);\n        }\n        return\
    \ x;\n    }\n    runtime_mod_int pow(long long n) const {\n        if (n < 0)\
    \ { return pow(-n).inv(); }\n        runtime_mod_int ret = 1, mul = *this;\n \
    \       while (n) {\n            if (n & 1) { ret *= mul; }\n            mul *=\
    \ mul, n >>= 1;\n        }\n        return ret;\n    }\n    friend bool operator==(const\
    \ runtime_mod_int &a, const runtime_mod_int &b) { return a.v == b.v; }\n    friend\
    \ bool operator!=(const runtime_mod_int &a, const runtime_mod_int &b) {\n    \
    \    return std::rel_ops::operator!=(a, b);\n    }\n    friend runtime_mod_int\
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
    \ }\n    T catalan(int n) { return C(2 * n, n) * inv[n + 1]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/mod-int.hpp
  requiredBy:
  - mathematics/convolute.hpp
  timestamp: '2020-10-10 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/mod-int.test.cpp
  - test/unit-test/mathematics/matrix.test.cpp
  - test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
  - test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
  - test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
  - test/AOJ/NTL/Power-0.test.cpp
documentation_of: mathematics/mod-int.hpp
layout: document
title: modint
---

- `<int MOD=1'000'000'0007> struct mod_int`  
`MOD`を法とした modint。

  - `(constructor)(long long v_)`  
  値`v_`で初期化。

  - `static int mod()`  
  `MOD`を返す。

  - 各種`operator`  
  演算をする。特に、割り算の可能性・計算量は`inv`メソッドに準拠する。
  
  - `mod_int inv()`  
  逆元を返す。値と`MOD`が互いに素である場合のみ使える。時間計算量`O(log MOD)`。
  
  - `mod_int pow(int n)`  
  `n`乗を返す。時間計算量`O(log n)`。

- `<T> struct combination`  
  組み合わせの計算を行う。`T`は`mod_int`。
  
  - `(constructor)(int n)`  
  `n`までの階乗、逆元、階乗逆元をテーブルに保存して初期化。
  
  - 各種メソッド  
  順列、組み合わせ数、重複組み合わせ数を計算する。