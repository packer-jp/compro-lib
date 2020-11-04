---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Add-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Add-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Sum-Query-1.test.cpp
    title: test/AOJ/DSL/Range-Sum-Query-1.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick-tree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate<typename S>\nstruct fenwick_tree {\n    using T = typename\
    \ S::T;\n    int n;\n    std::vector<T> data;\n    fenwick_tree(int n) : n(n),\
    \ data(n + 1, S::zero()) {}\n    void add(int i, const T &x) {\n        for (i++;\
    \ i <= n; i += i & -i) { data[i] = S::plus(data[i], x); }\n    }\n    T sum(int\
    \ i) const {\n        T ret = S::zero();\n        for (; i > 0; i -= i & -i) {\
    \ ret = S::plus(ret, data[i]); }\n        return ret;\n    }\n    T sum(int l,\
    \ int r) const { return S::plus(S::minus(sum(l)), sum(r)); }\n};\n\ntemplate<typename\
    \ S>\nstruct fenwick_tree_range : public fenwick_tree<S> {\n    using F = fenwick_tree<S>;\n\
    \    using T = typename S::T;\n    fenwick_tree_range(int n) : F(n) {}\n    void\
    \ add(int l, int r, const T &x) { F::add(l, x), F::add(r, S::minus(x)); }\n  \
    \  T operator[](int i) const { return F::sum(i + 1); }\n};\n\nstruct rsq {\n \
    \   using T = int;\n    static T zero() { return 0; }\n    static T plus(const\
    \ T &a, const T &b) { return a + b; }\n    static T minus(const T &a) { return\
    \ -a; }\n};\n"
  code: "#include <vector>\n#include <cassert>\n\ntemplate<typename S>\nstruct fenwick_tree\
    \ {\n    using T = typename S::T;\n    int n;\n    std::vector<T> data;\n    fenwick_tree(int\
    \ n) : n(n), data(n + 1, S::zero()) {}\n    void add(int i, const T &x) {\n  \
    \      for (i++; i <= n; i += i & -i) { data[i] = S::plus(data[i], x); }\n   \
    \ }\n    T sum(int i) const {\n        T ret = S::zero();\n        for (; i >\
    \ 0; i -= i & -i) { ret = S::plus(ret, data[i]); }\n        return ret;\n    }\n\
    \    T sum(int l, int r) const { return S::plus(S::minus(sum(l)), sum(r)); }\n\
    };\n\ntemplate<typename S>\nstruct fenwick_tree_range : public fenwick_tree<S>\
    \ {\n    using F = fenwick_tree<S>;\n    using T = typename S::T;\n    fenwick_tree_range(int\
    \ n) : F(n) {}\n    void add(int l, int r, const T &x) { F::add(l, x), F::add(r,\
    \ S::minus(x)); }\n    T operator[](int i) const { return F::sum(i + 1); }\n};\n\
    \nstruct rsq {\n    using T = int;\n    static T zero() { return 0; }\n    static\
    \ T plus(const T &a, const T &b) { return a + b; }\n    static T minus(const T\
    \ &a) { return -a; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2020-09-24 00:11:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/Range-Add-Query-0.test.cpp
  - test/AOJ/DSL/Range-Sum-Query-1.test.cpp
documentation_of: data-structure/fenwick-tree.hpp
layout: document
title: "Fenwick \u6728"
---

- `<S> struct fenwick_tree`  
列への一点加算クエリと区間和クエリを処理する。

  - `(constructor)(int n)`  
  `n`は要素数。列の全要素を単位元で初期化。

  - `void add(int i, T x)`  
  要素`i`に`x`を加算。

  - `T sum(int i)`  
  `[0, i)`の区間和を返す。
  
  - `T sum(int l, int r)`  
  `[l, r)`の区間和を返す。

- `<S> struct fenwick_tree_range : public fenwick_tree<S>`  
列への区間加算クエリと一点取得クエリを処理する。

  - `(constructor)(int n)`  
  `n`は頂点数。列の全要素を単位元で初期化。

  - `void add(int l, int r, T x)`  
  `[l, r)`に`x`を加算。
  
  - `T operator[](int i)`  
  要素`i`を返す。

- `struct S`  
可換群をなす。
  - `struct T`  
  列に載せる値の型。

  - `T zero()`  
  `T`の`plus`に関する単位元。
  
  - `T plus(T a, T b)`  
  演算。