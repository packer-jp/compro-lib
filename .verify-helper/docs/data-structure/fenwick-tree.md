---
title: Fenwick 木
documentation_of: data-structure/fenwick-tree.hpp
---

## 概要
数列の一点加算クエリと区間和クエリを列長$N$に対し$O(\log N)$で処理する。

## テンプレートパラメータ
- `typename T`  
基本データ型。

## メンバ
- `(constructor)(int n)`  
列長`n`で初期化。

- `int n`  
列長。

- `void add(int i, T x)`  
要素`i`に`x`を加算する。

- `T get_sum(int l, int r)`  
`[l, r)`の区間和を取得する。