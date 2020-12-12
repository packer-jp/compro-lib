---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/Volume26/Tree-0.test.cpp
    title: test/AOJ/Volume26/Tree-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/heavy-light-decomposition.test.cpp
    title: test/unit-test/graph/heavy-light-decomposition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/heavy-light-decomposition.hpp\"\n#include <algorithm>\n\
    #include <vector>\n#include <cassert>\n\nstruct heavy_light_decomposition {\n\
    \    std::vector<std::vector<int>> adj;\n    std::vector<int> par, sz, depth,\
    \ in, out, head;\n    heavy_light_decomposition(int n) : adj(n), par(n), sz(n),\
    \ depth(n), in(n), out(n), head(n) {}\n    void add_edge(int u, int v) { adj[u].emplace_back(v),\
    \ adj[v].emplace_back(u); }\n    void dfs_size(int v, int p) {\n        sz[v]\
    \ = 1;\n        par[v] = p;\n        if (p != -1) { depth[v] = depth[p] + 1; }\n\
    \        for (int i = 0; i < adj[v].size(); i++) {\n            int &u = adj[v][i];\n\
    \            if (u == p) { continue; }\n            dfs_size(u, v);\n        \
    \    sz[v] += sz[u];\n            if (sz[u] > sz[adj[v][0]]) { std::swap(u, adj[v][0]);\
    \ }\n        }\n    }\n    int dfs_hld(int v, int &t) {\n        in[v] = t++;\n\
    \        for (int i = 0; i < adj[v].size(); i++) {\n            int u = adj[v][i];\n\
    \            if (u == par[v]) { continue; }\n            head[u] = (i == 0 ? head[v]\
    \ : u);\n            dfs_hld(u, t);\n        }\n        return out[v] = t;\n \
    \   }\n    std::vector<int> build(int root) {\n        dfs_size(root, -1);\n \
    \       head[root] = root;\n        int t = 0;\n        dfs_hld(root, t);\n  \
    \      return in;\n    }\n    int get_lca(int u, int v) {\n        while (true)\
    \ {\n            if (in[u] > in[v]) { std::swap(u, v); }\n            if (head[u]\
    \ == head[v]) { return u; }\n            v = par[head[v]];\n        }\n    }\n\
    \    int get_dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[get_lca(u,\
    \ v)]; }\n    std::vector<std::pair<int, int>> get_path(int u, int v, bool edge)\
    \ {\n        std::vector<std::pair<int, int>> a, b;\n        while (true) {\n\
    \            if (head[u] == head[v]) {\n                if (edge) {\n        \
    \            if (in[u] > in[v]) { a.push_back({in[u], in[v] + 1}); }\n       \
    \             if (in[u] < in[v]) { a.push_back({in[u] + 1, in[v]}); }\n      \
    \          } else { a.push_back({in[u], in[v]}); }\n                break;\n \
    \           }\n            if (in[u] > in[v]) {\n                a.push_back({in[u],\
    \ in[head[u]]});\n                u = par[head[u]];\n            } else {\n  \
    \              b.push_back({in[head[v]], in[v]});\n                v = par[head[v]];\n\
    \            }\n        }\n        std::reverse(b.begin(), b.end());\n       \
    \ a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n    std::pair<int,\
    \ int> get_subtree(int v, bool edge) { return {in[v] + edge, out[v] - 1}; }\n\
    };\n"
  code: "#include <algorithm>\n#include <vector>\n#include <cassert>\n\nstruct heavy_light_decomposition\
    \ {\n    std::vector<std::vector<int>> adj;\n    std::vector<int> par, sz, depth,\
    \ in, out, head;\n    heavy_light_decomposition(int n) : adj(n), par(n), sz(n),\
    \ depth(n), in(n), out(n), head(n) {}\n    void add_edge(int u, int v) { adj[u].emplace_back(v),\
    \ adj[v].emplace_back(u); }\n    void dfs_size(int v, int p) {\n        sz[v]\
    \ = 1;\n        par[v] = p;\n        if (p != -1) { depth[v] = depth[p] + 1; }\n\
    \        for (int i = 0; i < adj[v].size(); i++) {\n            int &u = adj[v][i];\n\
    \            if (u == p) { continue; }\n            dfs_size(u, v);\n        \
    \    sz[v] += sz[u];\n            if (sz[u] > sz[adj[v][0]]) { std::swap(u, adj[v][0]);\
    \ }\n        }\n    }\n    int dfs_hld(int v, int &t) {\n        in[v] = t++;\n\
    \        for (int i = 0; i < adj[v].size(); i++) {\n            int u = adj[v][i];\n\
    \            if (u == par[v]) { continue; }\n            head[u] = (i == 0 ? head[v]\
    \ : u);\n            dfs_hld(u, t);\n        }\n        return out[v] = t;\n \
    \   }\n    std::vector<int> build(int root) {\n        dfs_size(root, -1);\n \
    \       head[root] = root;\n        int t = 0;\n        dfs_hld(root, t);\n  \
    \      return in;\n    }\n    int get_lca(int u, int v) {\n        while (true)\
    \ {\n            if (in[u] > in[v]) { std::swap(u, v); }\n            if (head[u]\
    \ == head[v]) { return u; }\n            v = par[head[v]];\n        }\n    }\n\
    \    int get_dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[get_lca(u,\
    \ v)]; }\n    std::vector<std::pair<int, int>> get_path(int u, int v, bool edge)\
    \ {\n        std::vector<std::pair<int, int>> a, b;\n        while (true) {\n\
    \            if (head[u] == head[v]) {\n                if (edge) {\n        \
    \            if (in[u] > in[v]) { a.push_back({in[u], in[v] + 1}); }\n       \
    \             if (in[u] < in[v]) { a.push_back({in[u] + 1, in[v]}); }\n      \
    \          } else { a.push_back({in[u], in[v]}); }\n                break;\n \
    \           }\n            if (in[u] > in[v]) {\n                a.push_back({in[u],\
    \ in[head[u]]});\n                u = par[head[u]];\n            } else {\n  \
    \              b.push_back({in[head[v]], in[v]});\n                v = par[head[v]];\n\
    \            }\n        }\n        std::reverse(b.begin(), b.end());\n       \
    \ a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n    std::pair<int,\
    \ int> get_subtree(int v, bool edge) { return {in[v] + edge, out[v] - 1}; }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: graph/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2020-10-13 19:48:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/graph/heavy-light-decomposition.test.cpp
  - test/AOJ/Volume26/Tree-0.test.cpp
documentation_of: graph/heavy-light-decomposition.hpp
layout: document
title: "HL \u5206\u89E3"
---

