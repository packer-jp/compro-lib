---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
    title: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/re-rooting.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ S>\nstruct re_rooting {\n    using T = typename S::T;\n    using E = typename\
    \ S::E;\n    struct edge {\n        int to;\n        E cost;\n        edge(int\
    \ to, E cost) : to(to), cost(cost) {}\n    };\n    int m = 0;\n    std::vector<std::vector<edge>>\
    \ adj;\n    re_rooting(int n) : adj(n) {}\n    int add_edge(int u, int v, E u2v,\
    \ E v2u) {\n        adj[u].emplace_back(v, u2v), adj[v].emplace_back(u, v2u);\n\
    \        return m++;\n    }\n    std::vector<T> get() {\n        std::vector<std::vector<T>>\
    \ dp(adj.size());\n        auto dfs0 = [&](auto &&dfs0, int cur, int par) -> T\
    \ {\n            dp[cur].resize(adj[cur].size());\n            T cum = S::id();\n\
    \            for (int i = 0; i < adj[cur].size(); i++) {\n                if (adj[cur][i].to\
    \ == par) { continue; }\n                dp[cur][i] = S::op_TE(dfs0(dfs0, adj[cur][i].to,\
    \ cur), adj[cur][i].cost);\n                cum = S::op_TT(cum, dp[cur][i]);\n\
    \            }\n            return cum;\n        };\n        dfs0(dfs0, 0, -1);\n\
    \        std::vector<T> ret(adj.size());\n        auto dfs1 = [&](auto &&dfs1,\
    \ int cur, int par, T drop) -> void {\n            int k = adj[cur].size();\n\
    \            std::vector<T> l_cum(k + 1), r_cum(k + 1);\n            l_cum[0]\
    \ = r_cum[k] = S::id();\n            for (int i = 0; i < k; i++) {\n         \
    \       if (adj[cur][i].to == par) { dp[cur][i] = S::op_TE(drop, adj[cur][i].cost);\
    \ }\n                l_cum[i + 1] = S::op_TT(l_cum[i], dp[cur][i]);\n        \
    \    }\n            for (int i = k - 1; i >= 0; i--) { r_cum[i] = S::op_TT(dp[cur][i],\
    \ r_cum[i + 1]); }\n            for (int i = 0; i < k; i++) {\n              \
    \  if (adj[cur][i].to == par) { continue; }\n                dfs1(dfs1, adj[cur][i].to,\
    \ cur, S::op_TT(l_cum[i], r_cum[i + 1]));\n            }\n            ret[cur]\
    \ = l_cum[k];\n        };\n        dfs1(dfs1, 0, -1, S::id());\n        return\
    \ ret;\n    }\n};\n\nstruct diameter_rr {\n    using T = int;\n    using E = int;\n\
    \    static T id() { return 0; }\n    static T op_TT(const T &a, const T &b) {\
    \ return std::max(a, b); }\n    static T op_TE(const T &a, const E &b) { return\
    \ a + b; }\n};\n"
  code: "#include <vector>\n\ntemplate<typename S>\nstruct re_rooting {\n    using\
    \ T = typename S::T;\n    using E = typename S::E;\n    struct edge {\n      \
    \  int to;\n        E cost;\n        edge(int to, E cost) : to(to), cost(cost)\
    \ {}\n    };\n    int m = 0;\n    std::vector<std::vector<edge>> adj;\n    re_rooting(int\
    \ n) : adj(n) {}\n    int add_edge(int u, int v, E u2v, E v2u) {\n        adj[u].emplace_back(v,\
    \ u2v), adj[v].emplace_back(u, v2u);\n        return m++;\n    }\n    std::vector<T>\
    \ get() {\n        std::vector<std::vector<T>> dp(adj.size());\n        auto dfs0\
    \ = [&](auto &&dfs0, int cur, int par) -> T {\n            dp[cur].resize(adj[cur].size());\n\
    \            T cum = S::id();\n            for (int i = 0; i < adj[cur].size();\
    \ i++) {\n                if (adj[cur][i].to == par) { continue; }\n         \
    \       dp[cur][i] = S::op_TE(dfs0(dfs0, adj[cur][i].to, cur), adj[cur][i].cost);\n\
    \                cum = S::op_TT(cum, dp[cur][i]);\n            }\n           \
    \ return cum;\n        };\n        dfs0(dfs0, 0, -1);\n        std::vector<T>\
    \ ret(adj.size());\n        auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop)\
    \ -> void {\n            int k = adj[cur].size();\n            std::vector<T>\
    \ l_cum(k + 1), r_cum(k + 1);\n            l_cum[0] = r_cum[k] = S::id();\n  \
    \          for (int i = 0; i < k; i++) {\n                if (adj[cur][i].to ==\
    \ par) { dp[cur][i] = S::op_TE(drop, adj[cur][i].cost); }\n                l_cum[i\
    \ + 1] = S::op_TT(l_cum[i], dp[cur][i]);\n            }\n            for (int\
    \ i = k - 1; i >= 0; i--) { r_cum[i] = S::op_TT(dp[cur][i], r_cum[i + 1]); }\n\
    \            for (int i = 0; i < k; i++) {\n                if (adj[cur][i].to\
    \ == par) { continue; }\n                dfs1(dfs1, adj[cur][i].to, cur, S::op_TT(l_cum[i],\
    \ r_cum[i + 1]));\n            }\n            ret[cur] = l_cum[k];\n        };\n\
    \        dfs1(dfs1, 0, -1, S::id());\n        return ret;\n    }\n};\n\nstruct\
    \ diameter_rr {\n    using T = int;\n    using E = int;\n    static T id() { return\
    \ 0; }\n    static T op_TT(const T &a, const T &b) { return std::max(a, b); }\n\
    \    static T op_TE(const T &a, const E &b) { return a + b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/re-rooting.hpp
  requiredBy: []
  timestamp: '2020-10-13 20:08:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
documentation_of: graph/re-rooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728 DP"
---

