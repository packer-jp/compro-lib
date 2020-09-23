---
title: Warshall-Floyd 法
documentation_of: graph/warshall-floyd.hpp
---

- `<S> struct warshall_floyd`  
  グラフの全対間最短距離を求める。

  - `(constructor)(int n)`  
    `n`は頂点数。

  - `void add_edge(int from, int to, T cost)`  
    `from`から`to`にコスト`cost`の辺を貼る。

  - `std::vector<std::vector<T>> get_dist()`  
    最短距離行列を返す。時間計算量`O(n^3)`。

- `struct S`
  - `using T`  
    辺のコストの型。

  - `T zero()`  
    `T`の`plus`に関する単位元。

  - `T inf()`  
    `T`の`plus`に関する吸収元、`less`に関する巨大元。

  - `T plus(T a, T b)`  
    演算。結合性を要請。

  - `bool less(T a, T b)`  
    `a < b`かどうか。以下を要請。
    - `less(a, b) => less(plus(a, c), plus(b, c))`
    - `less(b, c) => less(plus(a, b), plus(a, c))`