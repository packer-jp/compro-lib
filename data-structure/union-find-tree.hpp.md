---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
    title: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/union-find-tree.hpp\"\n#include <vector>\n\
    \ntemplate<typename S>\nstruct union_find_tree {\n    using T = typename S::T;\n\
    \    std::vector<int> par, sz;\n    std::vector<T> val;\n    union_find_tree(const\
    \ std::vector<T> &val) : par(val.size(), -1), sz(val.size(), 1), val(val) {}\n\
    \    union_find_tree(int n, const T &x = {}) : union_find_tree(std::vector<T>(n,\
    \ x)) {}\n    int root(int i) {\n        if (par[i] == -1) { return i; }\n   \
    \     else { return par[i] = root(par[i]); }\n    }\n    void unite(int i, int\
    \ j) {\n        if ((i = root(i)) == (j = root(j))) { return; }\n        if (sz[i]\
    \ < sz[j]) { std::swap(i, j); }\n        sz[i] += sz[j];\n        val[i] = S::op(val[i],\
    \ val[j]);\n        par[j] = i;\n    }\n    bool same(int i, int j) { return root(i)\
    \ == root(j); }\n    int size(int i) { return sz[root(i)]; }\n    T &operator[](int\
    \ i) { return val[root(i)]; }\n};\n\nstruct normal_uf {\n    struct T {};\n  \
    \  static T op(const T &a, const T &b) { return {}; }\n};\n"
  code: "#include <vector>\n\ntemplate<typename S>\nstruct union_find_tree {\n   \
    \ using T = typename S::T;\n    std::vector<int> par, sz;\n    std::vector<T>\
    \ val;\n    union_find_tree(const std::vector<T> &val) : par(val.size(), -1),\
    \ sz(val.size(), 1), val(val) {}\n    union_find_tree(int n, const T &x = {})\
    \ : union_find_tree(std::vector<T>(n, x)) {}\n    int root(int i) {\n        if\
    \ (par[i] == -1) { return i; }\n        else { return par[i] = root(par[i]); }\n\
    \    }\n    void unite(int i, int j) {\n        if ((i = root(i)) == (j = root(j)))\
    \ { return; }\n        if (sz[i] < sz[j]) { std::swap(i, j); }\n        sz[i]\
    \ += sz[j];\n        val[i] = S::op(val[i], val[j]);\n        par[j] = i;\n  \
    \  }\n    bool same(int i, int j) { return root(i) == root(j); }\n    int size(int\
    \ i) { return sz[root(i)]; }\n    T &operator[](int i) { return val[root(i)];\
    \ }\n};\n\nstruct normal_uf {\n    struct T {};\n    static T op(const T &a, const\
    \ T &b) { return {}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find-tree.hpp
  requiredBy: []
  timestamp: '2020-09-26 20:50:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/Union-Find-Tree-0.test.cpp
documentation_of: data-structure/union-find-tree.hpp
layout: document
title: "Union-Find \u6728"
---

- `<S> struct union_find_tree`  
互いに素な集合を管理する。各集合に可換半群`S`の要素を載せられる。

  - `(constructor)(int n, T x = {})`  
  `n`は要素数。列の全要素を`x`で初期化。

  - `int root(int i)`  
  要素`i`の属する集合の代表元番号を返す。

  - `void unite(int i, int j)`  
  要素`i, j`の属する集合を併合する。
  
  - `bool same(int i, int j)`  
  要素`i, j`が同じ集合に属するかどうか。
  
  - `int size(int i)`  
  要素`i`が属する集合のサイズ。
  
  - `int size(int i)`  
  要素`i`が属する集合のサイズ。
  
  - `T& operator[](int i)`  
  要素`i`が属する集合に載っている可換半群の元。

- `struct S`  
可換半群をなす。
  - `struct T`  
  列に載せる値の型。

  - `T op(T a, T b)`  
  演算。