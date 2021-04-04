---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/RMQ-and-RAQ-0.test.cpp
    title: test/AOJ/DSL/RMQ-and-RAQ-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp
    title: test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
    title: test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/Volume26/Tree-0.test.cpp
    title: test/AOJ/Volume26/Tree-0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/lazy-segment-tree.hpp\"\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\ntemplate <typename S> struct lazy_segment_tree\
    \ {\n    using T = typename S::T;\n    using E = typename S::E;\n    int n;\n\
    \    std::vector<T> data;\n    std::vector<E> lazy;\n    lazy_segment_tree(int\
    \ n) : n(n), data(n << 1, S::id_T()), lazy(n << 1, S::id_E()) {\n    }\n    lazy_segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, S::id_E())\
    \ {\n        std::copy(src.begin(), src.end(), data.begin() + n);\n        for\
    \ (int i = n - 1; i > 0; i--) {\n            data[i] = S::op_TT(data[i << 1 |\
    \ 0], data[i << 1 | 1]);\n        }\n    }\n    void propagate(int i) {\n    \
    \    if (i < 1) {\n            return;\n        }\n        data[i] = S::op_TE(data[i],\
    \ lazy[i]);\n        if (i < n) {\n            lazy[i << 1 | 0] = S::op_EE(lazy[i\
    \ << 1 | 0], lazy[i]);\n            lazy[i << 1 | 1] = S::op_EE(lazy[i << 1 |\
    \ 1], lazy[i]);\n        }\n        lazy[i] = S::id_E();\n    }\n    void apply(int\
    \ l, int r, const E &x) {\n        l += n, r += n - 1;\n        for (int i = std::__lg(r);\
    \ i > 0; i--) {\n            propagate(l >> i);\n            propagate(r >> i);\n\
    \        }\n        auto update = [&](int i) { lazy[i] = S::op_EE(lazy[i], x),\
    \ propagate(i); };\n        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1)\
    \ {\n            if (i & 1) {\n                update(i++);\n            }\n \
    \           if (j & 1) {\n                update(--j);\n            }\n      \
    \  }\n        while (l >>= 1, r >>= 1) {\n            data[l] =\n            \
    \    S::op_TT(S::op_TE(data[l << 1 | 0], lazy[l << 1 | 0]), S::op_TE(data[l <<\
    \ 1 | 1], lazy[l << 1 | 1]));\n            data[r] =\n                S::op_TT(S::op_TE(data[r\
    \ << 1 | 0], lazy[r << 1 | 0]), S::op_TE(data[r << 1 | 1], lazy[r << 1 | 1]));\n\
    \        }\n    }\n    T fold(int l, int r) {\n        l += n, r += n - 1;\n \
    \       for (int i = std::__lg(r); i > 0; i--) {\n            propagate(l >> i),\
    \ propagate(r >> i);\n        }\n        T a = S::id_T(), b = S::id_T();\n   \
    \     for (r++; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n       \
    \         propagate(l), a = S::op_TT(a, data[l++]);\n            }\n         \
    \   if (r & 1) {\n                propagate(--r), b = S::op_TT(data[r], b);\n\
    \            }\n        }\n        return S::op_TT(a, b);\n    }\n};\n\nstruct\
    \ rminq_and_ruq {\n    using T = int;\n    using E = int;\n    static T id_T()\
    \ {\n        return std::numeric_limits<T>::max();\n    };\n    static E id_E()\
    \ {\n        return -1;\n    };\n    static T op_TT(const T &a, const T &b) {\n\
    \        return std::min(a, b);\n    }\n    static E op_EE(const E &a, const E\
    \ &b) {\n        return b == id_E() ? a : b;\n    }\n    static T op_TE(const\
    \ T &a, const E &b) {\n        return b == id_E() ? a : b;\n    }\n};\n\nstruct\
    \ rsq_and_raq {\n    using T = std::pair<long long, int>;\n    using E = long\
    \ long;\n    static T id_T() {\n        return {0, 0};\n    };\n    static E id_E()\
    \ {\n        return 0;\n    };\n    static T op_TT(const T &a, const T &b) {\n\
    \        return {a.first + b.first, a.second + b.second};\n    }\n    static E\
    \ op_EE(const E &a, const E &b) {\n        return a + b;\n    }\n    static T\
    \ op_TE(const T &a, const E &b) {\n        return {a.first + b * a.second, a.second};\n\
    \    }\n};\n\nstruct rminq_and_raq {\n    using T = long long;\n    using E =\
    \ long long;\n    static T id_T() {\n        return std::numeric_limits<T>::max();\n\
    \    };\n    static E id_E() {\n        return 0;\n    };\n    static T op_TT(const\
    \ T &a, const T &b) {\n        return std::min(a, b);\n    }\n    static E op_EE(const\
    \ E &a, const E &b) {\n        return a + b;\n    }\n    static T op_TE(const\
    \ T &a, const E &b) {\n        return a + b;\n    }\n};\n"
  code: "#include <cassert>\n#include <limits>\n#include <vector>\n\ntemplate <typename\
    \ S> struct lazy_segment_tree {\n    using T = typename S::T;\n    using E = typename\
    \ S::E;\n    int n;\n    std::vector<T> data;\n    std::vector<E> lazy;\n    lazy_segment_tree(int\
    \ n) : n(n), data(n << 1, S::id_T()), lazy(n << 1, S::id_E()) {\n    }\n    lazy_segment_tree(const\
    \ std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, S::id_E())\
    \ {\n        std::copy(src.begin(), src.end(), data.begin() + n);\n        for\
    \ (int i = n - 1; i > 0; i--) {\n            data[i] = S::op_TT(data[i << 1 |\
    \ 0], data[i << 1 | 1]);\n        }\n    }\n    void propagate(int i) {\n    \
    \    if (i < 1) {\n            return;\n        }\n        data[i] = S::op_TE(data[i],\
    \ lazy[i]);\n        if (i < n) {\n            lazy[i << 1 | 0] = S::op_EE(lazy[i\
    \ << 1 | 0], lazy[i]);\n            lazy[i << 1 | 1] = S::op_EE(lazy[i << 1 |\
    \ 1], lazy[i]);\n        }\n        lazy[i] = S::id_E();\n    }\n    void apply(int\
    \ l, int r, const E &x) {\n        l += n, r += n - 1;\n        for (int i = std::__lg(r);\
    \ i > 0; i--) {\n            propagate(l >> i);\n            propagate(r >> i);\n\
    \        }\n        auto update = [&](int i) { lazy[i] = S::op_EE(lazy[i], x),\
    \ propagate(i); };\n        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1)\
    \ {\n            if (i & 1) {\n                update(i++);\n            }\n \
    \           if (j & 1) {\n                update(--j);\n            }\n      \
    \  }\n        while (l >>= 1, r >>= 1) {\n            data[l] =\n            \
    \    S::op_TT(S::op_TE(data[l << 1 | 0], lazy[l << 1 | 0]), S::op_TE(data[l <<\
    \ 1 | 1], lazy[l << 1 | 1]));\n            data[r] =\n                S::op_TT(S::op_TE(data[r\
    \ << 1 | 0], lazy[r << 1 | 0]), S::op_TE(data[r << 1 | 1], lazy[r << 1 | 1]));\n\
    \        }\n    }\n    T fold(int l, int r) {\n        l += n, r += n - 1;\n \
    \       for (int i = std::__lg(r); i > 0; i--) {\n            propagate(l >> i),\
    \ propagate(r >> i);\n        }\n        T a = S::id_T(), b = S::id_T();\n   \
    \     for (r++; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n       \
    \         propagate(l), a = S::op_TT(a, data[l++]);\n            }\n         \
    \   if (r & 1) {\n                propagate(--r), b = S::op_TT(data[r], b);\n\
    \            }\n        }\n        return S::op_TT(a, b);\n    }\n};\n\nstruct\
    \ rminq_and_ruq {\n    using T = int;\n    using E = int;\n    static T id_T()\
    \ {\n        return std::numeric_limits<T>::max();\n    };\n    static E id_E()\
    \ {\n        return -1;\n    };\n    static T op_TT(const T &a, const T &b) {\n\
    \        return std::min(a, b);\n    }\n    static E op_EE(const E &a, const E\
    \ &b) {\n        return b == id_E() ? a : b;\n    }\n    static T op_TE(const\
    \ T &a, const E &b) {\n        return b == id_E() ? a : b;\n    }\n};\n\nstruct\
    \ rsq_and_raq {\n    using T = std::pair<long long, int>;\n    using E = long\
    \ long;\n    static T id_T() {\n        return {0, 0};\n    };\n    static E id_E()\
    \ {\n        return 0;\n    };\n    static T op_TT(const T &a, const T &b) {\n\
    \        return {a.first + b.first, a.second + b.second};\n    }\n    static E\
    \ op_EE(const E &a, const E &b) {\n        return a + b;\n    }\n    static T\
    \ op_TE(const T &a, const E &b) {\n        return {a.first + b * a.second, a.second};\n\
    \    }\n};\n\nstruct rminq_and_raq {\n    using T = long long;\n    using E =\
    \ long long;\n    static T id_T() {\n        return std::numeric_limits<T>::max();\n\
    \    };\n    static E id_E() {\n        return 0;\n    };\n    static T op_TT(const\
    \ T &a, const T &b) {\n        return std::min(a, b);\n    }\n    static E op_EE(const\
    \ E &a, const E &b) {\n        return a + b;\n    }\n    static T op_TE(const\
    \ T &a, const E &b) {\n        return a + b;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-04-04 16:30:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/RMQ-and-RAQ-0.test.cpp
  - test/AOJ/DSL/RMQ-and-RUQ-0.test.cpp
  - test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
  - test/AOJ/Volume26/Tree-0.test.cpp
