---
title: 遅延評価 Segment 木
documentation_of: data-structure/lazy-segment-tree.hpp
---

- `<S> struct lazy_segment_tree`  
  列への区間適用クエリと区間演算クエリを処理する。

  - `(constructor)(int n)`  
    `n`は要素数。列の全要素を単位元で初期化。

  - `(constructor)(std::vector<std::vector<T>> src)`  
    `n`は要素数。列を`src`で初期化。

  - `void apply(int l, int r, T x)`  
    `[l, r)`を`x`に適用。

  - `T fold(int l, int r)`  
    `[l, r)`の区間演算を返す。

- `struct S`  
  列に載せる値、作用素はいずれもモノイドをなす。  

  - `struct T`  
    列に載せる値の型。

  - `struct E`  
    作用素の型。

  - `T id_T()`  
    `T`の`op_TT`に関する単位元。

  - `E id_E()`  
    `E`の`op_EE`に関する単位元。

  - `T op_TT(T a, T b)`  
    `T`と`T`の演算。

  - `T op_TE(T a, E b)`  
    `T`と`E`の演算。

  - `E op_EE(E a, E b)`  
    `E`と`E`の演算。  

  これらの演算は以下を満たす。  
  - `op_TE(op_TT(a, b), c) = op_TT(op_TE(a, c), op_TE(b, c))`
  - `op_TE(op_TE(a, b), c) = op_TE(a, op_EE(b, c))`
