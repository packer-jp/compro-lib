---
title: Warshall-Floyd 法
documentation_of: graph/warshall-floyd.hpp
---

# Warshall-Floyd 法
グラフの全対間最短距離を求める。

## コンストラクタ
- `warshall_floyd<S> wf(int n);`  
`S`は代数的構造。

## 引数
- `std::vector<std::vector<T>> graph`  
隣接行列形式のグラフ。

- `F f`  
コストの二項演算。結合性を要請する。

- `G g`  
コスト`a, b`を受けとり、`a > b`を返す二項演算。

# 代数的構造
