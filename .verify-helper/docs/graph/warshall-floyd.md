---
title: Warshall-Floyd 法
documentation_of: graph/warshall-floyd.hpp
---

## 概要
グラフの全対間最短距離を頂点数$N$に対し$O(N^3)$で求める。

## テンプレートパラメータ
- `typename T`  
コストのデータ型。

## 引数
- `std::vector<std::vector<T>> graph`  
隣接行列形式のグラフ。

- `F f`  
コストの二項演算。結合性を要請する。

- `G g`  
コスト`a, b`を受けとり、`a > b`を返す二項演算。