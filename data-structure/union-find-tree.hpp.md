---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/union-find-tree.hpp\"\n#include <vector>\n\
    \nstruct union_find_tree {\n    std::vector<int> par, size;\n    union_find_tree(int\
    \ n) : par(n), size(n) {\n        for (int i = 0; i < n; i++) {\n            par[i]\
    \ = i;\n            size[i] = 1;\n        }\n    }\n    int get_root(int i) {\n\
    \        if (par[i] == i) { return i; }\n        else { return par[i] = get_root(par[i]);\
    \ }\n    }\n    void unite(int i, int j) {\n        if ((i = get_root(i)) == (j\
    \ = get_root(j))) { return; }\n        if (size[i] < size[j]) { std::swap(i, j);\
    \ }\n        par[j] = i;\n        size[i] += size[j];\n    }\n    bool are_same(int\
    \ i, int j) { return get_root(i) == get_root(j); }\n    int get_size(int i) {\
    \ return size[get_root(i)]; }\n};\n"
  code: "#include <vector>\n\nstruct union_find_tree {\n    std::vector<int> par,\
    \ size;\n    union_find_tree(int n) : par(n), size(n) {\n        for (int i =\
    \ 0; i < n; i++) {\n            par[i] = i;\n            size[i] = 1;\n      \
    \  }\n    }\n    int get_root(int i) {\n        if (par[i] == i) { return i; }\n\
    \        else { return par[i] = get_root(par[i]); }\n    }\n    void unite(int\
    \ i, int j) {\n        if ((i = get_root(i)) == (j = get_root(j))) { return; }\n\
    \        if (size[i] < size[j]) { std::swap(i, j); }\n        par[j] = i;\n  \
    \      size[i] += size[j];\n    }\n    bool are_same(int i, int j) { return get_root(i)\
    \ == get_root(j); }\n    int get_size(int i) { return size[get_root(i)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/union-find-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/union-find-tree.hpp
layout: document
title: "Union-Find \u6728"
---

