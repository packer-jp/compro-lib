---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Maximum-Flow-1.test.cpp
    title: test/AOJ/GRL/Maximum-Flow-1.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/dinic.hpp\"\n#include <limits>\n#include <map>\n#include\
    \ <queue>\n#include <vector>\n\ntemplate<typename M>\nstruct dinic {\n    using\
    \ T = typename M::T;\n    struct edge {\n        int to, rev;\n        T cap;\n\
    \        bool is_rev;\n    };\n    int n;\n    std::vector<std::vector<edge>>\
    \ graph;\n    std::vector<int> level, iter;\n    void add_edge(int from, int to,\
    \ T cap) {\n        graph[from].push_back({to, (int) graph[to].size(), cap, false});\n\
    \        graph[to].push_back({from, (int) graph[from].size() - 1, M::id(), true});\n\
    \    }\n    dinic(const std::vector<std::vector<int>> &adj, const std::vector<std::vector<typename\
    \ M::T>> &cap)\n        : n(adj.size()), graph(n), level(n), iter(n) {\n     \
    \   for (int i = 0; i < n; i++) {\n            for (int j = 0; j < adj[i].size();\
    \ j++) { add_edge(i, adj[i][j], cap[i][j]); }\n        }\n    }\n    void bfs(int\
    \ s) {\n        fill(level.begin(), level.end(), -1);\n        std::queue<int>\
    \ que;\n        level[s] = 0;\n        que.push(s);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (int i = 0; i < graph[v].size(); i++) {\n                edge &e = graph[v][i];\n\
    \                if (M::is_id(e.cap) || level[e.to] >= 0) { continue; }\n    \
    \            level[e.to] = level[v] + 1;\n                que.push(e.to);\n  \
    \          }\n        }\n    }\n    T dfs(int v, int t, T f) {\n        if (v\
    \ == t) { return f; }\n        for (int &i = iter[v]; i < graph[v].size(); i++)\
    \ {\n            edge &e = graph[v][i];\n            if (level[v] >= level[e.to]\
    \ || M::is_id(e.cap)) { continue; }\n            T d = dfs(e.to, t, M::gr(f, e.cap)\
    \ ? e.cap : f);\n            if (M::is_id(d)) { continue; }\n            e.cap\
    \ = M::op(e.cap, M::inv(d));\n            graph[e.to][e.rev].cap = M::op(graph[e.to][e.rev].cap,\
    \ d);\n            return d;\n        }\n        return M::id();\n    }\n    T\
    \ calc_max_flow(int s, int t, T lim) {\n        T ret = M::id();\n        while\
    \ (true) {\n            bfs(s);\n            if (level[t] < 0 || M::is_id(lim))\
    \ { return ret; }\n            fill(iter.begin(), iter.end(), 0);\n          \
    \  T f;\n            while (!M::is_id(f = dfs(s, t, lim))) {\n               \
    \ ret = M::op(ret, f);\n                lim = M::op(lim, M::inv(f));\n       \
    \     }\n        }\n    }\n    T calc_max_flow(int s, int t) { return calc_max_flow(s,\
    \ t, M::ab()); }\n    std::map<std::pair<int, int>, T> get_max_flow() {\n    \
    \    std::map<std::pair<int, int>, T> ret;\n        for (int i = 0; i < n; i++)\
    \ {\n            for (int j = 0; j < graph[i].size(); j++) {\n               \
    \ edge &e = graph[i][j];\n                if (e.is_rev) { ret[{e.to, i}] = e.cap;\
    \ }\n            }\n        }\n        return ret;\n    }\n    std::map<std::pair<int,\
    \ int>, T> get_min_cut(int s) {\n        std::map<std::pair<int, int>, T> ret;\n\
    \        std::vector<int> visited(n);\n        std::queue<int> que;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            if (visited[v]) { continue; }\n            visited[v]\
    \ = true;\n            for (int i = 0; i < graph[v].size(); i++) {\n         \
    \       edge &e = graph[v][i];\n                if (!M::is_id(e.cap)) { que.push(e.to);\
    \ }\n            }\n        }\n        for (int i = 0; i < n; i++) {\n       \
    \     if (visited[i]) { continue; }\n            for (int j = 0; j < graph[i].size();\
    \ j++) {\n                edge &e = graph[i][j];\n                if (e.is_rev\
    \ && visited[e.to]) { ret[{e.to, i}] = e.cap; }\n            }\n        }\n  \
    \      return ret;\n    }\n};\n\nstruct int_dinic {\n    using T = int;\n    static\
    \ T id() { return 0; }\n    static T ab() { return std::numeric_limits<T>::max();\
    \ }\n    static T inv(const T &a) { return -a; }\n    static T op(const T &a,\
    \ const T &b) { return a + b; }\n    static bool gr(const T &a, const T &b) {\
    \ return a > b; }\n    static bool is_id(const T &a) { return a == id(); };\n\
    };\n"
  code: "#include <limits>\n#include <map>\n#include <queue>\n#include <vector>\n\n\
    template<typename M>\nstruct dinic {\n    using T = typename M::T;\n    struct\
    \ edge {\n        int to, rev;\n        T cap;\n        bool is_rev;\n    };\n\
    \    int n;\n    std::vector<std::vector<edge>> graph;\n    std::vector<int> level,\
    \ iter;\n    void add_edge(int from, int to, T cap) {\n        graph[from].push_back({to,\
    \ (int) graph[to].size(), cap, false});\n        graph[to].push_back({from, (int)\
    \ graph[from].size() - 1, M::id(), true});\n    }\n    dinic(const std::vector<std::vector<int>>\
    \ &adj, const std::vector<std::vector<typename M::T>> &cap)\n        : n(adj.size()),\
    \ graph(n), level(n), iter(n) {\n        for (int i = 0; i < n; i++) {\n     \
    \       for (int j = 0; j < adj[i].size(); j++) { add_edge(i, adj[i][j], cap[i][j]);\
    \ }\n        }\n    }\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        std::queue<int> que;\n        level[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (int i = 0; i < graph[v].size(); i++) {\n     \
    \           edge &e = graph[v][i];\n                if (M::is_id(e.cap) || level[e.to]\
    \ >= 0) { continue; }\n                level[e.to] = level[v] + 1;\n         \
    \       que.push(e.to);\n            }\n        }\n    }\n    T dfs(int v, int\
    \ t, T f) {\n        if (v == t) { return f; }\n        for (int &i = iter[v];\
    \ i < graph[v].size(); i++) {\n            edge &e = graph[v][i];\n          \
    \  if (level[v] >= level[e.to] || M::is_id(e.cap)) { continue; }\n           \
    \ T d = dfs(e.to, t, M::gr(f, e.cap) ? e.cap : f);\n            if (M::is_id(d))\
    \ { continue; }\n            e.cap = M::op(e.cap, M::inv(d));\n            graph[e.to][e.rev].cap\
    \ = M::op(graph[e.to][e.rev].cap, d);\n            return d;\n        }\n    \
    \    return M::id();\n    }\n    T calc_max_flow(int s, int t, T lim) {\n    \
    \    T ret = M::id();\n        while (true) {\n            bfs(s);\n         \
    \   if (level[t] < 0 || M::is_id(lim)) { return ret; }\n            fill(iter.begin(),\
    \ iter.end(), 0);\n            T f;\n            while (!M::is_id(f = dfs(s, t,\
    \ lim))) {\n                ret = M::op(ret, f);\n                lim = M::op(lim,\
    \ M::inv(f));\n            }\n        }\n    }\n    T calc_max_flow(int s, int\
    \ t) { return calc_max_flow(s, t, M::ab()); }\n    std::map<std::pair<int, int>,\
    \ T> get_max_flow() {\n        std::map<std::pair<int, int>, T> ret;\n       \
    \ for (int i = 0; i < n; i++) {\n            for (int j = 0; j < graph[i].size();\
    \ j++) {\n                edge &e = graph[i][j];\n                if (e.is_rev)\
    \ { ret[{e.to, i}] = e.cap; }\n            }\n        }\n        return ret;\n\
    \    }\n    std::map<std::pair<int, int>, T> get_min_cut(int s) {\n        std::map<std::pair<int,\
    \ int>, T> ret;\n        std::vector<int> visited(n);\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            if (visited[v]) { continue;\
    \ }\n            visited[v] = true;\n            for (int i = 0; i < graph[v].size();\
    \ i++) {\n                edge &e = graph[v][i];\n                if (!M::is_id(e.cap))\
    \ { que.push(e.to); }\n            }\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if (visited[i]) { continue; }\n            for (int j =\
    \ 0; j < graph[i].size(); j++) {\n                edge &e = graph[i][j];\n   \
    \             if (e.is_rev && visited[e.to]) { ret[{e.to, i}] = e.cap; }\n   \
    \         }\n        }\n        return ret;\n    }\n};\n\nstruct int_dinic {\n\
    \    using T = int;\n    static T id() { return 0; }\n    static T ab() { return\
    \ std::numeric_limits<T>::max(); }\n    static T inv(const T &a) { return -a;\
    \ }\n    static T op(const T &a, const T &b) { return a + b; }\n    static bool\
    \ gr(const T &a, const T &b) { return a > b; }\n    static bool is_id(const T\
    \ &a) { return a == id(); };\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Maximum-Flow-1.test.cpp
documentation_of: graph/dinic.hpp
layout: document
title: "Dinic \u6CD5"
---

