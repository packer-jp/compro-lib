---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman-ford.hpp
    title: "Bellman-Ford \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja
  bundledCode: "#line 1 \"test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja\"\
    \n#line 1 \"graph/bellman-ford.hpp\"\n#include <limits>\n#include <vector>\n#include\
    \ <functional>\n#include <cassert>\n\ntemplate<typename S>\nstruct bellman_ford\
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
    \ }\n    static bool less(const T &a, const T &b) { return a < b; }\n};\n#line\
    \ 3 \"test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp\"\n\n\
    #include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int V, E, r;\n\
    \    cin >> V >> E >> r;\n    bellman_ford<int_bf> bf(V);\n    for (int i = 0;\
    \ i < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n        bf.add_edge(s,\
    \ t, d);\n    }\n    vector<int> dist = bf.get(r);\n    if (dist.empty()) {\n\
    \        cout << \"NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n    for\
    \ (int i = 0; i < V; i++) { cout << (dist[i] < INT_MAX ? to_string(dist[i]) :\
    \ \"INF\") << endl; }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja\"\
    \n#include\"../../../graph/bellman-ford.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int V, E, r;\n    cin >> V >> E >> r;\n\
    \    bellman_ford<int_bf> bf(V);\n    for (int i = 0; i < E; i++) {\n        int\
    \ s, t, d;\n        cin >> s >> t >> d;\n        bf.add_edge(s, t, d);\n    }\n\
    \    vector<int> dist = bf.get(r);\n    if (dist.empty()) {\n        cout << \"\
    NEGATIVE CYCLE\" << endl;\n        return 0;\n    }\n    for (int i = 0; i < V;\
    \ i++) { cout << (dist[i] < INT_MAX ? to_string(dist[i]) : \"INF\") << endl; }\n\
    }"
  dependsOn:
  - graph/bellman-ford.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 19:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
- /verify/test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp.html
title: test/AOJ/GRL/Single-Source-Shortest-Path-Negative-Edges-0.test.cpp
---
