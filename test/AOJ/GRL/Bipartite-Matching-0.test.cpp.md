---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite-matching.hpp
    title: graph/bipartite-matching.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/GRL/Bipartite-Matching-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja\"\
    \n#line 1 \"graph/bipartite-matching.hpp\"\n#include <vector>\n\nstd::vector<std::pair<int,\
    \ int>> bipartite_matching(const std::vector<std::vector<int>> &adj) {\n    int\
    \ n = adj.size();\n    std::vector<int> match(n, -1), used(n);\n    int timestamp\
    \ = 0;\n    auto dfs = [&](auto &&self, int v) -> bool {\n        used[v] = timestamp;\n\
    \        for (int i = 0; i < adj[v].size(); i++) {\n            int u = adj[v][i],\
    \ w = match[u];\n            if (w < 0 || (used[w] != timestamp && self(self,\
    \ w))) {\n                match[v] = u;\n                match[u] = v;\n     \
    \           return true;\n            }\n        }\n        return false;\n  \
    \  };\n    for (int i = 0; i < n; i++) {\n        if (match[i] < 0) {\n      \
    \      timestamp++;\n            dfs(dfs, i);\n        }\n    }\n    std::vector<std::pair<int,\
    \ int>> ret;\n    for (int i = 0; i < n; i++) {\n        if (i < match[i]) { ret.push_back({i,\
    \ match[i]}); }\n    }\n    return ret;\n}\n#line 3 \"test/AOJ/GRL/Bipartite-Matching-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int X,\
    \ Y, E;\n    cin >> X >> Y >> E;\n    vector<vector<int>> adj(X + Y);\n    for\
    \ (int i = 0; i < E; i++) {\n        int x, y;\n        cin >> x >> y;\n     \
    \   adj[x].push_back(X + y), adj[X + y].push_back(x);\n    }\n    cout << bipartite_matching(adj).size()\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja\"\
    \n#include\"../../../graph/bipartite-matching.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int X, Y, E;\n    cin >> X >> Y >> E;\n\
    \    vector<vector<int>> adj(X + Y);\n    for (int i = 0; i < E; i++) {\n    \
    \    int x, y;\n        cin >> x >> y;\n        adj[x].push_back(X + y), adj[X\
    \ + y].push_back(x);\n    }\n    cout << bipartite_matching(adj).size() << endl;\n\
    }"
  dependsOn:
  - graph/bipartite-matching.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Bipartite-Matching-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Bipartite-Matching-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Bipartite-Matching-0.test.cpp
- /verify/test/AOJ/GRL/Bipartite-Matching-0.test.cpp.html
title: test/AOJ/GRL/Bipartite-Matching-0.test.cpp
---
