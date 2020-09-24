---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
    title: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/union-find-tree.hpp\"\n#include <vector>\n\
    \ntemplate<typename S>\nstruct union_find_tree {\n    using T = typename S::T;\n\
    \    std::vector<int> parent, size_;\n    std::vector<T> val;\n    union_find_tree(const\
    \ std::vector<T> &val) : parent(val.size(), -1), size_(val.size(), 1), val(val)\
    \ {}\n    union_find_tree(int n) : union_find_tree(std::vector<T>(n, S::initial()))\
    \ {}\n    int root(int i) {\n        if (parent[i] == -1) { return i; }\n    \
    \    else { return parent[i] = root(parent[i]); }\n    }\n    void unite(int i,\
    \ int j) {\n        if ((i = root(i)) == (j = root(j))) { return; }\n        if\
    \ (size_[i] < size_[j]) { std::swap(i, j); }\n        size_[i] += size_[j];\n\
    \        val[i] = S::op(val[i], val[j]);\n        parent[j] = i;\n    }\n    bool\
    \ same(int i, int j) { return root(i) == root(j); }\n    int size(int i) { return\
    \ size_[root(i)]; }\n    void set(int i, const T &x) { val[root(i)] = x; }\n \
    \   T operator[](int i) { return val[root(i)]; }\n};\n\nstruct normal_uf {\n \
    \   struct T {};\n    static T initial() { return {}; }\n    static T op(const\
    \ T &a, const T &b) { return {}; }\n};\n"
  code: "#include <vector>\n\ntemplate<typename S>\nstruct union_find_tree {\n   \
    \ using T = typename S::T;\n    std::vector<int> parent, size_;\n    std::vector<T>\
    \ val;\n    union_find_tree(const std::vector<T> &val) : parent(val.size(), -1),\
    \ size_(val.size(), 1), val(val) {}\n    union_find_tree(int n) : union_find_tree(std::vector<T>(n,\
    \ S::initial())) {}\n    int root(int i) {\n        if (parent[i] == -1) { return\
    \ i; }\n        else { return parent[i] = root(parent[i]); }\n    }\n    void\
    \ unite(int i, int j) {\n        if ((i = root(i)) == (j = root(j))) { return;\
    \ }\n        if (size_[i] < size_[j]) { std::swap(i, j); }\n        size_[i] +=\
    \ size_[j];\n        val[i] = S::op(val[i], val[j]);\n        parent[j] = i;\n\
    \    }\n    bool same(int i, int j) { return root(i) == root(j); }\n    int size(int\
    \ i) { return size_[root(i)]; }\n    void set(int i, const T &x) { val[root(i)]\
    \ = x; }\n    T operator[](int i) { return val[root(i)]; }\n};\n\nstruct normal_uf\
    \ {\n    struct T {};\n    static T initial() { return {}; }\n    static T op(const\
    \ T &a, const T &b) { return {}; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find-tree.hpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL/Union-Find-Tree-0.test.cpp
documentation_of: data-structure/union-find-tree.hpp
layout: document
title: "Union-Find \u6728"
---

