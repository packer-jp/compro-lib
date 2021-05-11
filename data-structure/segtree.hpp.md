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
  bundledCode: "#line 1 \"data-structure/segtree.hpp\"\n#include <vector>\n\ntemplate\
    \ <typename S> struct segment_tree {\n    using T = typename S::T;\n    int n;\n\
    \    std::vector<T> data;\n    segment_tree(int n) : n(n), data(n << 1, S::id())\
    \ {\n    }\n    segment_tree(const std::vector<T> &src) : n(src.size()), data(n\
    \ << 1) {\n        std::copy(src.begin(), src.end(), data.begin() + n);\n    \
    \    for (int i = n - 1; i > 0; i--) {\n            data[i] = S::op(data[i <<\
    \ 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    void set(int i, const T &x)\
    \ {\n        data[i += n] = x;\n        while (i >>= 1) {\n            data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    const T\
    \ &operator[](int i) const {\n        return data[i + n];\n    }\n    T fold(int\
    \ l, int r) const {\n        T a = S::id(), b = S::id();\n        for (l += n,\
    \ r += n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n             \
    \   a = S::op(a, data[l++]);\n            }\n            if (r & 1) {\n      \
    \          b = S::op(data[--r], b);\n            }\n        }\n        return\
    \ S::op(a, b);\n    }\n};\n\nstruct rsq {\n    using T = int;\n    static T op(const\
    \ T &a, const T &b) {\n        return a + b;\n    }\n    static T id() {\n   \
    \     return 0;\n    }\n};\n\nstruct rminq {\n    using T = int;\n    static T\
    \ op(const T &a, const T &b) {\n        return std::min(a, b);\n    }\n    static\
    \ T id() {\n        return std::numeric_limits<T>::max();\n    }\n};\n"
  code: "#include <vector>\n\ntemplate <typename S> struct segment_tree {\n    using\
    \ T = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
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
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2021-05-11 17:24:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree.hpp
- /library/data-structure/segtree.hpp.html
title: data-structure/segtree.hpp
---
