---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/matrix.hpp
    title: mathematics/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: mathematics/mod-int.hpp
    title: mathematics/mod-int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ const { return data[0].size(); }\n    static matrix identity(int n) {\n    \
    \    matrix ret(n, n);\n        for (int i = 0; i < n; i++) { ret[i][i] = S::one();\
    \ }\n        return ret;\n    }\n    bool operator==(const matrix &rhs) const\
    \ {\n        if (height() != rhs.height() || width() != rhs.width()) { return\
    \ false; }\n        for (int i = 0; i < height(); i++) {\n            for (int\
    \ j = 0; j < width(); j++) {\n                if (data[i][j] != rhs[i][j]) { return\
    \ false; }\n            }\n        }\n        return true;\n    }\n    bool operator!=(const\
    \ matrix &rhs) const { return std::rel_ops::operator!=(*this, rhs); }\n    matrix\
    \ &operator+=(const matrix &rhs) {\n        for (int i = 0; i < height(); i++)\
    \ {\n            for (int j = 0; j < width(); j++) {\n                (*this)[i][j]\
    \ = S::plus((*this)[i][j], rhs[i][j]);\n            }\n        }\n        return\
    \ *this;\n    }\n    matrix &operator-=(const matrix &rhs) {\n        for (int\
    \ i = 0; i < height(); i++) {\n            for (int j = 0; j < width(); j++) {\n\
    \                (*this)[i][j] = S::plus((*this)[i][j], S::minus(rhs[i][j]));\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator*=(const\
    \ matrix &rhs) {\n        std::vector<std::vector<T>> ret(height(), std::vector<T>(rhs.width(),\
    \ S::zero()));\n        for (int i = 0; i < height(); i++) {\n            for\
    \ (int j = 0; j < rhs.width(); j++) {\n                for (int k = 0; k < width();\
    \ k++) {\n                    ret[i][j] = S::plus(ret[i][j], S::cross((*this)[i][k],\
    \ rhs[k][j]));\n                }\n            }\n        }\n        data = ret;\n\
    \        return *this;\n    }\n    matrix &operator/=(const matrix &rhs) { return\
    \ *this *= rhs.inv(); }\n    matrix operator+() const { return *this; }\n    matrix\
    \ operator-() const { return matrix(height(), width()) -= *this; }\n    matrix\
    \ operator+(const matrix &rhs) const { return matrix(*this) += rhs; }\n    matrix\
    \ operator-(const matrix &rhs) const { return matrix(*this) -= rhs; }\n    matrix\
    \ operator*(const matrix &rhs) const { return matrix(*this) *= rhs; }\n    matrix\
    \ operator/(const matrix &rhs) const { return matrix(*this) /= rhs; }\n    matrix\
    \ reduced() const {\n        std::vector ret(data);\n        for (int i = 0, m\
    \ = 0; i < width() && m < height(); i++) {\n            for (int j = m + 1; j\
    \ < height(); j++) {\n                if (S::less_abs(ret[m][i], ret[j][i])) {\
    \ swap(ret[m], ret[j]); }\n            }\n            if (S::less_abs(ret[m][i],\
    \ S::eps())) { continue; }\n            for (int j = width() - 1; j >= i; j--)\
    \ { ret[m][j] = S::cross(ret[m][j], S::inv(ret[m][i])); }\n            for (int\
    \ j = 0; j < height(); j++) {\n                if (j == m) { continue; }\n   \
    \             for (int k = width() - 1; k >= i; k--) {\n                    ret[j][k]\
    \ = S::plus(ret[j][k], S::minus(S::cross(ret[m][k], ret[j][i])));\n          \
    \      }\n            }\n            m++;\n        }\n        return ret;\n  \
    \  }\n    matrix inv() const {\n        matrix id = identity(height());\n    \
    \    matrix ex(std::vector(height(), std::vector<T>(width() << 1)));\n       \
    \ for (int i = 0; i < height(); i++) {\n            for (int j = 0; j < width();\
    \ j++) { ex[i][j] = (*this)[i][j]; }\n            for (int j = 0; j < width();\
    \ j++) { ex[i][width() + j] = id[i][j]; }\n        }\n        ex = ex.reduced();\n\
    \        std::vector ret(height(), std::vector<T>(width()));\n        for (int\
    \ i = 0; i < height(); i++) {\n            for (int j = 0; j < width(); j++) {\n\
    \                ret[i][j] = ex[i][width() + j];\n            }\n        }\n \
    \       return ret;\n    }\n    matrix pow(long long n) const {\n        matrix\
    \ ret = identity(height()), mul = *this;\n        while (n > 0) {\n          \
    \  if (n & 1) { ret *= mul; }\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const matrix &rhs) {\n        for (int i = 0; i < rhs.height(); i++) {\n\
    \            os << \"[\";\n            for (int j = 0; j < rhs.width(); j++) {\n\
    \                os << rhs[i][j] << (j + 1 == rhs.width() ? \"]\\n\" : \",\");\n\
    \            }\n        }\n        return os;\n    }\n};\n\nstruct double_mat\
    \ {\n    using T = double;\n    static T plus(const T &a, const T &b) { return\
    \ a + b; }\n    static T cross(const T &a, const T &b) { return a * b; }\n   \
    \ static T zero() { return 0; }\n    static T one() { return 1; }\n    static\
    \ T minus(const T &a) { return -a; }\n    static T inv(const T &a) { return 1\
    \ / a; }\n    static T eps() { return 1e-10; };\n    static bool less_abs(const\
    \ T &a, const T &b) { return std::abs(a) < std::abs(b); };\n};\n#line 5 \"mathematics/mod-int.hpp\"\
    \n\ntemplate<int MOD = 1000000007>\nstruct mod_int {\n    int val;\n    mod_int(long\
    \ long val_ = 0) : val(val_ % MOD) { if (val < 0) { val += MOD; }}\n    bool operator==(const\
    \ mod_int &rhs) const { return val == rhs.val; }\n    bool operator!=(const mod_int\
    \ &rhs) const { return std::rel_ops::operator!=(*this, rhs); }\n    mod_int &operator+=(const\
    \ mod_int &rhs) {\n        if ((val += rhs.val) >= MOD) { val -= MOD; }\n    \
    \    return *this;\n    }\n    mod_int &operator-=(const mod_int &rhs) {\n   \
    \     if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }\n        return *this;\n\
    \    }\n    mod_int &operator*=(const mod_int &rhs) {\n        val = (int) ((long\
    \ long) val * rhs.val % MOD);\n        return *this;\n    }\n    mod_int &operator/=(const\
    \ mod_int &rhs) { return *this *= rhs.inv(); }\n    mod_int operator+() const\
    \ { return *this; }\n    mod_int operator-() const { return -val; }\n    mod_int\
    \ operator++() { return *this += 1; }\n    mod_int operator--() { return *this\
    \ -= 1; }\n    mod_int operator++(signed) {\n        const mod_int ret(*this);\n\
    \        ++*this;\n        return ret;\n    }\n    mod_int operator--(signed)\
    \ {\n        const mod_int ret(*this);\n        --*this;\n        return ret;\n\
    \    }\n    mod_int operator+(const mod_int &rhs) const { return mod_int(*this)\
    \ += rhs; }\n    mod_int operator-(const mod_int &rhs) const { return mod_int(*this)\
    \ -= rhs; }\n    mod_int operator*(const mod_int &rhs) const { return mod_int(*this)\
    \ *= rhs; }\n    mod_int operator/(const mod_int &rhs) const { return mod_int(*this)\
    \ /= rhs; }\n    mod_int inv() const {\n        assert(val != 0);\n        int\
    \ a = val, b = MOD, x = 1, u = 0;\n        while (b) {\n            int t = a\
    \ / b;\n            std::swap(a -= t * b, b);\n            std::swap(x -= t *\
    \ u, u);\n        }\n        return x;\n    }\n    mod_int pow(long long n) const\
    \ {\n        if (n < 0) { return pow(-n).inv(); }\n        mod_int ret = 1, mul\
    \ = *this;\n        while (n) {\n            if (n & 1) { ret *= mul; }\n    \
    \        mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n \
    \   }\n    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {\n\
    \        long long v;\n        is >> v;\n        rhs = v;\n        return is;\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs)\
    \ { return os << rhs.val; }\n    struct combination {\n        std::vector<mod_int>\
    \ fact{1, 1}, f_inv{1, 1}, inv{0, 1};\n        void calc(int n) {\n          \
    \  while (fact.size() <= n) {\n                int i = fact.size();\n        \
    \        fact.push_back(fact[i - 1] * i);\n                inv.push_back(-inv[MOD\
    \ % i] * (MOD / i));\n                f_inv.push_back(f_inv[i - 1] * inv[i]);\n\
    \            }\n        }\n        mod_int P(int n, int r) { return r < 0 || n\
    \ < r ? 0 : (calc(n), fact[n] * f_inv[n - r]); }\n        mod_int C(int n, int\
    \ r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[r] * f_inv[n - r]);\
    \ }\n        mod_int H(int n, int r) { return C(n + r - 1, r); }\n    };\n};\n\
    #line 4 \"test/unit-test/mathematics/matrix.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    using mint = mod_int<>;\n    struct\
    \ mint_mat {\n        using T = mint;\n        static T plus(const T &a, const\
    \ T &b) { return a + b; }\n        static T cross(const T &a, const T &b) { return\
    \ a * b; }\n        static T zero() { return 0; }\n        static T one() { return\
    \ 1; }\n        static T minus(const T &a) { return -a; }\n        static T inv(const\
    \ T &a) { return a.inv(); }\n        static T eps() { return 0; };\n        static\
    \ bool less_abs(const T &a, const T &b) { return a.val < b.val; };\n    };\n \
    \   using mat = matrix<mint_mat>;\n    mat A({{8, 2, 3, 2},\n           {1, 3,\
    \ 2, 7},\n           {2, 5, 7, 6},\n           {1, 9, 9, 4}});\n    mat A2({{74,\
    \ 55, 67, 56},\n            {22, 84, 86, 63},\n            {41, 108, 119, 105},\n\
    \            {39, 110, 120, 135}});\n    assert(A * A == A2);\n    assert(A *\
    \ A * A * A * A * A * A * A * A * A == A.pow(10));\n    assert(A / A == mat::identity(A.height()));\n\
    \    assert(A.pow(12) / A.pow(2) / A.pow(3) / A.pow(5) == A * A);\n    assert(-A\
    \ == mat(A.height(), A.width()) - A);\n    cout << \"Hello World\" << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/matrix.hpp\"\n#include\"../../../mathematics/mod-int.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    using mint\
    \ = mod_int<>;\n    struct mint_mat {\n        using T = mint;\n        static\
    \ T plus(const T &a, const T &b) { return a + b; }\n        static T cross(const\
    \ T &a, const T &b) { return a * b; }\n        static T zero() { return 0; }\n\
    \        static T one() { return 1; }\n        static T minus(const T &a) { return\
    \ -a; }\n        static T inv(const T &a) { return a.inv(); }\n        static\
    \ T eps() { return 0; };\n        static bool less_abs(const T &a, const T &b)\
    \ { return a.val < b.val; };\n    };\n    using mat = matrix<mint_mat>;\n    mat\
    \ A({{8, 2, 3, 2},\n           {1, 3, 2, 7},\n           {2, 5, 7, 6},\n     \
    \      {1, 9, 9, 4}});\n    mat A2({{74, 55, 67, 56},\n            {22, 84, 86,\
    \ 63},\n            {41, 108, 119, 105},\n            {39, 110, 120, 135}});\n\
    \    assert(A * A == A2);\n    assert(A * A * A * A * A * A * A * A * A * A ==\
    \ A.pow(10));\n    assert(A / A == mat::identity(A.height()));\n    assert(A.pow(12)\
    \ / A.pow(2) / A.pow(3) / A.pow(5) == A * A);\n    assert(-A == mat(A.height(),\
    \ A.width()) - A);\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - mathematics/matrix.hpp
  - mathematics/mod-int.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/matrix.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/mathematics/matrix.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/matrix.test.cpp
- /verify/test/unit-test/mathematics/matrix.test.cpp.html
title: test/unit-test/mathematics/matrix.test.cpp
---
