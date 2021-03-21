---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.hpp
    title: "Warshall-Floyd \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja\"\
    \n#line 1 \"graph/warshall-floyd.hpp\"\n#include <limits>\n#include <vector>\n\
    #include <functional>\n\ntemplate<typename S>\nstruct warshall_floyd {\n    using\
    \ T = typename S::T;\n    std::vector<std::vector<T>> cost;\n    warshall_floyd(int\
    \ n) : cost(n, std::vector<T>(n, S::inf())) {\n        for (int i = 0; i < n;\
    \ i++) { cost[i][i] = S::zero(); }\n    }\n    void add_edge(int from, int to,\
    \ T cost) { this->cost[from][to] = cost; }\n    std::vector<std::vector<T>> get()\
    \ {\n        int n = cost.size();\n        std::vector<std::vector<T>> ret(cost);\n\
    \        for (int k = 0; k < n; k++) {\n            for (int i = 0; i < n; i++)\
    \ {\n                for (int j = 0; j < n; j++) {\n                    T dist\
    \ = S::plus(ret[i][k], ret[k][j]);\n                    if (S::less(dist, ret[i][j]))\
    \ { ret[i][j] = dist; }\n                }\n            }\n        }\n       \
    \ return ret;\n    }\n};\n\nstruct int_wf {\n    using T = int;\n    static T\
    \ zero() { return 0; }\n    static T inf() { return std::numeric_limits<T>::max();\
    \ }\n    static T plus(const T &a, const T &b) { return a == inf() || b == inf()\
    \ ? inf() : a + b; }\n    static bool less(const T &a, const T &b) { return a\
    \ < b; }\n};\n#line 3 \"test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int V, E;\n\
    \    cin >> V >> E;\n    warshall_floyd<int_wf> wf(V);\n    for (int i = 0; i\
    \ < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n        wf.add_edge(s,\
    \ t, d);\n    }\n    vector<vector<int>> dist = wf.get();\n    for (int i = 0;\
    \ i < V; i++) {\n        if (dist[i][i] < 0) {\n            cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n            return 0;\n        }\n    }\n    for (int i =\
    \ 0; i < V; i++) {\n        for (int j = 0; j < V; j++) {\n            cout <<\
    \ (dist[i][j] == INT_MAX ? \"INF\" : to_string(dist[i][j])) << (j < V - 1 ? \"\
    \ \" : \"\");\n        }\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja\"\
    \n#include \"../../../graph/warshall-floyd.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    warshall_floyd<int_wf>\
    \ wf(V);\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        wf.add_edge(s, t, d);\n    }\n    vector<vector<int>>\
    \ dist = wf.get();\n    for (int i = 0; i < V; i++) {\n        if (dist[i][i]\
    \ < 0) {\n            cout << \"NEGATIVE CYCLE\" << endl;\n            return\
    \ 0;\n        }\n    }\n    for (int i = 0; i < V; i++) {\n        for (int j\
    \ = 0; j < V; j++) {\n            cout << (dist[i][j] == INT_MAX ? \"INF\" : to_string(dist[i][j]))\
    \ << (j < V - 1 ? \" \" : \"\");\n        }\n        cout << endl;\n    }\n}"
  dependsOn:
  - graph/warshall-floyd.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 19:52:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
- /verify/test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp.html
title: test/AOJ/GRL/All-Pairs-Shortest-Path-0.test.cpp
---
