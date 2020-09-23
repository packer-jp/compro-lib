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
  bundledCode: "#line 1 \"data-structure/partially-persistent-union-find-tree.hpp\"\
    \n#include <vector>\n#include <climits>\n\nstruct partially_persistent_union_find_tree\
    \ {\n    int now = 0;\n    std::vector<int> parent, time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> size;\n    partially_persistent_union_find_tree(int n)\n        : parent(n),\
    \ time(n), size(n, std::vector<std::pair<int, int>>(0)) {\n        for (int i\
    \ = 0; i < n; i++) {\n            parent[i] = i;\n            size[i].push_back(std::make_pair(0,\
    \ 1));\n            time[i] = INT_MAX;\n        }\n    }\n    int get_root(int\
    \ i, int t) {\n        if (t < time[i]) { return i; }\n        else { return get_root(parent[i],\
    \ t); }\n    }\n    void unite(int i, int j) {\n        now++;\n        if ((i\
    \ = get_root(i, now)) == (j = get_root(j, now))) { return; }\n        int si =\
    \ get_size(i, now), sj = get_size(j, now);\n        if (si < sj) { std::swap(i,\
    \ j); }\n        size[i].push_back(std::make_pair(now, si + sj));\n        parent[j]\
    \ = i;\n        time[j] = now;\n    }\n    bool are_same(int i, int j, int t)\
    \ { return get_root(i, t) == get_root(j, t); }\n    int get_size(int i, int t)\
    \ {\n        i = get_root(i, t);\n        int lb = 0, ub = size[i].size();\n \
    \       while (ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n        \
    \    if (size[i][mid].first <= t) { lb = mid; }\n            else { ub = mid;\
    \ }\n        }\n        return size[i][lb].second;\n    }\n};\n"
  code: "#include <vector>\n#include <climits>\n\nstruct partially_persistent_union_find_tree\
    \ {\n    int now = 0;\n    std::vector<int> parent, time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> size;\n    partially_persistent_union_find_tree(int n)\n        : parent(n),\
    \ time(n), size(n, std::vector<std::pair<int, int>>(0)) {\n        for (int i\
    \ = 0; i < n; i++) {\n            parent[i] = i;\n            size[i].push_back(std::make_pair(0,\
    \ 1));\n            time[i] = INT_MAX;\n        }\n    }\n    int get_root(int\
    \ i, int t) {\n        if (t < time[i]) { return i; }\n        else { return get_root(parent[i],\
    \ t); }\n    }\n    void unite(int i, int j) {\n        now++;\n        if ((i\
    \ = get_root(i, now)) == (j = get_root(j, now))) { return; }\n        int si =\
    \ get_size(i, now), sj = get_size(j, now);\n        if (si < sj) { std::swap(i,\
    \ j); }\n        size[i].push_back(std::make_pair(now, si + sj));\n        parent[j]\
    \ = i;\n        time[j] = now;\n    }\n    bool are_same(int i, int j, int t)\
    \ { return get_root(i, t) == get_root(j, t); }\n    int get_size(int i, int t)\
    \ {\n        i = get_root(i, t);\n        int lb = 0, ub = size[i].size();\n \
    \       while (ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n        \
    \    if (size[i][mid].first <= t) { lb = mid; }\n            else { ub = mid;\
    \ }\n        }\n        return size[i][lb].second;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/partially-persistent-union-find-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/partially-persistent-union-find-tree.hpp
layout: document
title: "\u90E8\u5206\u6C38\u7D9A Union-Find \u6728"
---

