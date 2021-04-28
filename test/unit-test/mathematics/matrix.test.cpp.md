---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/matrix.hpp
    title: "\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: mathematics/mod-int.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/mathematics/matrix.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/matrix.hpp\"\n#include <iostream>\n#include <vector>\n\
    #include <cassert>\n#include <utility>\n\ntemplate<typename S>\nstruct matrix\
    \ {\n    using T = typename S::T;\n    std::vector<std::vector<T>> data;\n   \
    \ matrix(int h, int w) : data(h, std::vector<T>(w, S::zero())) {}\n    matrix(const\
    \ std::vector<std::vector<T>> &src) : data(src) {}\n    std::vector<T> &operator[](int\
    \ i) { return data[i]; }\n    const std::vector<T> &operator[](int i) const {\
    \ return data[i]; }\n    int height() const { return data.size(); }\n    int width()\
    \ const { return data[0].size(); }\n    static matrix id(int n) {\n        matrix\
    \ ret(n, n);\n        for (int i = 0; i < n; i++) { ret[i][i] = S::one(); }\n\
    \        return ret;\n    }\n    matrix &operator+=(const matrix &a) {\n     \
    \   for (int i = 0; i < height(); i++) {\n            for (int j = 0; j < width();\
    \ j++) {\n                (*this)[i][j] = S::plus((*this)[i][j], a[i][j]);\n \
    \           }\n        }\n        return *this;\n    }\n    matrix &operator-=(const\
    \ matrix &a) {\n        for (int i = 0; i < height(); i++) {\n            for\
    \ (int j = 0; j < width(); j++) {\n                (*this)[i][j] = S::plus((*this)[i][j],\
    \ S::minus(a[i][j]));\n            }\n        }\n        return *this;\n    }\n\
    \    matrix &operator*=(const matrix &a) {\n        std::vector<std::vector<T>>\
    \ ret(height(), std::vector<T>(a.width(), S::zero()));\n        for (int i = 0;\
    \ i < height(); i++) {\n            for (int j = 0; j < a.width(); j++) {\n  \
    \              for (int k = 0; k < width(); k++) {\n                    ret[i][j]\
    \ = S::plus(ret[i][j], S::cross((*this)[i][k], a[k][j]));\n                }\n\
    \            }\n        }\n        data = ret;\n        return *this;\n    }\n\
    \    matrix &operator/=(const matrix &a) { return *this *= a.inv(); }\n    matrix\
    \ operator+() const { return *this; }\n    matrix operator-() const { return matrix(height(),\
    \ width()) -= *this; }\n    friend bool operator==(const matrix &a, const matrix\
    \ &b) {\n        if (a.height() != b.height() || a.width() != b.width()) { return\
    \ false; }\n        for (int i = 0; i < a.height(); i++) {\n            for (int\
    \ j = 0; j < a.width(); j++) {\n                if (a[i][j] != b[i][j]) { return\
    \ false; }\n            }\n        }\n        return true;\n    }\n    friend\
    \ bool operator!=(const matrix &a, const matrix &b) { return std::rel_ops::operator!=(a,\
    \ b); }\n    friend matrix operator+(matrix a, const matrix &b) { return a +=\
    \ b; }\n    friend matrix operator-(matrix a, const matrix &b) { return a -= b;\
    \ }\n    friend matrix operator*(matrix a, const matrix &b) { return a *= b; }\n\
    \    friend matrix operator/(matrix a, const matrix &b) { return a /= b; }\n \
    \   matrix reduced() const {\n        std::vector ret(data);\n        for (int\
    \ i = 0, m = 0; i < width() && m < height(); i++) {\n            for (int j =\
    \ m + 1; j < height(); j++) {\n                if (S::less_abs(ret[m][i], ret[j][i]))\
    \ { swap(ret[m], ret[j]); }\n            }\n            if (S::less_abs(ret[m][i],\
    \ S::eps())) { continue; }\n            for (int j = width() - 1; j >= i; j--)\
    \ { ret[m][j] = S::cross(ret[m][j], S::inv(ret[m][i])); }\n            for (int\
    \ j = 0; j < height(); j++) {\n                if (j == m) { continue; }\n   \
    \             for (int k = width() - 1; k >= i; k--) {\n                    ret[j][k]\
    \ = S::plus(ret[j][k], S::minus(S::cross(ret[m][k], ret[j][i])));\n          \
    \      }\n            }\n            m++;\n        }\n        return ret;\n  \
    \  }\n    matrix inv() const {\n        matrix id_ = id(height()), ex(std::vector(height(),\
    \ std::vector<T>(width() << 1)));\n        for (int i = 0; i < height(); i++)\
    \ {\n            for (int j = 0; j < width(); j++) { ex[i][j] = (*this)[i][j];\
    \ }\n            for (int j = 0; j < width(); j++) { ex[i][width() + j] = id_[i][j];\
    \ }\n        }\n        ex = ex.reduced();\n        std::vector ret(height(),\
    \ std::vector<T>(width()));\n        for (int i = 0; i < height(); i++) {\n  \
    \          for (int j = 0; j < width(); j++) {\n                ret[i][j] = ex[i][width()\
    \ + j];\n            }\n        }\n        return ret;\n    }\n    matrix pow(long\
    \ long n) const {\n        matrix ret = id(height()), mul = *this;\n        while\
    \ (n > 0) {\n            if (n & 1) { ret *= mul; }\n            mul *= mul;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const matrix &rhs) {\n        for (int i = 0;\
    \ i < rhs.height(); i++) {\n            os << (i == 0 ? \"{{\" : \" {\");\n  \
    \          for (int j = 0; j < rhs.width(); j++) {\n                os << rhs[i][j]\
    \ << (j + 1 == rhs.width() ? \"}\" : \", \");\n            }\n            os <<\
    \ (i == rhs.height() - 1 ? \"}\" : \",\\n\");\n        }\n        return os;\n\
    \    }\n};\n\nstruct double_mat {\n    using T = double;\n    static T plus(const\
    \ T &a, const T &b) { return a + b; }\n    static T cross(const T &a, const T\
    \ &b) { return a * b; }\n    static T zero() { return 0; }\n    static T one()\
    \ { return 1; }\n    static T minus(const T &a) { return -a; }\n    static T inv(const\
    \ T &a) { return 1 / a; }\n    static T eps() { return 1e-10; };\n    static bool\
    \ less_abs(const T &a, const T &b) { return std::abs(a) < std::abs(b); };\n};\n\
    #line 5 \"mathematics/mod-int.hpp\"\n\ntemplate<int MOD = 1000000007>\nstruct\
    \ mod_int {\n    int v;\n    mod_int(long long v_ = 0) : v(v_ % MOD) { if (v <\
    \ 0) { v += MOD; }}\n    static int mod() { return MOD; }\n    int val() const\
    \ { return v; }\n    mod_int &operator+=(const mod_int &a) {\n        if ((v +=\
    \ a.v) >= MOD) { v -= MOD; }\n        return *this;\n    }\n    mod_int &operator-=(const\
    \ mod_int &a) {\n        if ((v += MOD - a.v) >= MOD) { v -= MOD; }\n        return\
    \ *this;\n    }\n    mod_int &operator*=(const mod_int &a) {\n        v = (int)\
    \ ((long long) v * a.v % MOD);\n        return *this;\n    }\n    mod_int &operator/=(const\
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
    test/unit-test/mathematics/matrix.test.cpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    using mint = mod_int<>;\n    struct mint_mat\
    \ {\n        using T = mint;\n        static T plus(const T &a, const T &b) {\
    \ return a + b; }\n        static T cross(const T &a, const T &b) { return a *\
    \ b; }\n        static T zero() { return 0; }\n        static T one() { return\
    \ 1; }\n        static T minus(const T &a) { return -a; }\n        static T inv(const\
    \ T &a) { return a.inv(); }\n        static T eps() { return 0; };\n        static\
    \ bool less_abs(const T &a, const T &b) { return a.val() < b.val(); };\n    };\n\
    \    using mat = matrix<mint_mat>;\n    mat A({{8, 2, 3, 2},\n           {1, 3,\
    \ 2, 7},\n           {2, 5, 7, 6},\n           {1, 9, 9, 4}});\n    mat A2({{74,\
    \ 55, 67, 56},\n            {22, 84, 86, 63},\n            {41, 108, 119, 105},\n\
    \            {39, 110, 120, 135}});\n    assert(A * A == A2);\n    assert(A *\
    \ A * A * A * A * A * A * A * A * A == A.pow(10));\n    assert(A / A == mat::id(A.height()));\n\
    \    assert(A.pow(12) / A.pow(2) / A.pow(3) / A.pow(5) == A * A);\n    assert(-A\
    \ == mat(A.height(), A.width()) - A);\n    cerr << A << endl;\n    cout << \"\
    Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/matrix.hpp\"\n#include\"../../../mathematics/mod-int.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    using mint\
    \ = mod_int<>;\n    struct mint_mat {\n        using T = mint;\n        static\
    \ T plus(const T &a, const T &b) { return a + b; }\n        static T cross(const\
    \ T &a, const T &b) { return a * b; }\n        static T zero() { return 0; }\n\
    \        static T one() { return 1; }\n        static T minus(const T &a) { return\
    \ -a; }\n        static T inv(const T &a) { return a.inv(); }\n        static\
    \ T eps() { return 0; };\n        static bool less_abs(const T &a, const T &b)\
    \ { return a.val() < b.val(); };\n    };\n    using mat = matrix<mint_mat>;\n\
    \    mat A({{8, 2, 3, 2},\n           {1, 3, 2, 7},\n           {2, 5, 7, 6},\n\
    \           {1, 9, 9, 4}});\n    mat A2({{74, 55, 67, 56},\n            {22, 84,\
    \ 86, 63},\n            {41, 108, 119, 105},\n            {39, 110, 120, 135}});\n\
    \    assert(A * A == A2);\n    assert(A * A * A * A * A * A * A * A * A * A ==\
    \ A.pow(10));\n    assert(A / A == mat::id(A.height()));\n    assert(A.pow(12)\
    \ / A.pow(2) / A.pow(3) / A.pow(5) == A * A);\n    assert(-A == mat(A.height(),\
    \ A.width()) - A);\n    cerr << A << endl;\n    cout << \"Hello World\" << endl;\n\
    }"
  dependsOn:
  - mathematics/matrix.hpp
  - mathematics/mod-int.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/matrix.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 19:42:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/mathematics/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/matrix.test.cpp
- /verify/test/unit-test/mathematics/matrix.test.cpp.html
title: test/unit-test/mathematics/matrix.test.cpp
---
