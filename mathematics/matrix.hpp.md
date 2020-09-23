---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/matrix.test.cpp
    title: test/unit-test/mathematics/matrix.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/matrix.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <cassert>\n#include <utility>\n\ntemplate<typename S>\nstruct\
    \ matrix {\n    using T = typename S::T;\n    std::vector<std::vector<T>> data;\n\
    \    matrix(int h, int w) : data(h, std::vector<T>(w, S::zero())) {}\n    matrix(const\
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
    \ T &a, const T &b) { return std::abs(a) < std::abs(b); };\n};\n"
  code: "#include <iostream>\n#include <vector>\n#include <cassert>\n#include <utility>\n\
    \ntemplate<typename S>\nstruct matrix {\n    using T = typename S::T;\n    std::vector<std::vector<T>>\
    \ data;\n    matrix(int h, int w) : data(h, std::vector<T>(w, S::zero())) {}\n\
    \    matrix(const std::vector<std::vector<T>> &src) : data(src) {}\n    std::vector<T>\
    \ &operator[](int i) { return data[i]; }\n    const std::vector<T> &operator[](int\
    \ i) const { return data[i]; }\n    int height() const { return data.size(); }\n\
    \    int width() const { return data[0].size(); }\n    static matrix identity(int\
    \ n) {\n        matrix ret(n, n);\n        for (int i = 0; i < n; i++) { ret[i][i]\
    \ = S::one(); }\n        return ret;\n    }\n    bool operator==(const matrix\
    \ &rhs) const {\n        if (height() != rhs.height() || width() != rhs.width())\
    \ { return false; }\n        for (int i = 0; i < height(); i++) {\n          \
    \  for (int j = 0; j < width(); j++) {\n                if (data[i][j] != rhs[i][j])\
    \ { return false; }\n            }\n        }\n        return true;\n    }\n \
    \   bool operator!=(const matrix &rhs) const { return std::rel_ops::operator!=(*this,\
    \ rhs); }\n    matrix &operator+=(const matrix &rhs) {\n        for (int i = 0;\
    \ i < height(); i++) {\n            for (int j = 0; j < width(); j++) {\n    \
    \            (*this)[i][j] = S::plus((*this)[i][j], rhs[i][j]);\n            }\n\
    \        }\n        return *this;\n    }\n    matrix &operator-=(const matrix\
    \ &rhs) {\n        for (int i = 0; i < height(); i++) {\n            for (int\
    \ j = 0; j < width(); j++) {\n                (*this)[i][j] = S::plus((*this)[i][j],\
    \ S::minus(rhs[i][j]));\n            }\n        }\n        return *this;\n   \
    \ }\n    matrix &operator*=(const matrix &rhs) {\n        std::vector<std::vector<T>>\
    \ ret(height(), std::vector<T>(rhs.width(), S::zero()));\n        for (int i =\
    \ 0; i < height(); i++) {\n            for (int j = 0; j < rhs.width(); j++) {\n\
    \                for (int k = 0; k < width(); k++) {\n                    ret[i][j]\
    \ = S::plus(ret[i][j], S::cross((*this)[i][k], rhs[k][j]));\n                }\n\
    \            }\n        }\n        data = ret;\n        return *this;\n    }\n\
    \    matrix &operator/=(const matrix &rhs) { return *this *= rhs.inv(); }\n  \
    \  matrix operator+() const { return *this; }\n    matrix operator-() const {\
    \ return matrix(height(), width()) -= *this; }\n    matrix operator+(const matrix\
    \ &rhs) const { return matrix(*this) += rhs; }\n    matrix operator-(const matrix\
    \ &rhs) const { return matrix(*this) -= rhs; }\n    matrix operator*(const matrix\
    \ &rhs) const { return matrix(*this) *= rhs; }\n    matrix operator/(const matrix\
    \ &rhs) const { return matrix(*this) /= rhs; }\n    matrix reduced() const {\n\
    \        std::vector ret(data);\n        for (int i = 0, m = 0; i < width() &&\
    \ m < height(); i++) {\n            for (int j = m + 1; j < height(); j++) {\n\
    \                if (S::less_abs(ret[m][i], ret[j][i])) { swap(ret[m], ret[j]);\
    \ }\n            }\n            if (S::less_abs(ret[m][i], S::eps())) { continue;\
    \ }\n            for (int j = width() - 1; j >= i; j--) { ret[m][j] = S::cross(ret[m][j],\
    \ S::inv(ret[m][i])); }\n            for (int j = 0; j < height(); j++) {\n  \
    \              if (j == m) { continue; }\n                for (int k = width()\
    \ - 1; k >= i; k--) {\n                    ret[j][k] = S::plus(ret[j][k], S::minus(S::cross(ret[m][k],\
    \ ret[j][i])));\n                }\n            }\n            m++;\n        }\n\
    \        return ret;\n    }\n    matrix inv() const {\n        matrix id = identity(height());\n\
    \        matrix ex(std::vector(height(), std::vector<T>(width() << 1)));\n   \
    \     for (int i = 0; i < height(); i++) {\n            for (int j = 0; j < width();\
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
    \ T &a, const T &b) { return std::abs(a) < std::abs(b); };\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/matrix.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/matrix.test.cpp
documentation_of: mathematics/matrix.hpp
layout: document
redirect_from:
- /library/mathematics/matrix.hpp
- /library/mathematics/matrix.hpp.html
title: mathematics/matrix.hpp
---
