---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Articulation-Points-0.test.cpp
    title: test/AOJ/GRL/Articulation-Points-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Bridges-0.test.cpp
    title: test/AOJ/GRL/Bridges-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/low-link.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \nstruct low_link {\n    int n;\n    std::vector<int> ord, low, articulations;\n\
    \    std::vector<std::vector<int>> adj;\n    std::vector<std::pair<int, int>>\
    \ bridges;\n    low_link(const std::vector<std::vector<int>> &adj) : n(adj.size()),\
    \ adj(adj), ord(n), low(n) {\n        std::vector<bool> visited(n);\n        int\
    \ k = 0;\n        auto dfs = [&](auto &&self, int cur, int par) -> void {\n  \
    \          visited[cur] = true;\n            ord[cur] = k++;\n            low[cur]\
    \ = ord[cur];\n            int cnt = 0;\n            bool is_articulation = false;\n\
    \            for (int to : adj[cur]) {\n                if (!visited[to]) {\n\
    \                    cnt++;\n                    self(self, to, cur);\n      \
    \              low[cur] = std::min(low[cur], low[to]);\n                    is_articulation\
    \ |= ord[cur] <= low[to];\n                    if (ord[cur] < low[to]) { bridges.emplace_back(std::minmax(cur,\
    \ to)); }\n                } else if (to != par) { low[cur] = std::min(low[cur],\
    \ ord[to]); }\n            }\n            if (par == -1) { is_articulation = cnt\
    \ >= 2; }\n            if (is_articulation) { articulations.emplace_back(cur);\
    \ }\n        };\n        dfs(dfs, 0, -1);\n    }\n};\n"
  code: "#include <vector>\n#include <algorithm>\n\nstruct low_link {\n    int n;\n\
    \    std::vector<int> ord, low, articulations;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<std::pair<int, int>> bridges;\n    low_link(const std::vector<std::vector<int>>\
    \ &adj) : n(adj.size()), adj(adj), ord(n), low(n) {\n        std::vector<bool>\
    \ visited(n);\n        int k = 0;\n        auto dfs = [&](auto &&self, int cur,\
    \ int par) -> void {\n            visited[cur] = true;\n            ord[cur] =\
    \ k++;\n            low[cur] = ord[cur];\n            int cnt = 0;\n         \
    \   bool is_articulation = false;\n            for (int to : adj[cur]) {\n   \
    \             if (!visited[to]) {\n                    cnt++;\n              \
    \      self(self, to, cur);\n                    low[cur] = std::min(low[cur],\
    \ low[to]);\n                    is_articulation |= ord[cur] <= low[to];\n   \
    \                 if (ord[cur] < low[to]) { bridges.emplace_back(std::minmax(cur,\
    \ to)); }\n                } else if (to != par) { low[cur] = std::min(low[cur],\
    \ ord[to]); }\n            }\n            if (par == -1) { is_articulation = cnt\
    \ >= 2; }\n            if (is_articulation) { articulations.emplace_back(cur);\
    \ }\n        };\n        dfs(dfs, 0, -1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/low-link.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Bridges-0.test.cpp
  - test/AOJ/GRL/Articulation-Points-0.test.cpp
documentation_of: graph/low-link.hpp
layout: document
title: Low Link
---

