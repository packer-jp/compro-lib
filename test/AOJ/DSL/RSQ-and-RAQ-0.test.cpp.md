---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1 Segment \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja\"\n#line\
    \ 1 \"data-structure/lazy-segment-tree.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <limits>\n\ntemplate<typename M>\nstruct lazy_segment_tree {\n    using\
    \ T = typename M::T;\n    using E = typename M::E;\n    int n;\n    std::vector<T>\
    \ data;\n    std::vector<E> lazy;\n    lazy_segment_tree(int n) : n(n), data(n\
    \ << 1, M::id_T()), lazy(n << 1, M::id_E()) {}\n    lazy_segment_tree(const std::vector<T>\
    \ &src) : n(src.size()), data(n << 1), lazy(n << 1, M::id_E()) {\n        std::copy(src.begin(),\
    \ src.end(), data.begin() + n);\n        for (int i = n - 1; i > 0; i--) { data[i]\
    \ = M::op_TT(data[i << 1 | 0], data[i << 1 | 1]); }\n    }\n    void propagate(int\
    \ i) {\n        if (i < 1) { return; }\n        data[i] = M::op_TE(data[i], lazy[i]);\n\
    \        if (i < n) {\n            lazy[i << 1 | 0] = M::op_EE(lazy[i << 1 | 0],\
    \ lazy[i]);\n            lazy[i << 1 | 1] = M::op_EE(lazy[i << 1 | 1], lazy[i]);\n\
    \        }\n        lazy[i] = M::id_E();\n    }\n    void apply(int l, int r,\
    \ const E &x) {\n        l += n, r += n - 1;\n        for (int i = std::__lg(r);\
    \ i > 0; i--) {\n            propagate(l >> i);\n            propagate(r >> i);\n\
    \        }\n        auto update = [&](int i) { lazy[i] = M::op_EE(lazy[i], x),\
    \ propagate(i); };\n        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1)\
    \ {\n            if (i & 1) { update(i++); }\n            if (j & 1) { update(--j);\
    \ }\n        }\n        while (l >>= 1, r >>= 1) {\n            data[l] = M::op_TT(M::op_TE(data[l\
    \ << 1 | 0], lazy[l << 1 | 0]),\n                               M::op_TE(data[l\
    \ << 1 | 1], lazy[l << 1 | 1]));\n            data[r] = M::op_TT(M::op_TE(data[r\
    \ << 1 | 0], lazy[r << 1 | 0]),\n                               M::op_TE(data[r\
    \ << 1 | 1], lazy[r << 1 | 1]));\n        }\n    }\n    T fold(int l, int r) {\n\
    \        l += n, r += n - 1;\n        for (int i = std::__lg(r); i > 0; i--) {\
    \ propagate(l >> i), propagate(r >> i); }\n        T a = M::id_T(), b = M::id_T();\n\
    \        for (r++; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) { propagate(l),\
    \ a = M::op_TT(a, data[l++]); }\n            if (r & 1) { propagate(--r), b =\
    \ M::op_TT(data[r], b); }\n        }\n        return M::op_TT(a, b);\n    }\n\
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
    \ }\n};\n#line 3 \"test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    lazy_segment_tree<rsq_and_raq>\
    \ lst(vector<pair<long long, int>>(n + 1, {0, 1}));\n    for (int i = 0; i < q;\
    \ i++) {\n        int com;\n        cin >> com;\n        if (com == 0) {\n   \
    \         int s, t;\n            long long x;\n            cin >> s >> t >> x;\n\
    \            lst.apply(s, t + 1, x);\n        } else if (com == 1) {\n       \
    \     int s, t;\n            cin >> s >> t;\n            cout << lst.fold(s, t\
    \ + 1).first << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja\"\
    \n#include\"../../../data-structure/lazy-segment-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    lazy_segment_tree<rsq_and_raq>\
    \ lst(vector<pair<long long, int>>(n + 1, {0, 1}));\n    for (int i = 0; i < q;\
    \ i++) {\n        int com;\n        cin >> com;\n        if (com == 0) {\n   \
    \         int s, t;\n            long long x;\n            cin >> s >> t >> x;\n\
    \            lst.apply(s, t + 1, x);\n        } else if (com == 1) {\n       \
    \     int s, t;\n            cin >> s >> t;\n            cout << lst.fold(s, t\
    \ + 1).first << endl;\n        }\n    }\n}"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
- /verify/test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp.html
title: test/AOJ/DSL/RSQ-and-RAQ-0.test.cpp
---
