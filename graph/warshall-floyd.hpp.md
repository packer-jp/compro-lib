---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
    title: test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall-floyd.hpp\"\n#include <limits>\n#include\
    \ <vector>\n#include <functional>\n\ntemplate<typename S>\nstruct warshall_floyd\
    \ {\n    using T = typename S::T;\n    std::vector<std::vector<T>> cost;\n   \
    \ warshall_floyd(int n) : cost(n, std::vector<T>(n, S::inf())) {\n        for\
    \ (int i = 0; i < n; i++) { cost[i][i] = S::zero(); }\n    }\n    void add_edge(int\
    \ from, int to, T cost) { this->cost[from][to] = cost; }\n    std::vector<std::vector<T>>\
    \ get() {\n        int n = cost.size();\n        std::vector<std::vector<T>> ret(cost);\n\
    \        for (int k = 0; k < n; k++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                for (int j = 0; j < n; j++) {\n                    T dist\
    \ = S::plus(ret[i][k], ret[k][j]);\n                    if (S::less(dist, ret[i][j]))\
    \ { ret[i][j] = dist; }\n                }\n            }\n        }\n       \
    \ return ret;\n    }\n};\n\nstruct int_wf {\n    using T = int;\n    static T\
    \ zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const T &b) { return a == inf() || b == inf()\
    \ ? inf() : a + b; }\n    static bool less(const T &a, const T &b) { return a\
    \ < b; }\n};\n"
  code: "#include <limits>\n#include <vector>\n#include <functional>\n\ntemplate<typename\
    \ S>\nstruct warshall_floyd {\n    using T = typename S::T;\n    std::vector<std::vector<T>>\
    \ cost;\n    warshall_floyd(int n) : cost(n, std::vector<T>(n, S::inf())) {\n\
    \        for (int i = 0; i < n; i++) { cost[i][i] = S::zero(); }\n    }\n    void\
    \ add_edge(int from, int to, T cost) { this->cost[from][to] = cost; }\n    std::vector<std::vector<T>>\
    \ get() {\n        int n = cost.size();\n        std::vector<std::vector<T>> ret(cost);\n\
    \        for (int k = 0; k < n; k++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                for (int j = 0; j < n; j++) {\n                    T dist\
    \ = S::plus(ret[i][k], ret[k][j]);\n                    if (S::less(dist, ret[i][j]))\
    \ { ret[i][j] = dist; }\n                }\n            }\n        }\n       \
    \ return ret;\n    }\n};\n\nstruct int_wf {\n    using T = int;\n    static T\
    \ zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const T &b) { return a == inf() || b == inf()\
    \ ? inf() : a + b; }\n    static bool less(const T &a, const T &b) { return a\
    \ < b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2020-10-13 19:48:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
documentation_of: graph/warshall-floyd.hpp
layout: document
title: "Warshall-Floyd \u6CD5"
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