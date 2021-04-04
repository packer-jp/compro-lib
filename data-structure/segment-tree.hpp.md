---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
    title: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/graph/heavy-light-decomposition.test.cpp
    title: test/unit-test/graph/heavy-light-decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E00\u70B9\u53D6\u5F97"
    links: []
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\ntemplate <typename S> struct segment_tree\
    \ {\n    using T = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, S::id()) {\n    }\n    segment_tree(const std::vector<T>\
    \ &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(),\
    \ data.begin() + n);\n        for (int i = n - 1; i > 0; i--) {\n            data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    /**\n  \
    \   * @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u7F6E\u304D\
    \u63DB\u3048\u5148\n     **/\n    void set(int i, const T &x) {\n        data[i\
    \ += n] = x;\n        while (i >>= 1) {\n            data[i] = S::op(data[i <<\
    \ 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    /**\n     * @brief \u4E00\u70B9\
    \u53D6\u5F97\n     **/\n    const T &operator[](int i) const {\n        return\
    \ data[i + n];\n    }\n    T fold(int l, int r) const {\n        T a = S::id(),\
    \ b = S::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) {\n                a = S::op(a, data[l++]);\n            }\n\
    \            if (r & 1) {\n                b = S::op(data[--r], b);\n        \
    \    }\n        }\n        return S::op(a, b);\n    }\n};\n\nstruct rsq {\n  \
    \  using T = int;\n    static T op(const T &a, const T &b) {\n        return a\
    \ + b;\n    }\n    static T id() {\n        return 0;\n    }\n};\n\nstruct rminq\
    \ {\n    using T = int;\n    static T op(const T &a, const T &b) {\n        return\
    \ std::min(a, b);\n    }\n    static T id() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n"
  code: "#include <cassert>\n#include <limits>\n#include <vector>\n\ntemplate <typename\
    \ S> struct segment_tree {\n    using T = typename S::T;\n    int n;\n    std::vector<T>\
    \ data;\n    segment_tree(int n) : n(n), data(n << 1, S::id()) {\n    }\n    segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(),\
    \ src.end(), data.begin() + n);\n        for (int i = n - 1; i > 0; i--) {\n \
    \           data[i] = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n\
    \    }\n    /**\n     * @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     *\
    \ @param x \u7F6E\u304D\u63DB\u3048\u5148\n     **/\n    void set(int i, const\
    \ T &x) {\n        data[i += n] = x;\n        while (i >>= 1) {\n            data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    /**\n  \
    \   * @brief \u4E00\u70B9\u53D6\u5F97\n     **/\n    const T &operator[](int i)\
    \ const {\n        return data[i + n];\n    }\n    T fold(int l, int r) const\
    \ {\n        T a = S::id(), b = S::id();\n        for (l += n, r += n; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) {\n                a = S::op(a,\
    \ data[l++]);\n            }\n            if (r & 1) {\n                b = S::op(data[--r],\
    \ b);\n            }\n        }\n        return S::op(a, b);\n    }\n};\n\nstruct\
    \ rsq {\n    using T = int;\n    static T op(const T &a, const T &b) {\n     \
    \   return a + b;\n    }\n    static T id() {\n        return 0;\n    }\n};\n\n\
    struct rminq {\n    using T = int;\n    static T op(const T &a, const T &b) {\n\
    \        return std::min(a, b);\n    }\n    static T id() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2021-04-04 16:49:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  - test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  - test/unit-test/graph/heavy-light-decomposition.test.cpp
documentation_of: data-structure/segment-tree.hpp
layout: document
redirect_from:
- /library/data-structure/segment-tree.hpp
- /library/data-structure/segment-tree.hpp.html
title: "\u4E00\u70B9\u53D6\u5F97"
---
