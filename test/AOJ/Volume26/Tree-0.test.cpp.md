---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1 Segment \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "#line 1 \"test/AOJ/Volume26/Tree-0.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\n#line 1 \"graph/heavy-light-decomposition.hpp\"\
    \n#include <algorithm>\n#include <vector>\n#include <cassert>\n\nstruct heavy_light_decomposition\
    \ {\n    int n;\n    std::vector<std::vector<int>> adj;\n    std::vector<int>\
    \ par, size, depth, in, out, head;\n    heavy_light_decomposition(const std::vector<std::vector<int>>\
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
    };\n#line 3 \"data-structure/lazy-segment-tree.hpp\"\n#include <limits>\n\ntemplate<typename\
    \ S>\nstruct lazy_segment_tree {\n    using T = typename S::T;\n    using E =\
    \ typename S::E;\n    int n;\n    std::vector<T> data;\n    std::vector<E> lazy;\n\
    \    lazy_segment_tree(int n) : n(n), data(n << 1, S::id_T()), lazy(n << 1, S::id_E())\
    \ {}\n    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n\
    \ << 1), lazy(n << 1, S::id_E()) {\n        std::copy(src.begin(), src.end(),\
    \ data.begin() + n);\n        for (int i = n - 1; i > 0; i--) { data[i] = S::op_TT(data[i\
    \ << 1 | 0], data[i << 1 | 1]); }\n    }\n    void propagate(int i) {\n      \
    \  if (i < 1) { return; }\n        data[i] = S::op_TE(data[i], lazy[i]);\n   \
    \     if (i < n) {\n            lazy[i << 1 | 0] = S::op_EE(lazy[i << 1 | 0],\
    \ lazy[i]);\n            lazy[i << 1 | 1] = S::op_EE(lazy[i << 1 | 1], lazy[i]);\n\
    \        }\n        lazy[i] = S::id_E();\n    }\n    void apply(int l, int r,\
    \ const E &x) {\n        l += n, r += n - 1;\n        for (int i = std::__lg(r);\
    \ i > 0; i--) {\n            propagate(l >> i);\n            propagate(r >> i);\n\
    \        }\n        auto update = [&](int i) { lazy[i] = S::op_EE(lazy[i], x),\
    \ propagate(i); };\n        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1)\
    \ {\n            if (i & 1) { update(i++); }\n            if (j & 1) { update(--j);\
    \ }\n        }\n        while (l >>= 1, r >>= 1) {\n            data[l] = S::op_TT(S::op_TE(data[l\
    \ << 1 | 0], lazy[l << 1 | 0]),\n                               S::op_TE(data[l\
    \ << 1 | 1], lazy[l << 1 | 1]));\n            data[r] = S::op_TT(S::op_TE(data[r\
    \ << 1 | 0], lazy[r << 1 | 0]),\n                               S::op_TE(data[r\
    \ << 1 | 1], lazy[r << 1 | 1]));\n        }\n    }\n    T fold(int l, int r) {\n\
    \        l += n, r += n - 1;\n        for (int i = std::__lg(r); i > 0; i--) {\
    \ propagate(l >> i), propagate(r >> i); }\n        T a = S::id_T(), b = S::id_T();\n\
    \        for (r++; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) { propagate(l),\
    \ a = S::op_TT(a, data[l++]); }\n            if (r & 1) { propagate(--r), b =\
    \ S::op_TT(data[r], b); }\n        }\n        return S::op_TT(a, b);\n    }\n\
    };\n\nstruct rminq_and_ruq {\n    using T = int;\n    using E = int;\n    static\
    \ T id_T() { return std::numeric_limits<T>::max(); };\n    static E id_E() { return\
    \ -1; };\n    static T op_TT(const T &a, const T &b) { return std::min(a, b);\
    \ }\n    static E op_EE(const E &a, const E &b) { return b == id_E() ? a : b;\
    \ }\n    static T op_TE(const T &a, const E &b) { return b == id_E() ? a : b;\
    \ }\n};\n\nstruct rsq_and_raq {\n    using T = std::pair<long long, int>;\n  \
    \  using E = long long;\n    static T id_T() { return {0, 0}; };\n    static E\
    \ id_E() { return 0; };\n    static T op_TT(const T &a, const T &b) { return {a.first\
    \ + b.first, a.second + b.second}; }\n    static E op_EE(const E &a, const E &b)\
    \ { return a + b; }\n    static T op_TE(const T &a, const E &b) { return {a.first\
    \ + b * a.second, a.second}; }\n};\n\nstruct rminq_and_raq {\n    using T = long\
    \ long;\n    using E = long long;\n    static T id_T() { return std::numeric_limits<T>::max();\
    \ };\n    static E id_E() { return 0; };\n    static T op_TT(const T &a, const\
    \ T &b) { return std::min(a, b); }\n    static E op_EE(const E &a, const E &b)\
    \ { return a + b; }\n    static T op_TE(const T &a, const E &b) { return a + b;\
    \ }\n};\n#line 4 \"test/AOJ/Volume26/Tree-0.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>>\
    \ adj(N);\n    for (int i = 0; i < N - 1; i++) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        adj[a].push_back(b), adj[b].push_back(a);\n    }\n    heavy_light_decomposition\
    \ hld(adj);\n    hld.build(0);\n    lazy_segment_tree<rsq_and_raq> lst(vector<pair<long\
    \ long, int>>(N, {0, 1}));\n    for (int i = 0; i < Q; i++) {\n        int type;\n\
    \        cin >> type;\n        if (type == 0) {\n            int u, v;\n     \
    \       cin >> u >> v;\n            long long ans = 0;\n            vector<pair<int,\
    \ int>> segs = hld.get_path(u, v, true);\n            for (int j = 0; j < segs.size();\
    \ j++) {\n                if (segs[j].first > segs[j].second) { swap(segs[j].first,\
    \ segs[j].second); }\n                ans += lst.fold(segs[j].first, segs[j].second\
    \ + 1).first;\n            }\n            cout << ans << endl;\n        } else\
    \ {\n            int v, x;\n            cin >> v >> x;\n            pair<int,\
    \ int> seg = hld.get_subtree(v, true);\n            if (seg.first <= seg.second)\
    \ { lst.apply(seg.first, seg.second + 1, x); }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\"\
    \n#include \"../../../graph/heavy-light-decomposition.hpp\"\n#include \"../../../data-structure/lazy-segment-tree.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<vector<int>> adj(N);\n    for (int i = 0;\
    \ i < N - 1; i++) {\n        int a, b;\n        cin >> a >> b;\n        adj[a].push_back(b),\
    \ adj[b].push_back(a);\n    }\n    heavy_light_decomposition hld(adj);\n    hld.build(0);\n\
    \    lazy_segment_tree<rsq_and_raq> lst(vector<pair<long long, int>>(N, {0, 1}));\n\
    \    for (int i = 0; i < Q; i++) {\n        int type;\n        cin >> type;\n\
    \        if (type == 0) {\n            int u, v;\n            cin >> u >> v;\n\
    \            long long ans = 0;\n            vector<pair<int, int>> segs = hld.get_path(u,\
    \ v, true);\n            for (int j = 0; j < segs.size(); j++) {\n           \
    \     if (segs[j].first > segs[j].second) { swap(segs[j].first, segs[j].second);\
    \ }\n                ans += lst.fold(segs[j].first, segs[j].second + 1).first;\n\
    \            }\n            cout << ans << endl;\n        } else {\n         \
    \   int v, x;\n            cin >> v >> x;\n            pair<int, int> seg = hld.get_subtree(v,\
    \ true);\n            if (seg.first <= seg.second) { lst.apply(seg.first, seg.second\
    \ + 1, x); }\n        }\n    }\n}"
  dependsOn:
  - graph/heavy-light-decomposition.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/AOJ/Volume26/Tree-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/Volume26/Tree-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/Volume26/Tree-0.test.cpp
- /verify/test/AOJ/Volume26/Tree-0.test.cpp.html
title: test/AOJ/Volume26/Tree-0.test.cpp
---
