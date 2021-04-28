---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: data-structure/segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
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
    \ <vector>\n#include <cassert>\n\nstruct heavy_light_decomposition {\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> par, sz, depth, in, out, head;\n    heavy_light_decomposition(int\
    \ n) : adj(n), par(n), sz(n), depth(n), in(n), out(n), head(n) {}\n    void add_edge(int\
    \ u, int v) { adj[u].emplace_back(v), adj[v].emplace_back(u); }\n    void dfs_size(int\
    \ v, int p) {\n        sz[v] = 1;\n        par[v] = p;\n        if (p != -1) {\
    \ depth[v] = depth[p] + 1; }\n        for (int i = 0; i < adj[v].size(); i++)\
    \ {\n            int &u = adj[v][i];\n            if (u == p) { continue; }\n\
    \            dfs_size(u, v);\n            sz[v] += sz[u];\n            if (sz[u]\
    \ > sz[adj[v][0]]) { std::swap(u, adj[v][0]); }\n        }\n    }\n    int dfs_hld(int\
    \ v, int &t) {\n        in[v] = t++;\n        for (int i = 0; i < adj[v].size();\
    \ i++) {\n            int u = adj[v][i];\n            if (u == par[v]) { continue;\
    \ }\n            head[u] = (i == 0 ? head[v] : u);\n            dfs_hld(u, t);\n\
    \        }\n        return out[v] = t;\n    }\n    std::vector<int> build(int\
    \ root) {\n        dfs_size(root, -1);\n        head[root] = root;\n        int\
    \ t = 0;\n        dfs_hld(root, t);\n        return in;\n    }\n    int get_lca(int\
    \ u, int v) {\n        while (true) {\n            if (in[u] > in[v]) { std::swap(u,\
    \ v); }\n            if (head[u] == head[v]) { return u; }\n            v = par[head[v]];\n\
    \        }\n    }\n    int get_dist(int u, int v) { return depth[u] + depth[v]\
    \ - 2 * depth[get_lca(u, v)]; }\n    std::vector<std::pair<int, int>> get_path(int\
    \ u, int v, bool edge) {\n        std::vector<std::pair<int, int>> a, b;\n   \
    \     while (true) {\n            if (head[u] == head[v]) {\n                if\
    \ (edge) {\n                    if (in[u] > in[v]) { a.push_back({in[u], in[v]\
    \ + 1}); }\n                    if (in[u] < in[v]) { a.push_back({in[u] + 1, in[v]});\
    \ }\n                } else { a.push_back({in[u], in[v]}); }\n               \
    \ break;\n            }\n            if (in[u] > in[v]) {\n                a.push_back({in[u],\
    \ in[head[u]]});\n                u = par[head[u]];\n            } else {\n  \
    \              b.push_back({in[head[v]], in[v]});\n                v = par[head[v]];\n\
    \            }\n        }\n        std::reverse(b.begin(), b.end());\n       \
    \ a.insert(a.end(), b.begin(), b.end());\n        return a;\n    }\n    std::pair<int,\
    \ int> get_subtree(int v, bool edge) { return {in[v] + edge, out[v] - 1}; }\n\
    };\n#line 2 \"data-structure/segment-tree.hpp\"\n#include <limits>\n#line 4 \"\
    data-structure/segment-tree.hpp\"\n\ntemplate <typename S> struct segment_tree\
    \ {\n    using T = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, S::id()) {\n    }\n    segment_tree(const std::vector<T>\
    \ &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(),\
    \ data.begin() + n);\n        for (int i = n - 1; i > 0; i--) {\n            data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    void set(int\
    \ i, const T &x) {\n        data[i += n] = x;\n        while (i >>= 1) {\n   \
    \         data[i] = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n  \
    \  }\n    const T &operator[](int i) const {\n        return data[i + n];\n  \
    \  }\n    T fold(int l, int r) const {\n        T a = S::id(), b = S::id();\n\
    \        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n            if (l &\
    \ 1) {\n                a = S::op(a, data[l++]);\n            }\n            if\
    \ (r & 1) {\n                b = S::op(data[--r], b);\n            }\n       \
    \ }\n        return S::op(a, b);\n    }\n};\n\nstruct rsq {\n    using T = int;\n\
    \    static T op(const T &a, const T &b) {\n        return a + b;\n    }\n   \
    \ static T id() {\n        return 0;\n    }\n};\n\nstruct rminq {\n    using T\
    \ = int;\n    static T op(const T &a, const T &b) {\n        return std::min(a,\
    \ b);\n    }\n    static T id() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 4 \"test/unit-test/graph/heavy-light-decomposition.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N =\
    \ 10;\n    struct str {\n        using T = string;\n        static T op(T a, T\
    \ b) { return a + b; }\n        static T id() { return \"\"; }\n    };\n    segment_tree<str>\
    \ st_fwd(N), st_rev(N);\n    vector<string> weight = {\"a\", \"b\", \"c\", \"\
    d\", \"e\", \"f\", \"g\", \"h\", \"i\", \"j\"};\n    heavy_light_decomposition\
    \ hld(N);\n    hld.add_edge(7, 2);\n    hld.add_edge(2, 6);\n    hld.add_edge(4,\
    \ 2);\n    hld.add_edge(4, 3);\n    hld.add_edge(5, 4);\n    hld.add_edge(5, 1);\n\
    \    hld.add_edge(1, 0);\n    hld.add_edge(0, 9);\n    hld.add_edge(5, 8);\n \
    \   vector<int> in = hld.build(5);\n    for (int i = 0; i < N; i++) {\n      \
    \  st_fwd.set(in[i], weight[i]);\n        st_rev.set(N - in[i] - 1, weight[i]);\n\
    \    }\n    auto path = [&](int u, int v) {\n        string ret = \"\";\n    \
    \    vector<pair<int, int>> path = hld.get_path(u, v, false);\n        for (int\
    \ i = 0; i < path.size(); i++) {\n            int l = path[i].first, r = path[i].second;\n\
    \            if (l < r) { ret += st_fwd.fold(l, r + 1); }\n            else {\
    \ ret += st_rev.fold(N - l - 1, N - r); }\n        }\n        return ret;\n  \
    \  };\n    auto subtree = [&](int v) {\n        pair<int, int> subtree = hld.get_subtree(v,\
    \ false);\n        return st_fwd.fold(subtree.first, subtree.second + 1);\n  \
    \  };\n    assert(path(2, 1) == \"cefb\");\n    assert(path(5, 3) == \"fed\");\n\
    \    assert(path(7, 4) == \"hce\");\n    assert(path(4, 4) == \"e\");\n    assert(subtree(2)\
    \ == \"chg\");\n    assert(subtree(5) == \"fechgdbaji\");\n    assert(hld.get_dist(2,\
    \ 0) == 4);\n    assert(hld.get_dist(4, 1) == 2);\n\n    cout << \"Hello World\"\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../graph/heavy-light-decomposition.hpp\"\n#include\"../../../data-structure/segment-tree.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N =\
    \ 10;\n    struct str {\n        using T = string;\n        static T op(T a, T\
    \ b) { return a + b; }\n        static T id() { return \"\"; }\n    };\n    segment_tree<str>\
    \ st_fwd(N), st_rev(N);\n    vector<string> weight = {\"a\", \"b\", \"c\", \"\
    d\", \"e\", \"f\", \"g\", \"h\", \"i\", \"j\"};\n    heavy_light_decomposition\
    \ hld(N);\n    hld.add_edge(7, 2);\n    hld.add_edge(2, 6);\n    hld.add_edge(4,\
    \ 2);\n    hld.add_edge(4, 3);\n    hld.add_edge(5, 4);\n    hld.add_edge(5, 1);\n\
    \    hld.add_edge(1, 0);\n    hld.add_edge(0, 9);\n    hld.add_edge(5, 8);\n \
    \   vector<int> in = hld.build(5);\n    for (int i = 0; i < N; i++) {\n      \
    \  st_fwd.set(in[i], weight[i]);\n        st_rev.set(N - in[i] - 1, weight[i]);\n\
    \    }\n    auto path = [&](int u, int v) {\n        string ret = \"\";\n    \
    \    vector<pair<int, int>> path = hld.get_path(u, v, false);\n        for (int\
    \ i = 0; i < path.size(); i++) {\n            int l = path[i].first, r = path[i].second;\n\
    \            if (l < r) { ret += st_fwd.fold(l, r + 1); }\n            else {\
    \ ret += st_rev.fold(N - l - 1, N - r); }\n        }\n        return ret;\n  \
    \  };\n    auto subtree = [&](int v) {\n        pair<int, int> subtree = hld.get_subtree(v,\
    \ false);\n        return st_fwd.fold(subtree.first, subtree.second + 1);\n  \
    \  };\n    assert(path(2, 1) == \"cefb\");\n    assert(path(5, 3) == \"fed\");\n\
    \    assert(path(7, 4) == \"hce\");\n    assert(path(4, 4) == \"e\");\n    assert(subtree(2)\
    \ == \"chg\");\n    assert(subtree(5) == \"fechgdbaji\");\n    assert(hld.get_dist(2,\
    \ 0) == 4);\n    assert(hld.get_dist(4, 1) == 2);\n\n    cout << \"Hello World\"\
    \ << endl;\n}"
  dependsOn:
  - graph/heavy-light-decomposition.hpp
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/unit-test/graph/heavy-light-decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-04-28 09:04:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/graph/heavy-light-decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/graph/heavy-light-decomposition.test.cpp
- /verify/test/unit-test/graph/heavy-light-decomposition.test.cpp.html
title: test/unit-test/graph/heavy-light-decomposition.test.cpp
---
