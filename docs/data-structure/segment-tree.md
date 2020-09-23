---
title: Segment 木
documentation_of: data-structure/segment-tree.hpp
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