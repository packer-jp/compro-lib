---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
    title: test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman-ford.hpp\"\n#include <limits>\n#include <vector>\n\
    #include <functional>\n#include <cassert>\n\ntemplate<typename S>\nstruct bellman_ford\
    \ {\n    using T = typename S::T;\n    using E = typename S::E;\n    struct edge\
    \ {\n        int from, to;\n        E cost;\n        edge(int from, int to, E\
    \ cost) : from(from), to(to), cost(cost) {}\n    };\n    int n;\n    std::vector<edge>\
    \ edges;\n    bellman_ford(int n) : n(n) {}\n    void add_edge(int from, int to,\
    \ E cost) { edges.emplace_back(from, to, cost); }\n    std::vector<T> get(int\
    \ s) {\n        std::vector<T> ret(n, S::inf());\n        ret[s] = S::zero();\n\
    \        for (int i = 0; i < n; i++) {\n            bool upd = false;\n      \
    \      for (int j = 0; j < edges.size(); j++) {\n                edge e = edges[j];\n\
    \                T dist = S::plus(ret[e.from], e.cost);\n                if (S::less(dist,\
    \ ret[e.to])) { ret[e.to] = dist, upd = true; }\n            }\n            if\
    \ (!upd) { return ret; }\n        }\n        return std::vector<T>();\n    }\n\
    };\n\nstruct int_bf {\n    using T = int;\n    using E = int;\n    static T zero()\
    \ { return 0; }\n    static T inf() { return std::numeric_limits<T>::max(); }\n\
    \    static T plus(const T &a, const E &b) { return a == inf() ? inf() : a + b;\
    \ }\n    static bool less(const T &a, const T &b) { return a < b; }\n};\n"
  code: "#include <limits>\n#include <vector>\n#include <functional>\n#include <cassert>\n\
    \ntemplate<typename S>\nstruct bellman_ford {\n    using T = typename S::T;\n\
    \    using E = typename S::E;\n    struct edge {\n        int from, to;\n    \
    \    E cost;\n        edge(int from, int to, E cost) : from(from), to(to), cost(cost)\
    \ {}\n    };\n    int n;\n    std::vector<edge> edges;\n    bellman_ford(int n)\
    \ : n(n) {}\n    void add_edge(int from, int to, E cost) { edges.emplace_back(from,\
    \ to, cost); }\n    std::vector<T> get(int s) {\n        std::vector<T> ret(n,\
    \ S::inf());\n        ret[s] = S::zero();\n        for (int i = 0; i < n; i++)\
    \ {\n            bool upd = false;\n            for (int j = 0; j < edges.size();\
    \ j++) {\n                edge e = edges[j];\n                T dist = S::plus(ret[e.from],\
    \ e.cost);\n                if (S::less(dist, ret[e.to])) { ret[e.to] = dist,\
    \ upd = true; }\n            }\n            if (!upd) { return ret; }\n      \
    \  }\n        return std::vector<T>();\n    }\n};\n\nstruct int_bf {\n    using\
    \ T = int;\n    using E = int;\n    static T zero() { return 0; }\n    static\
    \ T inf() { return std::numeric_limits<T>::max(); }\n    static T plus(const T\
    \ &a, const E &b) { return a == inf() ? inf() : a + b; }\n    static bool less(const\
    \ T &a, const T &b) { return a < b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2020-10-13 19:48:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
documentation_of: graph/bellman-ford.hpp
layout: document
title: "Bellman-Ford \u6CD5"
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