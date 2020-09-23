---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/permutation.test.cpp
    title: test/unit-test/mathematics/permutation.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/permutation.hpp\"\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\nstruct permutation {\n    int n;\n    std::vector<int>\
    \ data;\n    permutation(int n) : n(n), data(n) { for (int i = 0; i < n; i++)\
    \ { data[i] = i; }}\n    permutation(const std::vector<int> &src) : n(src.size()),\
    \ data(src) {}\n    bool next() { return std::next_permutation(data.begin(), data.end());\
    \ }\n    bool prev() { return std::prev_permutation(data.begin(), data.end());\
    \ }\n    bool operator==(const permutation &rhs) const { return data == rhs.data;\
    \ }\n    bool operator!=(const permutation &rhs) const { return std::rel_ops::operator!=(*this,\
    \ rhs); }\n    int operator[](int i) const { return data[i]; }\n    permutation\
    \ &operator*=(const permutation &rhs) {\n        std::vector<int> tmp(data);\n\
    \        for (int i = 0; i < n; i++) { data[i] = tmp[rhs[i]]; }\n        return\
    \ *this;\n    }\n    permutation &operator/=(const permutation &rhs) { return\
    \ *this *= rhs.inv(); }\n    permutation operator*(const permutation &rhs) const\
    \ { return permutation(*this) *= rhs; }\n    permutation operator/(const permutation\
    \ &rhs) const { return permutation(*this) /= rhs; }\n    permutation inv() const\
    \ {\n        std::vector<int> ret(n);\n        for (int i = 0; i < n; i++) { ret[data[i]]\
    \ = i; }\n        return ret;\n    }\n    permutation pow(long long m) const {\n\
    \        std::vector<int> ret(n);\n        std::vector<bool> used(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            if (used[i]) { continue; }\n   \
    \         std::vector<int> cyc;\n            int cur = i;\n            do {\n\
    \                used[cur] = true;\n                cyc.push_back(cur);\n    \
    \            cur = data[cur];\n            } while (cur != i);\n            for\
    \ (int j = 0; j < cyc.size(); j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()];\
    \ }\n        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const permutation &rhs) {\n        os << \"{\";\n        for (int i = 0;\
    \ i < rhs.n; i++) { os << rhs[i] << (i + 1 != rhs.n ? \", \" : \"\"); }\n    \
    \    os << \"}\";\n        return os;\n    }\n};\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <vector>\n\nstruct permutation\
    \ {\n    int n;\n    std::vector<int> data;\n    permutation(int n) : n(n), data(n)\
    \ { for (int i = 0; i < n; i++) { data[i] = i; }}\n    permutation(const std::vector<int>\
    \ &src) : n(src.size()), data(src) {}\n    bool next() { return std::next_permutation(data.begin(),\
    \ data.end()); }\n    bool prev() { return std::prev_permutation(data.begin(),\
    \ data.end()); }\n    bool operator==(const permutation &rhs) const { return data\
    \ == rhs.data; }\n    bool operator!=(const permutation &rhs) const { return std::rel_ops::operator!=(*this,\
    \ rhs); }\n    int operator[](int i) const { return data[i]; }\n    permutation\
    \ &operator*=(const permutation &rhs) {\n        std::vector<int> tmp(data);\n\
    \        for (int i = 0; i < n; i++) { data[i] = tmp[rhs[i]]; }\n        return\
    \ *this;\n    }\n    permutation &operator/=(const permutation &rhs) { return\
    \ *this *= rhs.inv(); }\n    permutation operator*(const permutation &rhs) const\
    \ { return permutation(*this) *= rhs; }\n    permutation operator/(const permutation\
    \ &rhs) const { return permutation(*this) /= rhs; }\n    permutation inv() const\
    \ {\n        std::vector<int> ret(n);\n        for (int i = 0; i < n; i++) { ret[data[i]]\
    \ = i; }\n        return ret;\n    }\n    permutation pow(long long m) const {\n\
    \        std::vector<int> ret(n);\n        std::vector<bool> used(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            if (used[i]) { continue; }\n   \
    \         std::vector<int> cyc;\n            int cur = i;\n            do {\n\
    \                used[cur] = true;\n                cyc.push_back(cur);\n    \
    \            cur = data[cur];\n            } while (cur != i);\n            for\
    \ (int j = 0; j < cyc.size(); j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()];\
    \ }\n        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const permutation &rhs) {\n        os << \"{\";\n        for (int i = 0;\
    \ i < rhs.n; i++) { os << rhs[i] << (i + 1 != rhs.n ? \", \" : \"\"); }\n    \
    \    os << \"}\";\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/permutation.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/permutation.test.cpp
documentation_of: mathematics/permutation.hpp
layout: document
title: "\u9806\u5217"
---

