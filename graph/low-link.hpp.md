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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/low-link.hpp\"\n#include <vector>\n#include <algorithm>\n\
    \nstruct low_link {\n    struct edge {\n        int to, idx;\n        edge(int\
    \ to, int idx) : to(to), idx(idx) {}\n    };\n    int m = 0;\n    std::vector<std::vector<edge>>\
    \ adj;\n    low_link(int n) : adj(n) {}\n    int add_edge(int u, int v) {\n  \
    \      adj[u].emplace_back(v, m), adj[v].emplace_back(u, m);\n        return m++;\n\
    \    }\n    std::pair<std::vector<int>, std::vector<int>> get() {\n        int\
    \ n = adj.size();\n        std::vector<int> ord(n), low(n), articulations, bridges;\n\
    \        std::vector<bool> visited(n);\n        int k = 0;\n        auto dfs =\
    \ [&](auto &&dfs, int cur, int par) -> void {\n            visited[cur] = true;\n\
    \            ord[cur] = k++;\n            low[cur] = ord[cur];\n            int\
    \ cnt = 0;\n            bool is_articulation = false;\n            for (auto[to,\
    \ idx] : adj[cur]) {\n                if (!visited[to]) {\n                  \
    \  cnt++;\n                    dfs(dfs, to, cur);\n                    low[cur]\
    \ = std::min(low[cur], low[to]);\n                    is_articulation |= ord[cur]\
    \ <= low[to];\n                    if (ord[cur] < low[to]) { bridges.emplace_back(idx);\
    \ }\n                } else if (to != par) { low[cur] = std::min(low[cur], ord[to]);\
    \ }\n            }\n            if (par == -1) { is_articulation = cnt >= 2; }\n\
    \            if (is_articulation) { articulations.emplace_back(cur); }\n     \
    \   };\n        dfs(dfs, 0, -1);\n        return {articulations, bridges};\n \
    \   }\n};\n"
  code: "#include <vector>\n#include <algorithm>\n\nstruct low_link {\n    struct\
    \ edge {\n        int to, idx;\n        edge(int to, int idx) : to(to), idx(idx)\
    \ {}\n    };\n    int m = 0;\n    std::vector<std::vector<edge>> adj;\n    low_link(int\
    \ n) : adj(n) {}\n    int add_edge(int u, int v) {\n        adj[u].emplace_back(v,\
    \ m), adj[v].emplace_back(u, m);\n        return m++;\n    }\n    std::pair<std::vector<int>,\
    \ std::vector<int>> get() {\n        int n = adj.size();\n        std::vector<int>\
    \ ord(n), low(n), articulations, bridges;\n        std::vector<bool> visited(n);\n\
    \        int k = 0;\n        auto dfs = [&](auto &&dfs, int cur, int par) -> void\
    \ {\n            visited[cur] = true;\n            ord[cur] = k++;\n         \
    \   low[cur] = ord[cur];\n            int cnt = 0;\n            bool is_articulation\
    \ = false;\n            for (auto[to, idx] : adj[cur]) {\n                if (!visited[to])\
    \ {\n                    cnt++;\n                    dfs(dfs, to, cur);\n    \
    \                low[cur] = std::min(low[cur], low[to]);\n                   \
    \ is_articulation |= ord[cur] <= low[to];\n                    if (ord[cur] <\
    \ low[to]) { bridges.emplace_back(idx); }\n                } else if (to != par)\
    \ { low[cur] = std::min(low[cur], ord[to]); }\n            }\n            if (par\
    \ == -1) { is_articulation = cnt >= 2; }\n            if (is_articulation) { articulations.emplace_back(cur);\
    \ }\n        };\n        dfs(dfs, 0, -1);\n        return {articulations, bridges};\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/low-link.hpp
  requiredBy: []
  timestamp: '2020-10-13 20:30:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Articulation-Points-0.test.cpp
  - test/AOJ/GRL/Bridges-0.test.cpp
documentation_of: graph/low-link.hpp
layout: document
title: Low Link
---

