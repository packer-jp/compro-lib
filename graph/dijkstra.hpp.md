---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
    title: test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <vector>\n#include <cassert>\n\ntemplate<typename S>\nstruct dijkstra\
    \ {\n    using T = typename S::T;\n    using E = typename S::E;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<std::vector<E>> cost;\n    dijkstra(int n) : adj(n), cost(n)\
    \ {}\n    void add_edge(int from, int to, E cost) { adj[from].emplace_back(to),\
    \ this->cost[from].emplace_back(cost); }\n    std::vector<T> get_dist(int s) {\n\
    \        std::vector<T> ret(adj.size(), S::inf());\n        using P = std::pair<T,\
    \ int>;\n        auto c = [&](P a, P b) -> bool { return S::less(b.first, a.first);\
    \ };\n        std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);\n   \
    \     ret[s] = S::zero();\n        pq.emplace(ret[s], s);\n        while (!pq.empty())\
    \ {\n            P p = pq.top();\n            pq.pop();\n            int v = p.second;\n\
    \            if (S::less(ret[v], p.first)) { continue; }\n            for (int\
    \ i = 0; i < adj[v].size(); i++) {\n                int u = adj[v][i];\n     \
    \           T dist = S::plus(ret[v], cost[v][i]);\n                if (S::less(dist,\
    \ ret[u])) { ret[u] = dist, pq.emplace(ret[u], u); }\n            }\n        }\n\
    \        return ret;\n    }\n};\n\nstruct int_dij {\n    using T = int;\n    using\
    \ E = int;\n    static T zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const E &b) { return a == inf() ? inf() : a\
    \ + b; }\n    static bool less(const T &a, const T &b) { return a < b; }\n};\n"
  code: "#include <limits>\n#include <queue>\n#include <vector>\n#include <cassert>\n\
    \ntemplate<typename S>\nstruct dijkstra {\n    using T = typename S::T;\n    using\
    \ E = typename S::E;\n    std::vector<std::vector<int>> adj;\n    std::vector<std::vector<E>>\
    \ cost;\n    dijkstra(int n) : adj(n), cost(n) {}\n    void add_edge(int from,\
    \ int to, E cost) { adj[from].emplace_back(to), this->cost[from].emplace_back(cost);\
    \ }\n    std::vector<T> get_dist(int s) {\n        std::vector<T> ret(adj.size(),\
    \ S::inf());\n        using P = std::pair<T, int>;\n        auto c = [&](P a,\
    \ P b) -> bool { return S::less(b.first, a.first); };\n        std::priority_queue<P,\
    \ std::vector<P>, decltype(c)> pq(c);\n        ret[s] = S::zero();\n        pq.emplace(ret[s],\
    \ s);\n        while (!pq.empty()) {\n            P p = pq.top();\n          \
    \  pq.pop();\n            int v = p.second;\n            if (S::less(ret[v], p.first))\
    \ { continue; }\n            for (int i = 0; i < adj[v].size(); i++) {\n     \
    \           int u = adj[v][i];\n                T dist = S::plus(ret[v], cost[v][i]);\n\
    \                if (S::less(dist, ret[u])) { ret[u] = dist, pq.emplace(ret[u],\
    \ u); }\n            }\n        }\n        return ret;\n    }\n};\n\nstruct int_dij\
    \ {\n    using T = int;\n    using E = int;\n    static T zero() { return 0; }\n\
    \    static T inf() { return std::numeric_limits<T>::max(); }\n    static T plus(const\
    \ T &a, const E &b) { return a == inf() ? inf() : a + b; }\n    static bool less(const\
    \ T &a, const T &b) { return a < b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

- `<S> struct dijkstra`  
グラフの単一始点最短距離を求める。

  - `(constructor)(int n)`  
  `n`は頂点数。

  - `void add_edge(int from, int to, E cost)`  
  `from`から`to`にコスト`cost`の辺を貼る。

  - `std::vector<T> get_dist(int s)`  
  `s`を始点とする最短距離列を返す。`m`を辺数として、時間計算量`O(m log n)`。


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
    - `!less(plus(a, b), a)`
    - `less(a, b) => less(plus(a, c), plus(b, c))`