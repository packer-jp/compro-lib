---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/weighted-union-find-tree.hpp\"\n#include\
    \ <vector>\n\ntemplate<typename T>\nstruct weighted_union_find_tree {\n    T zero;\n\
    \    std::vector<int> par, size;\n    std::vector<T> weight;\n    weighted_union_find_tree(int\
    \ n, T zero = T()) : zero(zero), par(n), size(n, 1), weight(n, zero) {\n     \
    \   for (int i = 0; i < n; i++) { par[i] = i; }\n    }\n    int get_root(int i)\
    \ {\n        if (par[i] == i) { return i; }\n        else {\n            int r\
    \ = get_root(par[i]);\n            weight[i] += weight[par[i]];\n            return\
    \ par[i] = r;\n        }\n    }\n    T get_weight(int i) {\n        get_root(i);\n\
    \        return weight[i];\n    }\n    T get_diff(int i, int j) { return get_weight(j)\
    \ - get_weight(i); }\n    void unite(int i, int j, T d) {\n        d -= get_diff(i,\
    \ j);\n        i = get_root(i);\n        j = get_root(j);\n        if (i == j)\
    \ { return; }\n        if (size[i] < size[j]) { std::swap(i, j), d = -d; }\n \
    \       par[j] = i;\n        size[i] += size[j];\n        weight[j] = d;\n   \
    \ }\n    bool are_same(int i, int j) { return get_root(i) == get_root(j); }\n\
    \    int get_size(int i) { return size[get_root(i)]; }\n};\n"
  code: "#include <vector>\n\ntemplate<typename T>\nstruct weighted_union_find_tree\
    \ {\n    T zero;\n    std::vector<int> par, size;\n    std::vector<T> weight;\n\
    \    weighted_union_find_tree(int n, T zero = T()) : zero(zero), par(n), size(n,\
    \ 1), weight(n, zero) {\n        for (int i = 0; i < n; i++) { par[i] = i; }\n\
    \    }\n    int get_root(int i) {\n        if (par[i] == i) { return i; }\n  \
    \      else {\n            int r = get_root(par[i]);\n            weight[i] +=\
    \ weight[par[i]];\n            return par[i] = r;\n        }\n    }\n    T get_weight(int\
    \ i) {\n        get_root(i);\n        return weight[i];\n    }\n    T get_diff(int\
    \ i, int j) { return get_weight(j) - get_weight(i); }\n    void unite(int i, int\
    \ j, T d) {\n        d -= get_diff(i, j);\n        i = get_root(i);\n        j\
    \ = get_root(j);\n        if (i == j) { return; }\n        if (size[i] < size[j])\
    \ { std::swap(i, j), d = -d; }\n        par[j] = i;\n        size[i] += size[j];\n\
    \        weight[j] = d;\n    }\n    bool are_same(int i, int j) { return get_root(i)\
    \ == get_root(j); }\n    int get_size(int i) { return size[get_root(i)]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/weighted-union-find-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/weighted-union-find-tree.hpp
layout: document
title: "\u91CD\u307F\u4ED8\u304D Union-Find \u6728"
---

