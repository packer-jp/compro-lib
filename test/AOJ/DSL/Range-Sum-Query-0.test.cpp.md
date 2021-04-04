---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: data-structure/segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja
  bundledCode: "#line 1 \"test/AOJ/DSL/Range-Sum-Query-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja\"\
    \n#line 1 \"data-structure/segment-tree.hpp\"\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n\ntemplate <typename S> struct segment_tree {\n    using T\
    \ = typename S::T;\n    int n;\n    std::vector<T> data;\n    segment_tree(int\
    \ n) : n(n), data(n << 1, S::id()) {\n    }\n    segment_tree(const std::vector<T>\
    \ &src) : n(src.size()), data(n << 1) {\n        std::copy(src.begin(), src.end(),\
    \ data.begin() + n);\n        for (int i = n - 1; i > 0; i--) {\n            data[i]\
    \ = S::op(data[i << 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    /**\n  \
    \   * @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u7F6E\u304D\
    \u63DB\u3048\u5148\n     **/\n    void set(int i, const T &x) {\n        data[i\
    \ += n] = x;\n        while (i >>= 1) {\n            data[i] = S::op(data[i <<\
    \ 1 | 0], data[i << 1 | 1]);\n        }\n    }\n    const T &operator[](int i)\
    \ const {\n        return data[i + n];\n    }\n    T fold(int l, int r) const\
    \ {\n        T a = S::id(), b = S::id();\n        for (l += n, r += n; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) {\n                a = S::op(a,\
    \ data[l++]);\n            }\n            if (r & 1) {\n                b = S::op(data[--r],\
    \ b);\n            }\n        }\n        return S::op(a, b);\n    }\n};\n\nstruct\
    \ rsq {\n    using T = int;\n    static T op(const T &a, const T &b) {\n     \
    \   return a + b;\n    }\n    static T id() {\n        return 0;\n    }\n};\n\n\
    struct rminq {\n    using T = int;\n    static T op(const T &a, const T &b) {\n\
    \        return std::min(a, b);\n    }\n    static T id() {\n        return std::numeric_limits<T>::max();\n\
    \    }\n};\n#line 3 \"test/AOJ/DSL/Range-Sum-Query-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    segment_tree<rsq>\
    \ rsq(n + 1);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n   \
    \     cin >> com >> x >> y;\n        if (com == 0) { rsq.set(x, rsq[x] + y); }\n\
    \        else if (com == 1) { cout << rsq.fold(x, y + 1) << endl; }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja\"\
    \n#include\"../../../data-structure/segment-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    segment_tree<rsq>\
    \ rsq(n + 1);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n   \
    \     cin >> com >> x >> y;\n        if (com == 0) { rsq.set(x, rsq[x] + y); }\n\
    \        else if (com == 1) { cout << rsq.fold(x, y + 1) << endl; }\n    }\n}"
  dependsOn:
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 16:30:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Range-Sum-Query-0.test.cpp
- /verify/test/AOJ/DSL/Range-Sum-Query-0.test.cpp.html
title: test/AOJ/DSL/Range-Sum-Query-0.test.cpp
---
