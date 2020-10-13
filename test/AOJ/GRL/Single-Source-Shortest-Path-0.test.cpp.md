---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n#line 1 \"graph/dijkstra.hpp\"\n#include <limits>\n#include <queue>\n#include\
    \ <vector>\n#include <cassert>\n\ntemplate<typename S>\nstruct dijkstra {\n  \
    \  using T = typename S::T;\n    using E = typename S::E;\n    struct edge {\n\
    \        int to;\n        E cost;\n        edge(int to, E cost) : to(to), cost(cost)\
    \ {}\n    };\n    std::vector<std::vector<edge>> adj;\n    dijkstra(int n) : adj(n)\
    \ {}\n    void add_edge(int from, int to, E cost) { adj[from].emplace_back(to,\
    \ cost); }\n    std::vector<T> get(int s) {\n        std::vector<T> ret(adj.size(),\
    \ S::inf());\n        using P = std::pair<T, int>;\n        auto c = [&](P a,\
    \ P b) -> bool { return S::less(b.first, a.first); };\n        std::priority_queue<P,\
    \ std::vector<P>, decltype(c)> pq(c);\n        ret[s] = S::zero();\n        pq.emplace(ret[s],\
    \ s);\n        while (!pq.empty()) {\n            P p = pq.top();\n          \
    \  pq.pop();\n            int v = p.second;\n            if (S::less(ret[v], p.first))\
    \ { continue; }\n            for (int i = 0; i < adj[v].size(); i++) {\n     \
    \           int u = adj[v][i].to;\n                T dist = S::plus(ret[v], adj[v][i].cost);\n\
    \                if (S::less(dist, ret[u])) { ret[u] = dist, pq.emplace(ret[u],\
    \ u); }\n            }\n        }\n        return ret;\n    }\n};\n\nstruct int_dij\
    \ {\n    using T = int;\n    using E = int;\n    static T zero() { return 0; }\n\
    \    static T inf() { return std::numeric_limits<T>::max(); }\n    static T plus(const\
    \ T &a, const E &b) { return a == inf() ? inf() : a + b; }\n    static bool less(const\
    \ T &a, const T &b) { return a < b; }\n};\n#line 3 \"test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int V,\
    \ E, r;\n    cin >> V >> E >> r;\n    dijkstra<int_dij> dij(V);\n    vector<vector<int>>\
    \ adj(V, vector<int>()), cost(V, vector<int>());\n    for (int i = 0; i < E; i++)\
    \ {\n        int s, t, d;\n        cin >> s >> t >> d;\n        dij.add_edge(s,\
    \ t, d);\n    }\n    vector<int> dist = dij.get(r);\n    for (int i = 0; i < V;\
    \ i++) { cout << (dist[i] == INT_MAX ? \"INF\" : to_string(dist[i])) << endl;\
    \ }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja\"\
    \n#include\"../../../graph/dijkstra.hpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    int V, E, r;\n    cin >> V >> E >> r;\n    dijkstra<int_dij>\
    \ dij(V);\n    vector<vector<int>> adj(V, vector<int>()), cost(V, vector<int>());\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        dij.add_edge(s, t, d);\n    }\n    vector<int> dist = dij.get(r);\n\
    \    for (int i = 0; i < V; i++) { cout << (dist[i] == INT_MAX ? \"INF\" : to_string(dist[i]))\
    \ << endl; }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 19:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
- /verify/test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp.html
title: test/AOJ/GRL/Single-Source-Shortest-Path-0.test.cpp
---
