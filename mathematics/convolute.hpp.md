---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/mod-int.hpp
    title: "\u5270\u4F59\u74B0 / \u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
    title: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/convolute.hpp\"\n#include <cmath>\n#include\
    \ <vector>\n#line 1 \"mathematics/mod-int.hpp\"\n#include <iostream>\n#include\
    \ <utility>\n#line 4 \"mathematics/mod-int.hpp\"\n#include <cassert>\n\ntemplate<int\
    \ MOD = 1'000'000'007>\nstruct mod_int {\n    int v;\n    mod_int(long long v_\
    \ = 0) : v(v_ % MOD) { if (v < 0) { v += MOD; }}\n    static int mod() { return\
    \ MOD; }\n    int val() const { return v; }\n    mod_int &operator+=(const mod_int\
    \ &a) {\n        if ((v += a.v) >= MOD) { v -= MOD; }\n        return *this;\n\
    \    }\n    mod_int &operator-=(const mod_int &a) {\n        if ((v += MOD - a.v)\
    \ >= MOD) { v -= MOD; }\n        return *this;\n    }\n    mod_int &operator*=(const\
    \ mod_int &a) {\n        v = (int) ((long long) v * a.v % MOD);\n        return\
    \ *this;\n    }\n    mod_int &operator/=(const mod_int &a) { return *this *= a.inv();\
    \ }\n    mod_int operator+() const { return *this; }\n    mod_int operator-()\
    \ const { return -v; }\n    mod_int operator++() { return *this += 1; }\n    mod_int\
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
    \ - r]); }\n    T H(int n, int r) { return C(n + r - 1, r); }\n};\n#line 4 \"\
    mathematics/convolute.hpp\"\n\nconstexpr double PI = 3.1415926535897932384626433832795028;\n\
    \nstruct my_complex {\n    double real = 0, imag = 0;\n    my_complex() {}\n \
    \   my_complex(double real) : real(real) {}\n    my_complex(double real, double\
    \ imag) : real(real), imag(imag) {}\n    my_complex operator+() const { return\
    \ *this; }\n    my_complex operator-() const { return {-real, -imag}; }\n    my_complex\
    \ &operator+=(const my_complex &rhs) {\n        real += rhs.real;\n        imag\
    \ += rhs.imag;\n        return *this;\n    }\n    my_complex &operator-=(const\
    \ my_complex &rhs) {\n        real -= rhs.real;\n        imag -= rhs.imag;\n \
    \       return *this;\n    }\n    my_complex &operator*=(const my_complex &rhs)\
    \ {\n        double tmp = real * rhs.real - imag * rhs.imag;\n        imag = real\
    \ * rhs.imag + imag * rhs.real;\n        real = tmp;\n        return *this;\n\
    \    }\n    my_complex &operator/=(const int &rhs) {\n        real /= rhs;\n \
    \       imag /= rhs;\n        return *this;\n    }\n    my_complex operator+(const\
    \ my_complex &rhs) const { return my_complex(*this) += rhs; }\n    my_complex\
    \ operator-(const my_complex &rhs) const { return my_complex(*this) -= rhs; }\n\
    \    my_complex operator*(const my_complex &rhs) const { return my_complex(*this)\
    \ *= rhs; }\n    my_complex operator/(const int &rhs) const { return my_complex(*this)\
    \ /= rhs; }\n    my_complex conj() { return {real, -imag}; }\n};\n\ntemplate<typename\
    \ T> void fft(std::vector<T> &x, const std::vector<T> &w) {\n    int n = x.size();\n\
    \    int m = n >> 1;\n    std::vector<T> y(n);\n    for (int i = 1; i <= m; i\
    \ <<= 1) {\n        for (int j = 0; j < m; j += i) {\n            for (int k =\
    \ 0; k < i; k++) {\n                int u = j + k;\n                y[(u << 1)\
    \ + 0] = (x[u + 0] + x[u + m]);\n                y[(u << 1) + 1] = (x[u + 0] -\
    \ x[u + m]) * w[j];\n            }\n        }\n        std::swap(x, y);\n    }\n\
    }\n\ntemplate<typename T> void ifft(std::vector<T> &x, const std::vector<T> &w)\
    \ {\n    int n = x.size();\n    int m = n >> 1;\n    std::vector<T> y(n);\n  \
    \  for (int i = m; i > 0; i >>= 1) {\n        for (int j = 0; j < m; j += i) {\n\
    \            for (int k = 0; k < i; k++) {\n                int u = j + k;\n \
    \               x[(u << 1) + 1] *= w[j];\n                y[u + 0] = x[(u << 1)\
    \ + 0] + x[(u << 1) + 1];\n                y[u + m] = x[(u << 1) + 0] - x[(u <<\
    \ 1) + 1];\n            }\n        }\n        std::swap(x, y);\n    }\n    T n_inv\
    \ = T(1) / n;\n    for (int i = 0; i < n; i++) { x[i] *= n_inv; }\n}\n\nstd::vector<double>\
    \ convolute(const std::vector<double> &a, const std::vector<double> &b) {\n  \
    \  int n_a = a.size(), n_b = b.size();\n    int n_ = n_a + n_b - 1, n;\n    for\
    \ (n = 1; n < n_; n <<= 1) {}\n    int m = n >> 1;\n    std::vector<my_complex>\
    \ c(n), w(m);\n    for (int i = 0; i < n_a; i++) { c[i].real = a[i]; }\n    for\
    \ (int i = 0; i < n_b; i++) { c[i].imag = b[i]; }\n    double theta = -2 * PI\
    \ / n;\n    for (int i = 0; i < m; i++) { w[i] = {cos(i * theta), sin(i * theta)};\
    \ }\n    fft(c, w);\n    auto to_prod = [&](int p, int q) {\n        static my_complex\
    \ miq = {0, -0.25};\n        my_complex c_p_sq = c[p] * c[p];\n        my_complex\
    \ c_q_sq = c[q] * c[q];\n        c[p] = (c_p_sq - c_q_sq.conj()) * miq;\n    \
    \    c[q] = (c_q_sq - c_p_sq.conj()) * miq;\n    };\n    to_prod(0, 0);\n    for\
    \ (int i = 1, m = 1; i < n; i += 2) {\n        if (i >= m) { m <<= 1; }\n    \
    \    int j = m + (m >> 1) - 1 - i;\n        to_prod(i, j);\n    }\n    for (int\
    \ i = 0; i < m; i++) { w[i] = w[i].conj(); }\n    ifft(c, w);\n    std::vector<double>\
    \ ret(n_);\n    for (int i = 0; i < n_; i++) { ret[i] = c[i].real; }\n    return\
    \ ret;\n}\n\ntemplate<int MOD, int ROOT>\nstd::vector<int> friendly_mod_convolute(const\
    \ std::vector<int> &a, const std::vector<int> &b) {\n    int n_a = a.size(), n_b\
    \ = b.size();\n    int n_ = n_a + n_b - 1, n;\n    for (n = 1; n < n_; n <<= 1)\
    \ {}\n    int m = n >> 1;\n    std::vector<mod_int<MOD>> a_mint(n), b_mint(n),\
    \ w(m + 2);\n    std::copy(a.begin(), a.end(), a_mint.begin()), std::copy(b.begin(),\
    \ b.end(), b_mint.begin());\n    w[0] = 1, w[1] = mod_int<MOD>(ROOT).pow((MOD\
    \ - 1) / n);\n    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }\n  \
    \  fft(a_mint, w);\n    fft(b_mint, w);\n    for (int i = 0; i < n; i++) { a_mint[i]\
    \ *= b_mint[i]; }\n    w[1] = w[1].inv();\n    for (int i = 2; i < m; i++) { w[i]\
    \ = w[i - 1] * w[1]; }\n    ifft(a_mint, w);\n    std::vector<int> ret(n_);\n\
    \    for (int i = 0; i < n_; i++) { ret[i] = a_mint[i].val(); }\n    return ret;\n\
    }\n\ntemplate<int K = 3>\nstd::vector<int> arbitrary_mod_convolute(const std::vector<int>\
    \ &a, const std::vector<int> &b, int mod) {\n    static constexpr int MS[] = {998244353,\
    \ 469762049, 167772161}, RS[] = {3, 3, 3};\n    auto safe_mod = [](int a, int\
    \ m) -> int {\n        a %= m;\n        if (a < 0) { a += m; }\n        return\
    \ a;\n    };\n    auto mod_inv = [&](int a, int m) -> int {\n        int b = m,\
    \ x = 1, u = 0;\n        while (b) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b);\n            std::swap(x -= t * u, u);\n        }\n\
    \        return safe_mod(x, m);\n    };\n    int n_a = a.size(), n_b = b.size();\n\
    \    int n_ = n_a + n_b - 1, n;\n    for (n = 1; n < n_; n <<= 1) {}\n    std::vector<int>\
    \ m(K + 1), prod_m(K + 1, 1);\n    std::vector<std::vector<int>> ret(K + 1, std::vector<int>(n_));\n\
    \    std::copy(MS, MS + K, m.begin());\n    m[K] = mod;\n    for (int i = 0; i\
    \ < K; i++) {\n        std::vector<int> piece;\n        if (i == 0) { piece =\
    \ friendly_mod_convolute<MS[0], RS[0]>(a, b); }\n        if (i == 1) { piece =\
    \ friendly_mod_convolute<MS[1], RS[1]>(a, b); }\n        if (i == 2) { piece =\
    \ friendly_mod_convolute<MS[2], RS[2]>(a, b); }\n        int prod_inv = mod_inv(prod_m[i],\
    \ m[i]);\n        for (int j = 0; j < n_; j++) {\n            int mod_m_i = (long\
    \ long) safe_mod(piece[j] - ret[i][j], m[i]) * prod_inv % m[i];\n            for\
    \ (int k = i + 1; k <= K; k++) {\n                ret[k][j] = (ret[k][j] + (long\
    \ long) mod_m_i * prod_m[k] % m[k]) % m[k];\n            }\n        }\n      \
    \  for (int j = i + 1; j <= K; j++) { prod_m[j] = (long long) prod_m[j] * m[i]\
    \ % m[j]; }\n    }\n    return ret[K];\n}\n"
  code: "#include <cmath>\n#include <vector>\n#include \"mod-int.hpp\"\n\nconstexpr\
    \ double PI = 3.1415926535897932384626433832795028;\n\nstruct my_complex {\n \
    \   double real = 0, imag = 0;\n    my_complex() {}\n    my_complex(double real)\
    \ : real(real) {}\n    my_complex(double real, double imag) : real(real), imag(imag)\
    \ {}\n    my_complex operator+() const { return *this; }\n    my_complex operator-()\
    \ const { return {-real, -imag}; }\n    my_complex &operator+=(const my_complex\
    \ &rhs) {\n        real += rhs.real;\n        imag += rhs.imag;\n        return\
    \ *this;\n    }\n    my_complex &operator-=(const my_complex &rhs) {\n       \
    \ real -= rhs.real;\n        imag -= rhs.imag;\n        return *this;\n    }\n\
    \    my_complex &operator*=(const my_complex &rhs) {\n        double tmp = real\
    \ * rhs.real - imag * rhs.imag;\n        imag = real * rhs.imag + imag * rhs.real;\n\
    \        real = tmp;\n        return *this;\n    }\n    my_complex &operator/=(const\
    \ int &rhs) {\n        real /= rhs;\n        imag /= rhs;\n        return *this;\n\
    \    }\n    my_complex operator+(const my_complex &rhs) const { return my_complex(*this)\
    \ += rhs; }\n    my_complex operator-(const my_complex &rhs) const { return my_complex(*this)\
    \ -= rhs; }\n    my_complex operator*(const my_complex &rhs) const { return my_complex(*this)\
    \ *= rhs; }\n    my_complex operator/(const int &rhs) const { return my_complex(*this)\
    \ /= rhs; }\n    my_complex conj() { return {real, -imag}; }\n};\n\ntemplate<typename\
    \ T> void fft(std::vector<T> &x, const std::vector<T> &w) {\n    int n = x.size();\n\
    \    int m = n >> 1;\n    std::vector<T> y(n);\n    for (int i = 1; i <= m; i\
    \ <<= 1) {\n        for (int j = 0; j < m; j += i) {\n            for (int k =\
    \ 0; k < i; k++) {\n                int u = j + k;\n                y[(u << 1)\
    \ + 0] = (x[u + 0] + x[u + m]);\n                y[(u << 1) + 1] = (x[u + 0] -\
    \ x[u + m]) * w[j];\n            }\n        }\n        std::swap(x, y);\n    }\n\
    }\n\ntemplate<typename T> void ifft(std::vector<T> &x, const std::vector<T> &w)\
    \ {\n    int n = x.size();\n    int m = n >> 1;\n    std::vector<T> y(n);\n  \
    \  for (int i = m; i > 0; i >>= 1) {\n        for (int j = 0; j < m; j += i) {\n\
    \            for (int k = 0; k < i; k++) {\n                int u = j + k;\n \
    \               x[(u << 1) + 1] *= w[j];\n                y[u + 0] = x[(u << 1)\
    \ + 0] + x[(u << 1) + 1];\n                y[u + m] = x[(u << 1) + 0] - x[(u <<\
    \ 1) + 1];\n            }\n        }\n        std::swap(x, y);\n    }\n    T n_inv\
    \ = T(1) / n;\n    for (int i = 0; i < n; i++) { x[i] *= n_inv; }\n}\n\nstd::vector<double>\
    \ convolute(const std::vector<double> &a, const std::vector<double> &b) {\n  \
    \  int n_a = a.size(), n_b = b.size();\n    int n_ = n_a + n_b - 1, n;\n    for\
    \ (n = 1; n < n_; n <<= 1) {}\n    int m = n >> 1;\n    std::vector<my_complex>\
    \ c(n), w(m);\n    for (int i = 0; i < n_a; i++) { c[i].real = a[i]; }\n    for\
    \ (int i = 0; i < n_b; i++) { c[i].imag = b[i]; }\n    double theta = -2 * PI\
    \ / n;\n    for (int i = 0; i < m; i++) { w[i] = {cos(i * theta), sin(i * theta)};\
    \ }\n    fft(c, w);\n    auto to_prod = [&](int p, int q) {\n        static my_complex\
    \ miq = {0, -0.25};\n        my_complex c_p_sq = c[p] * c[p];\n        my_complex\
    \ c_q_sq = c[q] * c[q];\n        c[p] = (c_p_sq - c_q_sq.conj()) * miq;\n    \
    \    c[q] = (c_q_sq - c_p_sq.conj()) * miq;\n    };\n    to_prod(0, 0);\n    for\
    \ (int i = 1, m = 1; i < n; i += 2) {\n        if (i >= m) { m <<= 1; }\n    \
    \    int j = m + (m >> 1) - 1 - i;\n        to_prod(i, j);\n    }\n    for (int\
    \ i = 0; i < m; i++) { w[i] = w[i].conj(); }\n    ifft(c, w);\n    std::vector<double>\
    \ ret(n_);\n    for (int i = 0; i < n_; i++) { ret[i] = c[i].real; }\n    return\
    \ ret;\n}\n\ntemplate<int MOD, int ROOT>\nstd::vector<int> friendly_mod_convolute(const\
    \ std::vector<int> &a, const std::vector<int> &b) {\n    int n_a = a.size(), n_b\
    \ = b.size();\n    int n_ = n_a + n_b - 1, n;\n    for (n = 1; n < n_; n <<= 1)\
    \ {}\n    int m = n >> 1;\n    std::vector<mod_int<MOD>> a_mint(n), b_mint(n),\
    \ w(m + 2);\n    std::copy(a.begin(), a.end(), a_mint.begin()), std::copy(b.begin(),\
    \ b.end(), b_mint.begin());\n    w[0] = 1, w[1] = mod_int<MOD>(ROOT).pow((MOD\
    \ - 1) / n);\n    for (int i = 2; i < m; i++) { w[i] = w[i - 1] * w[1]; }\n  \
    \  fft(a_mint, w);\n    fft(b_mint, w);\n    for (int i = 0; i < n; i++) { a_mint[i]\
    \ *= b_mint[i]; }\n    w[1] = w[1].inv();\n    for (int i = 2; i < m; i++) { w[i]\
    \ = w[i - 1] * w[1]; }\n    ifft(a_mint, w);\n    std::vector<int> ret(n_);\n\
    \    for (int i = 0; i < n_; i++) { ret[i] = a_mint[i].val(); }\n    return ret;\n\
    }\n\ntemplate<int K = 3>\nstd::vector<int> arbitrary_mod_convolute(const std::vector<int>\
    \ &a, const std::vector<int> &b, int mod) {\n    static constexpr int MS[] = {998244353,\
    \ 469762049, 167772161}, RS[] = {3, 3, 3};\n    auto safe_mod = [](int a, int\
    \ m) -> int {\n        a %= m;\n        if (a < 0) { a += m; }\n        return\
    \ a;\n    };\n    auto mod_inv = [&](int a, int m) -> int {\n        int b = m,\
    \ x = 1, u = 0;\n        while (b) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b);\n            std::swap(x -= t * u, u);\n        }\n\
    \        return safe_mod(x, m);\n    };\n    int n_a = a.size(), n_b = b.size();\n\
    \    int n_ = n_a + n_b - 1, n;\n    for (n = 1; n < n_; n <<= 1) {}\n    std::vector<int>\
    \ m(K + 1), prod_m(K + 1, 1);\n    std::vector<std::vector<int>> ret(K + 1, std::vector<int>(n_));\n\
    \    std::copy(MS, MS + K, m.begin());\n    m[K] = mod;\n    for (int i = 0; i\
    \ < K; i++) {\n        std::vector<int> piece;\n        if (i == 0) { piece =\
    \ friendly_mod_convolute<MS[0], RS[0]>(a, b); }\n        if (i == 1) { piece =\
    \ friendly_mod_convolute<MS[1], RS[1]>(a, b); }\n        if (i == 2) { piece =\
    \ friendly_mod_convolute<MS[2], RS[2]>(a, b); }\n        int prod_inv = mod_inv(prod_m[i],\
    \ m[i]);\n        for (int j = 0; j < n_; j++) {\n            int mod_m_i = (long\
    \ long) safe_mod(piece[j] - ret[i][j], m[i]) * prod_inv % m[i];\n            for\
    \ (int k = i + 1; k <= K; k++) {\n                ret[k][j] = (ret[k][j] + (long\
    \ long) mod_m_i * prod_m[k] % m[k]) % m[k];\n            }\n        }\n      \
    \  for (int j = i + 1; j <= K; j++) { prod_m[j] = (long long) prod_m[j] * m[i]\
    \ % m[j]; }\n    }\n    return ret[K];\n}\n"
  dependsOn:
  - mathematics/mod-int.hpp
  isVerificationFile: false
  path: mathematics/convolute.hpp
  requiredBy: []
  timestamp: '2020-09-28 19:25:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
documentation_of: mathematics/convolute.hpp
layout: document
title: "\u7573\u307F\u8FBC\u307F"
---

## 概要
二数列の畳み込み演算を列長$N, M$に対し$O((N+M) \log (N+M))$で処理する。

## 関数
- `std::vector<double> convolute(std::vector<double> a, std::vector<double> b)`  
`a`と`b`を畳み込む。

- `<int MOD, int ROOT> std::vector<int> friendly_mod_convolute(std::vector<int> a, std::vector<int> b)`  
`a`と`b`を`MOD`を法として畳み込む。  
`MOD`が素数であり、`MOD-1`が`2`で割れる回数が多いときに用いる。  
また、原始根`ROOT`が必要。

- `<int K = 3> std::vector<int> arbitrary_mod_convolute(std::vector<int> a, std::vector<int> b, int mod)`  
`a`と`b`を`mod`を法として畳み込む。`mod`は`long long`の範囲ならOK。  
`K`個の法について`friendly_mod_convolution`を計算した結果を用いている。