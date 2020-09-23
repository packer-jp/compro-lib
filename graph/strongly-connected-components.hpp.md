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
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/strongly-connected-components.hpp\"\n#include <vector>\n\
    \nstd::vector<int> strongly_connected_components(const std::vector<std::vector<int>>\
    \ &adj) {\n    int n = adj.size();\n    std::vector<int> vs;\n    {\n        std::vector<bool>\
    \ visited(n);\n        auto dfs = [&](auto &&self, int cur) -> void {\n      \
    \      if (visited[cur]) { return; }\n            visited[cur] = true;\n     \
    \       for (int i = 0; i < adj[cur].size(); i++) { self(self, adj[cur][i]); }\n\
    \            vs.push_back(cur);\n        };\n        for (int i = 0; i < n; i++)\
    \ { dfs(dfs, i); }\n    }\n    std::vector<int> ret(n);\n    {\n        std::vector<bool>\
    \ visited(n);\n        std::vector<std::vector<int>> radj(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < adj[i].size(); j++) {\
    \ radj[adj[i][j]].push_back(i); }\n        }\n        int k = 0;\n        auto\
    \ dfs = [&](auto &&self, int cur) -> void {\n            visited[cur] = true;\n\
    \            ret[cur] = k;\n            for (int i = 0; i < radj[cur].size();\
    \ i++) {\n                if (!visited[radj[cur][i]]) { self(self, radj[cur][i]);\
    \ }\n            }\n        };\n        for (int i = n - 1; i >= 0; i--) { if\
    \ (!visited[vs[i]]) { dfs(dfs, vs[i]), k++; }}\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\nstd::vector<int> strongly_connected_components(const\
    \ std::vector<std::vector<int>> &adj) {\n    int n = adj.size();\n    std::vector<int>\
    \ vs;\n    {\n        std::vector<bool> visited(n);\n        auto dfs = [&](auto\
    \ &&self, int cur) -> void {\n            if (visited[cur]) { return; }\n    \
    \        visited[cur] = true;\n            for (int i = 0; i < adj[cur].size();\
    \ i++) { self(self, adj[cur][i]); }\n            vs.push_back(cur);\n        };\n\
    \        for (int i = 0; i < n; i++) { dfs(dfs, i); }\n    }\n    std::vector<int>\
    \ ret(n);\n    {\n        std::vector<bool> visited(n);\n        std::vector<std::vector<int>>\
    \ radj(n);\n        for (int i = 0; i < n; i++) {\n            for (int j = 0;\
    \ j < adj[i].size(); j++) { radj[adj[i][j]].push_back(i); }\n        }\n     \
    \   int k = 0;\n        auto dfs = [&](auto &&self, int cur) -> void {\n     \
    \       visited[cur] = true;\n            ret[cur] = k;\n            for (int\
    \ i = 0; i < radj[cur].size(); i++) {\n                if (!visited[radj[cur][i]])\
    \ { self(self, radj[cur][i]); }\n            }\n        };\n        for (int i\
    \ = n - 1; i >= 0; i--) { if (!visited[vs[i]]) { dfs(dfs, vs[i]), k++; }}\n  \
    \  }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
documentation_of: graph/strongly-connected-components.hpp
layout: document
redirect_from:
- /library/graph/strongly-connected-components.hpp
- /library/graph/strongly-connected-components.hpp.html
title: graph/strongly-connected-components.hpp
---
