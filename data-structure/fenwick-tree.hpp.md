---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Sum-Query-1.test.cpp
    title: test/AOJ/DSL/Range-Sum-Query-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Add-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Add-Query-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick-tree.hpp\"\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate<typename M>\nstruct fenwick_tree {\n    using T = typename\
    \ M::T;\n    int n;\n    std::vector<T> data;\n    fenwick_tree(int n) : n(n),\
    \ data(n + 1, M::id()) {}\n    void apply(int i, const T &x) {\n        for (i++;\
    \ i <= n; i += i & -i) { data[i] = M::op(data[i], x); }\n    }\n    T fold(int\
    \ i) const {\n        T ret = M::id();\n        for (; i > 0; i -= i & -i) { ret\
    \ = M::op(ret, data[i]); }\n        return ret;\n    }\n    T fold(int l, int\
    \ r) const { return M::op(M::inv(fold(l)), fold(r)); }\n};\n\ntemplate<typename\
    \ M>\nstruct fenwick_tree_range : public fenwick_tree<M> {\n    using S = fenwick_tree<M>;\n\
    \    using T = typename M::T;\n    fenwick_tree_range(int n) : S(n) {}\n    void\
    \ apply(int l, int r, const T &x) { S::apply(l, x), S::apply(r, M::inv(x)); }\n\
    \    T operator[](int i) const { return S::fold(i + 1); }\n};\n\nstruct rsq {\n\
    \    using T = int;\n    static T id() { return 0; }\n    static T op(const T\
    \ &a, const T &b) { return a + b; }\n    static T inv(const T &a) { return -a;\
    \ }\n};\n"
  code: "#include <vector>\n#include <cassert>\n\ntemplate<typename M>\nstruct fenwick_tree\
    \ {\n    using T = typename M::T;\n    int n;\n    std::vector<T> data;\n    fenwick_tree(int\
    \ n) : n(n), data(n + 1, M::id()) {}\n    void apply(int i, const T &x) {\n  \
    \      for (i++; i <= n; i += i & -i) { data[i] = M::op(data[i], x); }\n    }\n\
    \    T fold(int i) const {\n        T ret = M::id();\n        for (; i > 0; i\
    \ -= i & -i) { ret = M::op(ret, data[i]); }\n        return ret;\n    }\n    T\
    \ fold(int l, int r) const { return M::op(M::inv(fold(l)), fold(r)); }\n};\n\n\
    template<typename M>\nstruct fenwick_tree_range : public fenwick_tree<M> {\n \
    \   using S = fenwick_tree<M>;\n    using T = typename M::T;\n    fenwick_tree_range(int\
    \ n) : S(n) {}\n    void apply(int l, int r, const T &x) { S::apply(l, x), S::apply(r,\
    \ M::inv(x)); }\n    T operator[](int i) const { return S::fold(i + 1); }\n};\n\
    \nstruct rsq {\n    using T = int;\n    static T id() { return 0; }\n    static\
    \ T op(const T &a, const T &b) { return a + b; }\n    static T inv(const T &a)\
    \ { return -a; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/Range-Sum-Query-1.test.cpp
  - test/AOJ/DSL/Range-Add-Query-0.test.cpp
documentation_of: data-structure/fenwick-tree.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick-tree.hpp
- /library/data-structure/fenwick-tree.hpp.html
title: data-structure/fenwick-tree.hpp
---
