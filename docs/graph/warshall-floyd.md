---
title: Warshall-Floyd 法
documentation_of: graph/warshall-floyd.hpp
---

# Warshall-Floyd 法
グラフの全対間最短距離を求める。

## コンストラクタ
```
warshall_floyd<S> wf(int n)
```
`S`は代数的構造。`n`は頂点数。

## add_edge
```
void add_edge(int from, int to, T cost)
```
`from`から`to`にコスト`cost`の辺を貼る。

## get_dist
```
std::vector<std::vector<T>> get_dist()
```
最短距離行列を返す。時間計算量`O(n^3)`。

# 代数的構造
## T
```
using T
```
辺のコストの型。

## zero
```
T zero()
```
`T`の`plus`に関する単位元。

## inf
```
T inf()
```
`T`の`plus`に関する吸収元、`less`に関する巨大元。

## plus
```
T plus(T a, T b)
```
演算。結合性を要請。

## less
```
bool less(T a, T b)
```
`a < b`かどうか。以下を要請。
- `less(a, b) => less(plus(a, c), plus(b, c))`
- `less(b, c) => less(plus(a, b), plus(a, c))`