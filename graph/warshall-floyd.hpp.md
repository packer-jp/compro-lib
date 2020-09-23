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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/warshall-floyd.hpp\"\n#include <limits>\n#include\
    \ <vector>\n#include <functional>\n\ntemplate<typename S>\nstruct warshall_floyd\
    \ {\n    using T = typename S::T;\n    std::vector<std::vector<T>> cost;\n   \
    \ warshall_floyd(int n) : cost(n, std::vector<T>(n, S::inf())) {\n        for\
    \ (int i = 0; i < n; i++) { cost[i][i] = S::zero(); }\n    }\n    void add_edge(int\
    \ from, int to, T cost) { this->cost[from][to] = cost; }\n    std::vector<std::vector<T>>\
    \ get_dist() {\n        int n = cost.size();\n        std::vector<std::vector<T>>\
    \ ret(cost);\n        for (int k = 0; k < n; k++) {\n            for (int i =\
    \ 0; i < n; i++) {\n                for (int j = 0; j < n; j++) {\n          \
    \          T dist = S::plus(ret[i][k], ret[k][j]);\n                    if (S::less(dist,\
    \ ret[i][j])) { ret[i][j] = dist; }\n                }\n            }\n      \
    \  }\n        return ret;\n    }\n};\n\nstruct int_wf {\n    using T = int;\n\
    \    static T zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const T &b) { return a == inf() || b == inf()\
    \ ? inf() : a + b; }\n    static bool less(const T &a, const T &b) { return a\
    \ < b; }\n};\n"
  code: "#include <limits>\n#include <vector>\n#include <functional>\n\ntemplate<typename\
    \ S>\nstruct warshall_floyd {\n    using T = typename S::T;\n    std::vector<std::vector<T>>\
    \ cost;\n    warshall_floyd(int n) : cost(n, std::vector<T>(n, S::inf())) {\n\
    \        for (int i = 0; i < n; i++) { cost[i][i] = S::zero(); }\n    }\n    void\
    \ add_edge(int from, int to, T cost) { this->cost[from][to] = cost; }\n    std::vector<std::vector<T>>\
    \ get_dist() {\n        int n = cost.size();\n        std::vector<std::vector<T>>\
    \ ret(cost);\n        for (int k = 0; k < n; k++) {\n            for (int i =\
    \ 0; i < n; i++) {\n                for (int j = 0; j < n; j++) {\n          \
    \          T dist = S::plus(ret[i][k], ret[k][j]);\n                    if (S::less(dist,\
    \ ret[i][j])) { ret[i][j] = dist; }\n                }\n            }\n      \
    \  }\n        return ret;\n    }\n};\n\nstruct int_wf {\n    using T = int;\n\
    \    static T zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const T &b) { return a == inf() || b == inf()\
    \ ? inf() : a + b; }\n    static bool less(const T &a, const T &b) { return a\
    \ < b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
documentation_of: graph/warshall-floyd.hpp
layout: document
title: "Warshall-Floyd \u6CD5"
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