---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/Maximum-Flow-0.test.cpp
    title: test/AOJ/GRL/Maximum-Flow-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/ford-fulkerson.hpp\"\n#include <limits>\n#include\
    \ <map>\n#include <queue>\n#include <vector>\n\ntemplate<typename S>\nstruct ford_fulkerson\
    \ {\n    using T = typename S::T;\n    struct edge {\n        int to, rev;\n \
    \       T cap;\n        bool is_rev;\n    };\n    std::vector<std::vector<edge>>\
    \ graph;\n    std::vector<int> used;\n    int timestamp;\n    void add_edge(int\
    \ from, int to, T cap) {\n        graph[from].push_back({to, (int) graph[to].size(),\
    \ cap, false});\n        graph[to].push_back({from, (int) graph[from].size() -\
    \ 1, S::zero(), true});\n    }\n    ford_fulkerson(int n) : graph(n), used(n)\
    \ {}\n    T dfs(int v, int t, T f) {\n        if (v == t) { return f; }\n    \
    \    used[v] = timestamp;\n        for (int i = 0; i < graph[v].size(); i++) {\n\
    \            edge &e = graph[v][i];\n            if (used[e.to] != timestamp &&\
    \ S::less(S::zero(), e.cap)) {\n                T d = dfs(e.to, t, S::less(e.cap,\
    \ f) ? e.cap : f);\n                if (S::is_zero(d)) { continue; }\n       \
    \         e.cap = S::plus(e.cap, S::minus(d));\n                graph[e.to][e.rev].cap\
    \ = S::plus(graph[e.to][e.rev].cap, d);\n                return d;\n         \
    \   }\n        }\n        return S::zero();\n    }\n    T calc_max_flow(int s,\
    \ int t, T lim) {\n        T ret = S::zero();\n        fill(used.begin(), used.end(),\
    \ 0);\n        timestamp = 0;\n        while (true) {\n            timestamp++;\n\
    \            T f = dfs(s, t, lim);\n            if (S::is_zero(f)) { return ret;\
    \ }\n            ret = S::plus(ret, f);\n            lim = S::plus(lim, S::minus(f));\n\
    \        }\n    }\n    T calc_max_flow(int s, int t) { return calc_max_flow(s,\
    \ t, S::inf()); }\n    std::map<std::pair<int, int>, T> get_max_flow() {\n   \
    \     std::map<std::pair<int, int>, T> ret;\n        for (int i = 0; i < graph.size();\
    \ i++) {\n            for (int j = 0; j < graph[i].size(); j++) {\n          \
    \      edge &e = graph[i][j];\n                if (e.is_rev) { ret[{e.to, i}]\
    \ = e.cap; }\n            }\n        }\n        return ret;\n    }\n    std::map<std::pair<int,\
    \ int>, T> get_min_cut(int s) {\n        std::map<std::pair<int, int>, T> ret;\n\
    \        std::vector<int> visited(graph.size());\n        std::queue<int> que;\n\
    \        que.push(s);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if (visited[v]) { continue; }\n         \
    \   visited[v] = true;\n            for (int i = 0; i < graph[v].size(); i++)\
    \ {\n                edge &e = graph[v][i];\n                if (!S::is_zero(e.cap))\
    \ { que.push(e.to); }\n            }\n        }\n        for (int i = 0; i < graph.size();\
    \ i++) {\n            if (visited[i]) { continue; }\n            for (int j =\
    \ 0; j < graph[i].size(); j++) {\n                edge &e = graph[i][j];\n   \
    \             if (e.is_rev && visited[e.to]) { ret[{e.to, i}] = e.cap; }\n   \
    \         }\n        }\n        return ret;\n    }\n};\n\nstruct int_ff {\n  \
    \  using T = int;\n    static T zero() { return 0; }\n    static T inf() { return\
    \ std::numeric_limits<T>::max(); }\n    static T minus(const T &a) { return -a;\
    \ }\n    static T plus(const T &a, const T &b) { return a + b; }\n    static bool\
    \ less(const T &a, const T &b) { return a < b; }\n    static bool is_zero(const\
    \ T &a) { return a == zero(); };\n};\n"
  code: "#include <limits>\n#include <map>\n#include <queue>\n#include <vector>\n\n\
    template<typename S>\nstruct ford_fulkerson {\n    using T = typename S::T;\n\
    \    struct edge {\n        int to, rev;\n        T cap;\n        bool is_rev;\n\
    \    };\n    std::vector<std::vector<edge>> graph;\n    std::vector<int> used;\n\
    \    int timestamp;\n    void add_edge(int from, int to, T cap) {\n        graph[from].push_back({to,\
    \ (int) graph[to].size(), cap, false});\n        graph[to].push_back({from, (int)\
    \ graph[from].size() - 1, S::zero(), true});\n    }\n    ford_fulkerson(int n)\
    \ : graph(n), used(n) {}\n    T dfs(int v, int t, T f) {\n        if (v == t)\
    \ { return f; }\n        used[v] = timestamp;\n        for (int i = 0; i < graph[v].size();\
    \ i++) {\n            edge &e = graph[v][i];\n            if (used[e.to] != timestamp\
    \ && S::less(S::zero(), e.cap)) {\n                T d = dfs(e.to, t, S::less(e.cap,\
    \ f) ? e.cap : f);\n                if (S::is_zero(d)) { continue; }\n       \
    \         e.cap = S::plus(e.cap, S::minus(d));\n                graph[e.to][e.rev].cap\
    \ = S::plus(graph[e.to][e.rev].cap, d);\n                return d;\n         \
    \   }\n        }\n        return S::zero();\n    }\n    T calc_max_flow(int s,\
    \ int t, T lim) {\n        T ret = S::zero();\n        fill(used.begin(), used.end(),\
    \ 0);\n        timestamp = 0;\n        while (true) {\n            timestamp++;\n\
    \            T f = dfs(s, t, lim);\n            if (S::is_zero(f)) { return ret;\
    \ }\n            ret = S::plus(ret, f);\n            lim = S::plus(lim, S::minus(f));\n\
    \        }\n    }\n    T calc_max_flow(int s, int t) { return calc_max_flow(s,\
    \ t, S::inf()); }\n    std::map<std::pair<int, int>, T> get_max_flow() {\n   \
    \     std::map<std::pair<int, int>, T> ret;\n        for (int i = 0; i < graph.size();\
    \ i++) {\n            for (int j = 0; j < graph[i].size(); j++) {\n          \
    \      edge &e = graph[i][j];\n                if (e.is_rev) { ret[{e.to, i}]\
    \ = e.cap; }\n            }\n        }\n        return ret;\n    }\n    std::map<std::pair<int,\
    \ int>, T> get_min_cut(int s) {\n        std::map<std::pair<int, int>, T> ret;\n\
    \        std::vector<int> visited(graph.size());\n        std::queue<int> que;\n\
    \        que.push(s);\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            if (visited[v]) { continue; }\n         \
    \   visited[v] = true;\n            for (int i = 0; i < graph[v].size(); i++)\
    \ {\n                edge &e = graph[v][i];\n                if (!S::is_zero(e.cap))\
    \ { que.push(e.to); }\n            }\n        }\n        for (int i = 0; i < graph.size();\
    \ i++) {\n            if (visited[i]) { continue; }\n            for (int j =\
    \ 0; j < graph[i].size(); j++) {\n                edge &e = graph[i][j];\n   \
    \             if (e.is_rev && visited[e.to]) { ret[{e.to, i}] = e.cap; }\n   \
    \         }\n        }\n        return ret;\n    }\n};\n\nstruct int_ff {\n  \
    \  using T = int;\n    static T zero() { return 0; }\n    static T inf() { return\
    \ std::numeric_limits<T>::max(); }\n    static T minus(const T &a) { return -a;\
    \ }\n    static T plus(const T &a, const T &b) { return a + b; }\n    static bool\
    \ less(const T &a, const T &b) { return a < b; }\n    static bool is_zero(const\
    \ T &a) { return a == zero(); };\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/ford-fulkerson.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/Maximum-Flow-0.test.cpp
documentation_of: graph/ford-fulkerson.hpp
layout: document
title: "Ford-Fulkerson \u6CD5"
---

