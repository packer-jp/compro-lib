---
title: Bellman-Ford 法
documentation_of: graph/bellman-ford.hpp
---

- `<S> struct bellman_ford`  
グラフの単一始点最短距離を求める。

  - `(constructor)(int n)`  
  `n`は頂点数。

  - `void add_edge(int from, int to, E cost)`  
  `from`から`to`にコスト`cost`の辺を貼る。

  - `std::vector<T> get_dist(int s)`  
  `s`を始点とする最短距離列を返す。`m`を辺数として、時間計算量`O(nm)`。


- `struct S`
  - `using T`  
  頂点の距離の型。

  - `using E`  
  辺のコストの型。

  - `T zero()`  
  `T`の`plus`に関する単位元。

  - `T inf()`  
  `T`の`plus`に関する吸収元、`less`に関する巨大元。

  - `T plus(T a, E b)`  
  演算。

  - `bool less(T a, T b)`  
  `a < b`かどうか。以下を要請。
    - `less(a, b) => less(plus(a, c), plus(b, c))`