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
    links: []
  bundledCode: "#line 1 \"mathematics/permutation.hpp\"\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n#include <numeric>\n\nstruct permutation {\n\
    \    std::vector<int> data;\n    permutation(int n) : data(n) { for (int i = 0;\
    \ i < n; i++) { data[i] = i; }}\n    permutation(const std::vector<int> &src)\
    \ : data(src) {}\n    int size() const { return data.size(); }\n    static permutation\
    \ id(int n) {\n        std::vector<int> ret(n);\n        std::iota(ret.begin(),\
    \ ret.end(), 0LL);\n        return ret;\n    }\n    bool next() { return std::next_permutation(data.begin(),\
    \ data.end()); }\n    bool prev() { return std::prev_permutation(data.begin(),\
    \ data.end()); }\n    int operator[](int i) const { return data[i]; }\n    permutation\
    \ &operator*=(const permutation &a) {\n        std::vector<int> tmp(data);\n \
    \       for (int i = 0; i < size(); i++) { data[i] = tmp[a[i]]; }\n        return\
    \ *this;\n    }\n    permutation &operator/=(const permutation &a) { return *this\
    \ *= a.inv(); }\n    friend bool operator==(const permutation &a, const permutation\
    \ &b) { return a.data == b.data; }\n    friend bool operator!=(const permutation\
    \ &a, const permutation &b) { return std::rel_ops::operator!=(a, b); }\n    friend\
    \ permutation operator*(permutation a, const permutation &b) { return a *= b;\
    \ }\n    friend permutation operator/(permutation a, const permutation &b) { return\
    \ a /= b; }\n    permutation inv() const {\n        std::vector<int> ret(size());\n\
    \        for (int i = 0; i < size(); i++) { ret[data[i]] = i; }\n        return\
    \ ret;\n    }\n    permutation pow(long long m) const {\n        std::vector<int>\
    \ ret(size());\n        std::vector<bool> used(size());\n        for (int i =\
    \ 0; i < size(); i++) {\n            if (used[i]) { continue; }\n            std::vector<int>\
    \ cyc;\n            int cur = i;\n            do {\n                used[cur]\
    \ = true;\n                cyc.push_back(cur);\n                cur = data[cur];\n\
    \            } while (cur != i);\n            for (int j = 0; j < cyc.size();\
    \ j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()]; }\n        }\n        return\
    \ ret;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const permutation\
    \ &a) {\n        os << \"{\";\n        for (int i = 0; i < a.size(); i++) { os\
    \ << a[i] << (i + 1 != a.size() ? \", \" : \"\"); }\n        os << \"}\";\n  \
    \      return os;\n    }\n};\n"
  code: "#include <algorithm>\n#include <iostream>\n#include <vector>\n#include <numeric>\n\
    \nstruct permutation {\n    std::vector<int> data;\n    permutation(int n) : data(n)\
    \ { for (int i = 0; i < n; i++) { data[i] = i; }}\n    permutation(const std::vector<int>\
    \ &src) : data(src) {}\n    int size() const { return data.size(); }\n    static\
    \ permutation id(int n) {\n        std::vector<int> ret(n);\n        std::iota(ret.begin(),\
    \ ret.end(), 0LL);\n        return ret;\n    }\n    bool next() { return std::next_permutation(data.begin(),\
    \ data.end()); }\n    bool prev() { return std::prev_permutation(data.begin(),\
    \ data.end()); }\n    int operator[](int i) const { return data[i]; }\n    permutation\
    \ &operator*=(const permutation &a) {\n        std::vector<int> tmp(data);\n \
    \       for (int i = 0; i < size(); i++) { data[i] = tmp[a[i]]; }\n        return\
    \ *this;\n    }\n    permutation &operator/=(const permutation &a) { return *this\
    \ *= a.inv(); }\n    friend bool operator==(const permutation &a, const permutation\
    \ &b) { return a.data == b.data; }\n    friend bool operator!=(const permutation\
    \ &a, const permutation &b) { return std::rel_ops::operator!=(a, b); }\n    friend\
    \ permutation operator*(permutation a, const permutation &b) { return a *= b;\
    \ }\n    friend permutation operator/(permutation a, const permutation &b) { return\
    \ a /= b; }\n    permutation inv() const {\n        std::vector<int> ret(size());\n\
    \        for (int i = 0; i < size(); i++) { ret[data[i]] = i; }\n        return\
    \ ret;\n    }\n    permutation pow(long long m) const {\n        std::vector<int>\
    \ ret(size());\n        std::vector<bool> used(size());\n        for (int i =\
    \ 0; i < size(); i++) {\n            if (used[i]) { continue; }\n            std::vector<int>\
    \ cyc;\n            int cur = i;\n            do {\n                used[cur]\
    \ = true;\n                cyc.push_back(cur);\n                cur = data[cur];\n\
    \            } while (cur != i);\n            for (int j = 0; j < cyc.size();\
    \ j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()]; }\n        }\n        return\
    \ ret;\n    }\n    friend std::ostream &operator<<(std::ostream &os, const permutation\
    \ &a) {\n        os << \"{\";\n        for (int i = 0; i < a.size(); i++) { os\
    \ << a[i] << (i + 1 != a.size() ? \", \" : \"\"); }\n        os << \"}\";\n  \
    \      return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/permutation.hpp
  requiredBy: []
  timestamp: '2020-09-28 19:18:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/permutation.test.cpp
documentation_of: mathematics/permutation.hpp
layout: document
title: "\u9806\u5217"
---

