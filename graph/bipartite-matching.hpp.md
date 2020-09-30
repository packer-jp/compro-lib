---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Bipartite-Matching-0.test.cpp
    title: test/AOJ/GRL/Bipartite-Matching-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bipartite-matching.hpp\"\n#include <vector>\n\nstd::vector<std::pair<int,\
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
    \ match[i]}); }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\nstd::vector<std::pair<int, int>> bipartite_matching(const\
    \ std::vector<std::vector<int>> &adj) {\n    int n = adj.size();\n    std::vector<int>\
    \ match(n, -1), used(n);\n    int timestamp = 0;\n    auto dfs = [&](auto &&self,\
    \ int v) -> bool {\n        used[v] = timestamp;\n        for (int i = 0; i <\
    \ adj[v].size(); i++) {\n            int u = adj[v][i], w = match[u];\n      \
    \      if (w < 0 || (used[w] != timestamp && self(self, w))) {\n             \
    \   match[v] = u;\n                match[u] = v;\n                return true;\n\
    \            }\n        }\n        return false;\n    };\n    for (int i = 0;\
    \ i < n; i++) {\n        if (match[i] < 0) {\n            timestamp++;\n     \
    \       dfs(dfs, i);\n        }\n    }\n    std::vector<std::pair<int, int>> ret;\n\
    \    for (int i = 0; i < n; i++) {\n        if (i < match[i]) { ret.push_back({i,\
    \ match[i]}); }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite-matching.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Bipartite-Matching-0.test.cpp
documentation_of: graph/bipartite-matching.hpp
layout: document
title: "\u4E8C\u90E8\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---

