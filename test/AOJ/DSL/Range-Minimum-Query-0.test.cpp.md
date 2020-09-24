---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: "Segment \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DSL/Range-Minimum-Query-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja\"\
    \n#line 1 \"data-structure/segment-tree.hpp\"\n#include <vector>\n#include <cassert>\n\
    #include <limits>\n\ntemplate<typename S>\nstruct segment_tree {\n    using T\
    \ = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, S::id()) {}\n    segment_tree(const std::vector<T> &src)\
    \ : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(), data.begin()\
    \ + n);\n        for (int i = n - 1; i > 0; i--) { data[i] = S::op(data[i << 1\
    \ | 0], data[i << 1 | 1]); }\n    }\n    void set(int i, const T &x) {\n     \
    \   data[i += n] = x;\n        while (i >>= 1) { data[i] = S::op(data[i << 1 |\
    \ 0], data[i << 1 | 1]); }\n    }\n    const T &operator[](int i) const { return\
    \ data[i + n]; }\n    T fold(int l, int r) const {\n        T a = S::id(), b =\
    \ S::id();\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) { a = S::op(a, data[l++]); }\n            if (r & 1) { b = S::op(data[--r],\
    \ b); }\n        }\n        return S::op(a, b);\n    }\n};\n\nstruct rsq {\n \
    \   using T = int;\n    static T op(const T &a, const T &b) { return a + b; }\n\
    \    static T id() { return 0; }\n};\n\nstruct rminq {\n    using T = int;\n \
    \   static T op(const T &a, const T &b) { return std::min(a, b); }\n    static\
    \ T id() { return std::numeric_limits<T>::max(); }\n};\n#line 3 \"test/AOJ/DSL/Range-Minimum-Query-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    segment_tree<rminq> rmq(n);\n    for (int i = 0;\
    \ i < q; i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if (com == 0) { rmq.set(x, y); }\n        else if (com == 1) { cout << rmq.fold(x,\
    \ y + 1) << endl; }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja\"\
    \n#include\"../../../data-structure/segment-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    segment_tree<rminq>\
    \ rmq(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n       \
    \ cin >> com >> x >> y;\n        if (com == 0) { rmq.set(x, y); }\n        else\
    \ if (com == 1) { cout << rmq.fold(x, y + 1) << endl; }\n    }\n}"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
- /verify/test/AOJ/DSL/Range-Minimum-Query-0.test.cpp.html
title: test/AOJ/DSL/Range-Minimum-Query-0.test.cpp
---
