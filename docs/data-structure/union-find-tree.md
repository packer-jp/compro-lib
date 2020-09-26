---
title: Union-Find 木
documentation_of: data-structure/union-find-tree.hpp
---

- `<S> struct union_find_tree`  
互いに素な集合を管理する。各集合に可換半環`S`の要素を載せられる。

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