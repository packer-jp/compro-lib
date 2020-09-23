---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/to-rooted-tree.test.cpp
    title: test/unit-test/graph/to-rooted-tree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/to-rooted-tree.hpp\"\n#include <vector>\n\nstd::vector<int>\
    \ to_rooted_tree(const std::vector<std::vector<int>> &adj, int s) {\n    std::vector<int>\
    \ ret(adj.size());\n    auto dfs = [&](auto &&self, int cur, int par) -> void\
    \ {\n        ret[cur] = par;\n        for (int i = 0; i < adj[cur].size(); i++)\
    \ {\n            if (adj[cur][i] == par) { continue; }\n            self(self,\
    \ adj[cur][i], cur);\n        }\n    };\n    dfs(dfs, s, -1);\n    return ret;\n\
    }\n"
  code: "#include <vector>\n\nstd::vector<int> to_rooted_tree(const std::vector<std::vector<int>>\
    \ &adj, int s) {\n    std::vector<int> ret(adj.size());\n    auto dfs = [&](auto\
    \ &&self, int cur, int par) -> void {\n        ret[cur] = par;\n        for (int\
    \ i = 0; i < adj[cur].size(); i++) {\n            if (adj[cur][i] == par) { continue;\
    \ }\n            self(self, adj[cur][i], cur);\n        }\n    };\n    dfs(dfs,\
    \ s, -1);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/to-rooted-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/graph/to-rooted-tree.test.cpp
documentation_of: graph/to-rooted-tree.hpp
layout: document
redirect_from:
- /library/graph/to-rooted-tree.hpp
- /library/graph/to-rooted-tree.hpp.html
title: graph/to-rooted-tree.hpp
---
