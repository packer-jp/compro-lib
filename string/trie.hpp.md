---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/string/trie.test.cpp
    title: test/unit-test/string/trie.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/trie.hpp\"\n#include <vector>\n\ntemplate<int K>\n\
    struct trie {\n    std::vector<std::vector<int>> adj;\n    std::vector<int> cnt;\n\
    \    trie() : adj(1, std::vector<int>(K, -1)), cnt(1) {}\n    void insert(const\
    \ std::vector<int> &s, int m = 1) {\n        int cur = 0;\n        for (int c:s)\
    \ {\n            if (adj[cur][c] == -1) {\n                adj[cur][c] = adj.size();\n\
    \                adj.emplace_back(K, -1);\n                cnt.emplace_back(0);\n\
    \            }\n            cur = adj[cur][c];\n        }\n        cnt[cur] +=\
    \ m;\n    }\n    std::vector<int> count_prefix(const std::vector<int> &s) {\n\
    \        std::vector<int> ret(s.size() + 1);\n        ret[0] = cnt[0];\n     \
    \   int cur = 0;\n        for (int i = 0; i < s.size(); i++) {\n            if\
    \ (adj[cur][s[i]] == -1) { break; }\n            cur = adj[cur][s[i]];\n     \
    \       ret[i + 1] = cnt[cur];\n        }\n        return ret;\n    }\n};\n"
  code: "#include <vector>\n\ntemplate<int K>\nstruct trie {\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> cnt;\n    trie() : adj(1, std::vector<int>(K, -1)),\
    \ cnt(1) {}\n    void insert(const std::vector<int> &s, int m = 1) {\n       \
    \ int cur = 0;\n        for (int c:s) {\n            if (adj[cur][c] == -1) {\n\
    \                adj[cur][c] = adj.size();\n                adj.emplace_back(K,\
    \ -1);\n                cnt.emplace_back(0);\n            }\n            cur =\
    \ adj[cur][c];\n        }\n        cnt[cur] += m;\n    }\n    std::vector<int>\
    \ count_prefix(const std::vector<int> &s) {\n        std::vector<int> ret(s.size()\
    \ + 1);\n        ret[0] = cnt[0];\n        int cur = 0;\n        for (int i =\
    \ 0; i < s.size(); i++) {\n            if (adj[cur][s[i]] == -1) { break; }\n\
    \            cur = adj[cur][s[i]];\n            ret[i + 1] = cnt[cur];\n     \
    \   }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/string/trie.test.cpp
documentation_of: string/trie.hpp
layout: document
title: Trie
---