documentation_of: data-structure/lazy-segment-tree.hpp
layout: document
title: "\u9045\u5EF6\u8A55\u4FA1 Segment \u6728"
---

- `<S> struct lazy_segment_tree`  
  列への区間適用クエリと区間演算クエリを処理する。

  - `(constructor)(int n)`  
    `n`は要素数。列の全要素を単位元で初期化。

  - `(constructor)(std::vector<std::vector<T>> src)`  
    `n`は要素数。列を`src`で初期化。

  - `void apply(int l, int r, T x)`  
    `[l, r)`を`x`に適用。

  - `T fold(int l, int r)`  
    `[l, r)`の区間演算を返す。

- `struct S`  
  列に載せる値、作用素はいずれもモノイドをなす。  

  - `struct T`  
    列に載せる値の型。

  - `struct E`  
    作用素の型。

  - `T id_T()`  
    `T`の`op_TT`に関する単位元。

  - `E id_E()`  
    `E`の`op_EE`に関する単位元。

  - `T op_TT(T a, T b)`  
    `T`と`T`の演算。

  - `T op_TE(T a, E b)`  
    `T`と`E`の演算。

  - `E op_EE(E a, E b)`  
    `E`と`E`の演算。  

  これらの演算は以下を満たす。  
  - `op_TE(op_TT(a, b), c) = op_TT(op_TE(a, c), op_TE(b, c))`
  - `op_TE(op_TE(a, b), c) = op_TE(a, op_EE(b, c))`
