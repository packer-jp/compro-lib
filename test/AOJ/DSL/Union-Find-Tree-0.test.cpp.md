---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find-tree.hpp
    title: "Union-Find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DSL/Union-Find-Tree-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja\"\
    \n#line 1 \"data-structure/union-find-tree.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ S>\nstruct union_find_tree {\n    using T = typename S::T;\n    std::vector<int>\
    \ par, sz;\n    std::vector<T> val;\n    union_find_tree(const std::vector<T>\
    \ &val) : par(val.size(), -1), sz(val.size(), 1), val(val) {}\n    union_find_tree(int\
    \ n, const T &x = {}) : union_find_tree(std::vector<T>(n, x)) {}\n    int root(int\
    \ i) {\n        if (par[i] == -1) { return i; }\n        else { return par[i]\
    \ = root(par[i]); }\n    }\n    void unite(int i, int j) {\n        if ((i = root(i))\
    \ == (j = root(j))) { return; }\n        if (sz[i] < sz[j]) { std::swap(i, j);\
    \ }\n        sz[i] += sz[j];\n        S::merge(val[i], val[j]);\n        par[j]\
    \ = i;\n    }\n    bool same(int i, int j) { return root(i) == root(j); }\n  \
    \  int size(int i) { return sz[root(i)]; }\n    T &operator[](int i) { return\
    \ val[root(i)]; }\n};\n\nstruct normal_uf {\n    struct T {};\n    static void\
    \ merge(T &a, const T &b) {}\n};\n#line 3 \"test/AOJ/DSL/Union-Find-Tree-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    union_find_tree<normal_uf> uf(n);\n    for (int\
    \ i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if (com == 0) { uf.unite(x, y); }\n        else if (com == 1) { cout\
    \ << uf.same(x, y) << endl; }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=ja\"\
    \n#include\"../../../data-structure/union-find-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    union_find_tree<normal_uf>\
    \ uf(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) { uf.unite(x, y); }\n        else if\
    \ (com == 1) { cout << uf.same(x, y) << endl; }\n    }\n}"
  dependsOn:
  - data-structure/union-find-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
  requiredBy: []
  timestamp: '2020-11-15 21:42:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Union-Find-Tree-0.test.cpp
- /verify/test/AOJ/DSL/Union-Find-Tree-0.test.cpp.html
title: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
---