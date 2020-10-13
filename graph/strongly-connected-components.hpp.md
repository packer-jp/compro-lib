---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
    title: test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/strongly-connected-components.hpp\"\n#include <vector>\n\
    \nstd::vector<int> strongly_connected_components(const std::vector<std::vector<int>>\
    \ &adj) {\n    int n = adj.size();\n    std::vector<int> vs;\n    std::vector<bool>\
    \ visited0(n);\n    auto dfs0 = [&](auto &&dfs0, int cur) -> void {\n        if\
    \ (visited0[cur]) { return; }\n        visited0[cur] = true;\n        for (int\
    \ i = 0; i < adj[cur].size(); i++) { dfs0(dfs0, adj[cur][i]); }\n        vs.push_back(cur);\n\
    \    };\n    for (int i = 0; i < n; i++) { dfs0(dfs0, i); }\n    std::vector<std::vector<int>>\
    \ radj(n);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < adj[i].size();\
    \ j++) { radj[adj[i][j]].push_back(i); }\n    }\n    int k = 0;\n    std::vector<bool>\
    \ visited1(n);\n    std::vector<int> ret(n);\n    auto dfs1 = [&](auto &&dfs1,\
    \ int cur) -> void {\n        visited1[cur] = true;\n        ret[cur] = k;\n \
    \       for (int i = 0; i < radj[cur].size(); i++) {\n            if (!visited1[radj[cur][i]])\
    \ { dfs1(dfs1, radj[cur][i]); }\n        }\n    };\n    for (int i = n - 1; i\
    \ >= 0; i--) { if (!visited1[vs[i]]) { dfs1(dfs1, vs[i]), k++; }}\n    return\
    \ ret;\n}\n"
  code: "#include <vector>\n\nstd::vector<int> strongly_connected_components(const\
    \ std::vector<std::vector<int>> &adj) {\n    int n = adj.size();\n    std::vector<int>\
    \ vs;\n    std::vector<bool> visited0(n);\n    auto dfs0 = [&](auto &&dfs0, int\
    \ cur) -> void {\n        if (visited0[cur]) { return; }\n        visited0[cur]\
    \ = true;\n        for (int i = 0; i < adj[cur].size(); i++) { dfs0(dfs0, adj[cur][i]);\
    \ }\n        vs.push_back(cur);\n    };\n    for (int i = 0; i < n; i++) { dfs0(dfs0,\
    \ i); }\n    std::vector<std::vector<int>> radj(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < adj[i].size(); j++) { radj[adj[i][j]].push_back(i);\
    \ }\n    }\n    int k = 0;\n    std::vector<bool> visited1(n);\n    std::vector<int>\
    \ ret(n);\n    auto dfs1 = [&](auto &&dfs1, int cur) -> void {\n        visited1[cur]\
    \ = true;\n        ret[cur] = k;\n        for (int i = 0; i < radj[cur].size();\
    \ i++) {\n            if (!visited1[radj[cur][i]]) { dfs1(dfs1, radj[cur][i]);\
    \ }\n        }\n    };\n    for (int i = n - 1; i >= 0; i--) { if (!visited1[vs[i]])\
    \ { dfs1(dfs1, vs[i]), k++; }}\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2020-10-13 19:48:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
documentation_of: graph/strongly-connected-components.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---

