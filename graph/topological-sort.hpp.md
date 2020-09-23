---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/topological-sort.test.cpp
    title: test/unit-test/graph/topological-sort.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/topological-sort.hpp\"\n#include <vector>\n#include\
    \ <stack>\n\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>\
    \ &adj) {\n    int n = adj.size();\n    std::vector<int> in_deg(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < adj[i].size(); j++) { in_deg[adj[i][j]]++;\
    \ }\n    }\n    std::vector<int> ret;\n    std::stack<int> stk;\n    for (int\
    \ i = 0; i < n; i++) { if (in_deg[i] == 0) { stk.push(i); }}\n    while (!stk.empty())\
    \ {\n        int i = stk.top();\n        stk.pop();\n        ret.push_back(i);\n\
    \        for (int j = 0; j < adj[i].size(); j++) {\n            if (--in_deg[adj[i][j]]\
    \ == 0) { stk.push(adj[i][j]); }\n        }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <stack>\n\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<int>> &adj) {\n    int n = adj.size();\n    std::vector<int>\
    \ in_deg(n);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < adj[i].size();\
    \ j++) { in_deg[adj[i][j]]++; }\n    }\n    std::vector<int> ret;\n    std::stack<int>\
    \ stk;\n    for (int i = 0; i < n; i++) { if (in_deg[i] == 0) { stk.push(i); }}\n\
    \    while (!stk.empty()) {\n        int i = stk.top();\n        stk.pop();\n\
    \        ret.push_back(i);\n        for (int j = 0; j < adj[i].size(); j++) {\n\
    \            if (--in_deg[adj[i][j]] == 0) { stk.push(adj[i][j]); }\n        }\n\
    \    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/graph/topological-sort.test.cpp
documentation_of: graph/topological-sort.hpp
layout: document
redirect_from:
- /library/graph/topological-sort.hpp
- /library/graph/topological-sort.hpp.html
title: graph/topological-sort.hpp
---
