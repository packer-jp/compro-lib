---
title: 遅延評価 Segment 木
documentation_of: data-structure/lazy-segment-tree.hpp
---

## 概要
モノイド列の区間加算クエリと区間和クエリを列長$N$に対し$O(\log N)$で処理する。

## テンプレートパラメータ
- `typename T`  
メインモノイドのデータ型。

- `typename E`  
作用素モノイドのデータ型。

- `typename F`  
メインモノイドの二項演算の型。

- `typename G`  
作用素モノイドの二項演算の型。

- `typename H`  
メインモノイド、作用素モノイド、列長からメインモノイドを得る演算の型。

- `typename ID_T`  
メインモノイドの単位元を返す関数の型。

- `typename ID_E`  
作用素モノイドの単位元を返す関数の型。

## メンバ
- `(constructor)(int n, F f, G g, H h, ID_T id_t, ID_E id_e)`  
列長`n`、各演算で初期化。

- `(constructor)(std::vector<T> src, F f, G g, H h, ID_T id_t, ID_E id_e)`  
`src`を元に、各演算で初期化。

- `int n`  
列長。

- `void add(int l, int r, E x)`  
`[l, r)`に`x`を作用させる。

- `T get_sum(int l, int r)`  
`[l, r)`の区間和を取得する。