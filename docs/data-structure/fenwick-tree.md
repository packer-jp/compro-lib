---
title: Fenwick 木
documentation_of: data-structure/fenwick-tree.hpp
---

- `<S> struct fenwick_tree`  
列への一点加算クエリと区間和クエリを処理する。

  - `(constructor)(int n)`  
  `n`は頂点数。列の全要素を単位元で初期化。

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
  - `using T`  
  列に載せる値の型。

  - `T zero()`  
  `T`の`plus`に関する単位元。
  
  - `T plus(T a, T b)`  
  演算。