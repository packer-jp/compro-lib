---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/heavy-light-decomposition.test.cpp
    title: test/unit-test/graph/heavy-light-decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <limits>\n\ntemplate<typename M>\nstruct segment_tree {\n\
    \    using T = typename M::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, M::id()) {}\n    segment_tree(const std::vector<T> &src)\
    \ : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(), data.begin()\
    \ + n);\n        for (int i = n - 1; i > 0; i--) { data[i] = M::op(data[i << 1\
    \ | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const T &x) {\n     \
    \   data[i += n] = x;\n        while (i >>= 1) { data[i] = M::op(data[i << 1 |\
    \ 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const { return\
    \ data[i + n]; }\n    T fold(int l, int r) const {\n        T a = M::id(), b =\
    \ M::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) { a = M::op(a, data[l++]); }\n            if (r & 1) { b = M::op(data[--r],\
    \ b); }\n        }\n        return M::op(a, b);\n    }\n};\n\nstruct rsq {\n \
    \   using T = int;\n    static T op(const T &a, const T &b) { return a + b; }\n\
    \    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T = int;\n \
    \   static T op(const T &a, const T &b) { return std::min(a, b); }\n    static\
    \ T id() { return std::numeric_limits<T>::max(); }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <limits>\n\ntemplate<typename\
    \ M>\nstruct segment_tree {\n    using T = typename M::T;\n    int n;\n    std::vector<T>\
    \ data;\n    segment_tree(int n) : n(n), data(n << 1, M::id()) {}\n    segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(),\
    \ src.end(), data.begin() + n);\n        for (int i = n - 1; i > 0; i--) { data[i]\
    \ = M::op(data[i << 1 | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const\
    \ T &x) {\n        data[i += n] = x;\n        while (i >>= 1) { data[i] = M::op(data[i\
    \ << 1 | 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const\
    \ { return data[i + n]; }\n    T fold(int l, int r) const {\n        T a = M::id(),\
    \ b = M::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) { a = M::op(a, data[l++]); }\n            if (r & 1) { b =\
    \ M::op(data[--r], b); }\n        }\n        return M::op(a, b);\n    }\n};\n\n\
    struct rsq {\n    using T = int;\n    static T op(const T &a, const T &b) { return\
    \ a + b; }\n    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T\
    \ = int;\n    static T op(const T &a, const T &b) { return std::min(a, b); }\n\
    \    static T id() { return std::numeric_limits<T>::max(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/graph/heavy-light-decomposition.test.cpp
  - test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - test/AOJ/DSL/Range-Sum-Query-0.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
title: "Segment \u6728"
---

## 概要
モノイド列の一点変更クエリと区間和クエリを列長$N$に対し$O(\log N)$で処理する。

## テンプレートパラメータ
- `typename T`  
モノイドのデータ型。

- `typename F`  
モノイドの二項演算の型。

- `typename ID`  
モノイドの単位元を返す関数の型。

## メンバ
- `(constructor)(int n, F f, ID id)`  
列長`n`、二項演算`f`、単位元`id`で初期化。

- `(constructor)(std::vector<T> src, F f, ID id)`  
`src`を元に、二項演算`f`、単位元`id`で初期化。

- `int n`  
列長。

- `void set(int i, T x)`  
要素`i`を`x`に変更する。

- `T operator[](int i)`  
要素`i`を取得する。

- `T get_sum(int l, int r)`  
`[l, r)`の区間和を取得する。