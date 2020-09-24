---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: "Segment \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/graph/heavy-light-decomposition.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"graph/heavy-light-decomposition.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#include <cassert>\n\nstruct heavy_light_decomposition {\n    int\
    \ n;\n    std::vector<std::vector<int>> adj;\n    std::vector<int> par, size,\
    \ depth, in, out, head;\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
    \ &adj)\n        : n(adj.size()), adj(adj), par(n), size(n), depth(n), in(n),\
    \ out(n), head(n) {}\n    void dfs_size(int v, int p) {\n        size[v] = 1;\n\
    \        par[v] = p;\n        if (p != -1) { depth[v] = depth[p] + 1; }\n    \
    \    for (int i = 0; i < adj[v].size(); i++) {\n            int &u = adj[v][i];\n\
    \            if (u == p) { continue; }\n            dfs_size(u, v);\n        \
    \    size[v] += size[u];\n            if (size[u] > size[adj[v][0]]) { std::swap(u,\
    \ adj[v][0]); }\n        }\n    }\n    int dfs_hld(int v, int &t) {\n        in[v]\
    \ = t++;\n        for (int i = 0; i < adj[v].size(); i++) {\n            int u\
    \ = adj[v][i];\n            if (u == par[v]) { continue; }\n            head[u]\
    \ = (i == 0 ? head[v] : u);\n            dfs_hld(u, t);\n        }\n        return\
    \ out[v] = t;\n    }\n    std::vector<int> build(int root) {\n        dfs_size(root,\
    \ -1);\n        head[root] = root;\n        int t = 0;\n        dfs_hld(root,\
    \ t);\n        return in;\n    }\n    int get_lca(int u, int v) {\n        while\
    \ (true) {\n            if (in[u] > in[v]) { std::swap(u, v); }\n            if\
    \ (head[u] == head[v]) { return u; }\n            v = par[head[v]];\n        }\n\
    \    }\n    int get_dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[get_lca(u,\
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
    };\n#line 3 \"data-structure/segment-tree.hpp\"\n#include <limits>\n\ntemplate<typename\
    \ S>\nstruct segment_tree {\n    using T = typename S::T;\n    int n;\n    std::vector<T>\
    \ data;\n    segment_tree(int n) : n(n), data(n << 1, S::id()) {}\n    segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(),\
    \ src.end(), data.begin() + n);\n        for (int i = n - 1; i > 0; i--) { data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const\
    \ T &x) {\n        data[i += n] = x;\n        while (i >>= 1) { data[i] = S::op(data[i\
    \ << 1 | 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const\
    \ { return data[i + n]; }\n    T fold(int l, int r) const {\n        T a = S::id(),\
    \ b = S::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) { a = S::op(a, data[l++]); }\n            if (r & 1) { b =\
    \ S::op(data[--r], b); }\n        }\n        return S::op(a, b);\n    }\n};\n\n\
    struct rsq {\n    using T = int;\n    static T op(const T &a, const T &b) { return\
    \ a + b; }\n    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T\
    \ = int;\n    static T op(const T &a, const T &b) { return std::min(a, b); }\n\
    \    static T id() { return std::numeric_limits<T>::max(); }\n};\n#line 4 \"test/unit-test/graph/heavy-light-decomposition.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N =\
    \ 10;\n    struct str {\n        using T = string;\n        static T op(T a, T\
    \ b) { return a + b; }\n        static T id() { return \"\"; }\n    };\n    segment_tree<str>\
    \ st_fwd(N), st_rev(N);\n    vector<string> weight = {\"a\", \"b\", \"c\", \"\
    d\", \"e\", \"f\", \"g\", \"h\", \"i\", \"j\"};\n    vector<vector<int>> graph(N,\
    \ vector<int>());\n    auto add_edge = [&](int u, int v) { graph[u].push_back(v),\
    \ graph[v].push_back(u); };\n    add_edge(7, 2);\n    add_edge(2, 6);\n    add_edge(4,\
    \ 2);\n    add_edge(4, 3);\n    add_edge(5, 4);\n    add_edge(5, 1);\n    add_edge(1,\
    \ 0);\n    add_edge(0, 9);\n    add_edge(5, 8);\n    heavy_light_decomposition\
    \ hld(graph);\n    vector<int> in = hld.build(5);\n    for (int i = 0; i < N;\
    \ i++) {\n        st_fwd.set(in[i], weight[i]);\n        st_rev.set(N - in[i]\
    \ - 1, weight[i]);\n    }\n    auto path = [&](int u, int v) {\n        string\
    \ ret = \"\";\n        vector<pair<int, int>> path = hld.get_path(u, v, false);\n\
    \        for (int i = 0; i < path.size(); i++) {\n            int l = path[i].first,\
    \ r = path[i].second;\n            if (l < r) { ret += st_fwd.fold(l, r + 1);\
    \ }\n            else { ret += st_rev.fold(N - l - 1, N - r); }\n        }\n \
    \       return ret;\n    };\n    auto subtree = [&](int v) {\n        pair<int,\
    \ int> subtree = hld.get_subtree(v, false);\n        return st_fwd.fold(subtree.first,\
    \ subtree.second + 1);\n    };\n    assert(path(2, 1) == \"cefb\");\n    assert(path(5,\
    \ 3) == \"fed\");\n    assert(path(7, 4) == \"hce\");\n    assert(path(4, 4) ==\
    \ \"e\");\n    assert(subtree(2) == \"chg\");\n    assert(subtree(5) == \"fechgdbaji\"\
    );\n    assert(hld.get_dist(2, 0) == 4);\n    assert(hld.get_dist(4, 1) == 2);\n\
    \n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../graph/heavy-light-decomposition.hpp\"\n#include\"../../../data-structure/segment-tree.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N =\
    \ 10;\n    struct str {\n        using T = string;\n        static T op(T a, T\
    \ b) { return a + b; }\n        static T id() { return \"\"; }\n    };\n    segment_tree<str>\
    \ st_fwd(N), st_rev(N);\n    vector<string> weight = {\"a\", \"b\", \"c\", \"\
    d\", \"e\", \"f\", \"g\", \"h\", \"i\", \"j\"};\n    vector<vector<int>> graph(N,\
    \ vector<int>());\n    auto add_edge = [&](int u, int v) { graph[u].push_back(v),\
    \ graph[v].push_back(u); };\n    add_edge(7, 2);\n    add_edge(2, 6);\n    add_edge(4,\
    \ 2);\n    add_edge(4, 3);\n    add_edge(5, 4);\n    add_edge(5, 1);\n    add_edge(1,\
    \ 0);\n    add_edge(0, 9);\n    add_edge(5, 8);\n    heavy_light_decomposition\
    \ hld(graph);\n    vector<int> in = hld.build(5);\n    for (int i = 0; i < N;\
    \ i++) {\n        st_fwd.set(in[i], weight[i]);\n        st_rev.set(N - in[i]\
    \ - 1, weight[i]);\n    }\n    auto path = [&](int u, int v) {\n        string\
    \ ret = \"\";\n        vector<pair<int, int>> path = hld.get_path(u, v, false);\n\
    \        for (int i = 0; i < path.size(); i++) {\n            int l = path[i].first,\
    \ r = path[i].second;\n            if (l < r) { ret += st_fwd.fold(l, r + 1);\
    \ }\n            else { ret += st_rev.fold(N - l - 1, N - r); }\n        }\n \
    \       return ret;\n    };\n    auto subtree = [&](int v) {\n        pair<int,\
    \ int> subtree = hld.get_subtree(v, false);\n        return st_fwd.fold(subtree.first,\
    \ subtree.second + 1);\n    };\n    assert(path(2, 1) == \"cefb\");\n    assert(path(5,\
    \ 3) == \"fed\");\n    assert(path(7, 4) == \"hce\");\n    assert(path(4, 4) ==\
    \ \"e\");\n    assert(subtree(2) == \"chg\");\n    assert(subtree(5) == \"fechgdbaji\"\
    );\n    assert(hld.get_dist(2, 0) == 4);\n    assert(hld.get_dist(4, 1) == 2);\n\
    \n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - graph/heavy-light-decomposition.hpp
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/unit-test/graph/heavy-light-decomposition.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/graph/heavy-light-decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/graph/heavy-light-decomposition.test.cpp
- /verify/test/unit-test/graph/heavy-light-decomposition.test.cpp.html
title: test/unit-test/graph/heavy-light-decomposition.test.cpp
---
