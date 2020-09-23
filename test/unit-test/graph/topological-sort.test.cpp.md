---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological-sort.hpp
    title: graph/topological-sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/graph/topological-sort.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"graph/topological-sort.hpp\"\n#include <vector>\n#include <stack>\n\
    \nstd::vector<int> topological_sort(const std::vector<std::vector<int>> &adj)\
    \ {\n    int n = adj.size();\n    std::vector<int> in_deg(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        for (int j = 0; j < adj[i].size(); j++) { in_deg[adj[i][j]]++;\
    \ }\n    }\n    std::vector<int> ret;\n    std::stack<int> stk;\n    for (int\
    \ i = 0; i < n; i++) { if (in_deg[i] == 0) { stk.push(i); }}\n    while (!stk.empty())\
    \ {\n        int i = stk.top();\n        stk.pop();\n        ret.push_back(i);\n\
    \        for (int j = 0; j < adj[i].size(); j++) {\n            if (--in_deg[adj[i][j]]\
    \ == 0) { stk.push(adj[i][j]); }\n        }\n    }\n    return ret;\n}\n#line\
    \ 3 \"test/unit-test/graph/topological-sort.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    constexpr int N = 20, V = 100, E = 1000;\n\
    \    random_device rnd;\n    mt19937 mt(rnd());\n    uniform_int_distribution<>\
    \ uid(0, V - 1);\n    for (int i = 0; i < N; i++) {\n        vector<vector<int>>\
    \ adj(V);\n        bool used[V][V] = {};\n        int src[V];\n        for (int\
    \ i = 0; i < V; i++) { src[i] = i; }\n        shuffle(src, src + N, mt);\n   \
    \     for (int j = 0; j < E; j++) {\n            int u = uid(mt), v = uid(mt);\n\
    \            if (used[u][v]) { continue; }\n            if (src[u] < src[v]) {\n\
    \                adj[u].push_back(v);\n                used[u][v] = true;\n  \
    \          }\n        }\n        vector<int> sorted = topological_sort(adj);\n\
    \        // shuffle(sorted.begin(), sorted.end(), mt);\n        for (int j = 0;\
    \ j < V; j++) {\n            for (int k = j + 1; k < V; k++) {\n             \
    \   assert(!used[sorted[k]][sorted[j]]);\n            }\n        }\n\n    }\n\n\
    \    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../graph/topological-sort.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    constexpr int N = 20, V = 100, E = 1000;\n\
    \    random_device rnd;\n    mt19937 mt(rnd());\n    uniform_int_distribution<>\
    \ uid(0, V - 1);\n    for (int i = 0; i < N; i++) {\n        vector<vector<int>>\
    \ adj(V);\n        bool used[V][V] = {};\n        int src[V];\n        for (int\
    \ i = 0; i < V; i++) { src[i] = i; }\n        shuffle(src, src + N, mt);\n   \
    \     for (int j = 0; j < E; j++) {\n            int u = uid(mt), v = uid(mt);\n\
    \            if (used[u][v]) { continue; }\n            if (src[u] < src[v]) {\n\
    \                adj[u].push_back(v);\n                used[u][v] = true;\n  \
    \          }\n        }\n        vector<int> sorted = topological_sort(adj);\n\
    \        // shuffle(sorted.begin(), sorted.end(), mt);\n        for (int j = 0;\
    \ j < V; j++) {\n            for (int k = j + 1; k < V; k++) {\n             \
    \   assert(!used[sorted[k]][sorted[j]]);\n            }\n        }\n\n    }\n\n\
    \    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - graph/topological-sort.hpp
  isVerificationFile: true
  path: test/unit-test/graph/topological-sort.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/graph/topological-sort.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/graph/topological-sort.test.cpp
- /verify/test/unit-test/graph/topological-sort.test.cpp.html
title: test/unit-test/graph/topological-sort.test.cpp
---