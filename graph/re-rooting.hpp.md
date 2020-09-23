---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
    title: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/re-rooting.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ M>\nstd::vector<typename M::T> re_rooting(const std::vector<std::vector<int>>\
    \ &adj,\n                                      const std::vector<std::vector<typename\
    \ M::E>> &cost) {\n    using T = typename M::T;\n    int n = adj.size();\n   \
    \ std::vector<std::vector<T>> dp(n);\n    auto dfs0 = [&](auto &&dfs0, int cur,\
    \ int par) -> T {\n        dp[cur].resize(adj[cur].size());\n        T cum = M::id();\n\
    \        for (int i = 0; i < adj[cur].size(); i++) {\n            if (adj[cur][i]\
    \ == par) { continue; }\n            dp[cur][i] = M::op_TE(dfs0(dfs0, adj[cur][i],\
    \ cur), cost[cur][i]);\n            cum = M::op_TT(cum, dp[cur][i]);\n       \
    \ }\n        return cum;\n    };\n    dfs0(dfs0, 0, -1);\n    std::vector<T> ret(n);\n\
    \    auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop) -> void {\n      \
    \  int m = adj[cur].size();\n        std::vector<T> l_cum(m + 1), r_cum(m + 1);\n\
    \        l_cum[0] = r_cum[m] = M::id();\n        for (int i = 0; i < m; i++) {\n\
    \            if (adj[cur][i] == par) { dp[cur][i] = M::op_TE(drop, cost[cur][i]);\
    \ }\n            l_cum[i + 1] = M::op_TT(l_cum[i], dp[cur][i]);\n        }\n \
    \       for (int i = m - 1; i >= 0; i--) { r_cum[i] = M::op_TT(dp[cur][i], r_cum[i\
    \ + 1]); }\n        for (int i = 0; i < m; i++) {\n            if (adj[cur][i]\
    \ == par) { continue; }\n            dfs1(dfs1, adj[cur][i], cur, M::op_TT(l_cum[i],\
    \ r_cum[i + 1]));\n        }\n        ret[cur] = l_cum[m];\n    };\n    dfs1(dfs1,\
    \ 0, -1, M::id());\n    return ret;\n}\n\nstruct diameter_rr {\n    using T =\
    \ int;\n    using E = int;\n    static T id() { return 0; }\n    static T op_TT(const\
    \ T &a, const T &b) { return std::max(a, b); }\n    static T op_TE(const T &a,\
    \ const E &b) { return a + b; }\n};\n"
  code: "#include <vector>\n\ntemplate<typename M>\nstd::vector<typename M::T> re_rooting(const\
    \ std::vector<std::vector<int>> &adj,\n                                      const\
    \ std::vector<std::vector<typename M::E>> &cost) {\n    using T = typename M::T;\n\
    \    int n = adj.size();\n    std::vector<std::vector<T>> dp(n);\n    auto dfs0\
    \ = [&](auto &&dfs0, int cur, int par) -> T {\n        dp[cur].resize(adj[cur].size());\n\
    \        T cum = M::id();\n        for (int i = 0; i < adj[cur].size(); i++) {\n\
    \            if (adj[cur][i] == par) { continue; }\n            dp[cur][i] = M::op_TE(dfs0(dfs0,\
    \ adj[cur][i], cur), cost[cur][i]);\n            cum = M::op_TT(cum, dp[cur][i]);\n\
    \        }\n        return cum;\n    };\n    dfs0(dfs0, 0, -1);\n    std::vector<T>\
    \ ret(n);\n    auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop) -> void\
    \ {\n        int m = adj[cur].size();\n        std::vector<T> l_cum(m + 1), r_cum(m\
    \ + 1);\n        l_cum[0] = r_cum[m] = M::id();\n        for (int i = 0; i < m;\
    \ i++) {\n            if (adj[cur][i] == par) { dp[cur][i] = M::op_TE(drop, cost[cur][i]);\
    \ }\n            l_cum[i + 1] = M::op_TT(l_cum[i], dp[cur][i]);\n        }\n \
    \       for (int i = m - 1; i >= 0; i--) { r_cum[i] = M::op_TT(dp[cur][i], r_cum[i\
    \ + 1]); }\n        for (int i = 0; i < m; i++) {\n            if (adj[cur][i]\
    \ == par) { continue; }\n            dfs1(dfs1, adj[cur][i], cur, M::op_TT(l_cum[i],\
    \ r_cum[i + 1]));\n        }\n        ret[cur] = l_cum[m];\n    };\n    dfs1(dfs1,\
    \ 0, -1, M::id());\n    return ret;\n}\n\nstruct diameter_rr {\n    using T =\
    \ int;\n    using E = int;\n    static T id() { return 0; }\n    static T op_TT(const\
    \ T &a, const T &b) { return std::max(a, b); }\n    static T op_TE(const T &a,\
    \ const E &b) { return a + b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/re-rooting.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
documentation_of: graph/re-rooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728 DP"
---

