---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/heavy-light-decomposition.test.cpp
    title: test/unit-test/graph/heavy-light-decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n#include <limits>\n\ntemplate<typename S>\nstruct segment_tree {\n\
    \    using T = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, S::id()) {}\n    segment_tree(const std::vector<T> &src)\
    \ : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(), data.begin()\
    \ + n);\n        for (int i = n - 1; i > 0; i--) { data[i] = S::op(data[i << 1\
    \ | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const T &x) {\n     \
    \   data[i += n] = x;\n        while (i >>= 1) { data[i] = S::op(data[i << 1 |\
    \ 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const { return\
    \ data[i + n]; }\n    T fold(int l, int r) const {\n        T a = S::id(), b =\
    \ S::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) { a = S::op(a, data[l++]); }\n            if (r & 1) { b = S::op(data[--r],\
    \ b); }\n        }\n        return S::op(a, b);\n    }\n};\n\nstruct rsq {\n \
    \   using T = int;\n    static T op(const T &a, const T &b) { return a + b; }\n\
    \    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T = int;\n \
    \   static T op(const T &a, const T &b) { return std::min(a, b); }\n    static\
    \ T id() { return std::numeric_limits<T>::max(); }\n};\n"
  code: "#include <vector>\n#include <cassert>\n#include <limits>\n\ntemplate<typename\
    \ S>\nstruct segment_tree {\n    using T = typename S::T;\n    int n;\n    std::vector<T>\
    \ data;\n    segment_tree(int n) : n(n), data(n << 1, S::id()) {}\n    segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(),\
    \ src.end(), data.begin() + n);\n        for (int i = n - 1; i > 0; i--) { data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const\
    \ T &x) {\n        data[i += n] = x;\n        while (i >>= 1) { data[i] = S::op(data[i\
    \ << 1 | 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const\
    \ { return data[i + n]; }\n    T fold(int l, int r) const {\n        T a = S::id(),\
    \ b = S::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) { a = S::op(a, data[l++]); }\n            if (r & 1) { b =\
    \ S::op(data[--r], b); }\n        }\n        return S::op(a, b);\n    }\n};\n\n\
    struct rsq {\n    using T = int;\n    static T op(const T &a, const T &b) { return\
    \ a + b; }\n    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T\
    \ = int;\n    static T op(const T &a, const T &b) { return std::min(a, b); }\n\
    \    static T id() { return std::numeric_limits<T>::max(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  - test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - test/unit-test/graph/heavy-light-decomposition.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
title: "Segment \u6728"
---

- `<S> struct segment_tree`  
  列への一点変更クエリと区間演算クエリを処理する。

  - `(constructor)(int n)`  
    `n`は要素数。列の全要素を単位元で初期化。
  
  - `(constructor)(std::vector<std::vector<T>> src)`  
    `n`は要素数。列を`src`で初期化。

  - `void set(int i, T x)`  
    要素`i`を`x`に変更。
  
  - `T operator[](int i)`  
    要素`i`を返す。
  
  - `T fold(int l, int r)`  
    `[l, r)`の区間演算を返す。

- `struct S`  
  モノイドをなす。
  - `struct T`  
    列に載せる値の型。

  - `T id()`  
    `T`の`plus`に関する単位元。
  
  - `T zero(T a, T b)`  
    演算。