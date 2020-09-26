---
title: Segment 木
documentation_of: data-structure/segment-tree.hpp
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