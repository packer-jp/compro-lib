---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: data-structure/fenwick-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp
  bundledCode: "#line 1 \"test/AOJ/DSL/Range-Add-Query-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp\"\
    \n#line 1 \"data-structure/fenwick-tree.hpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate<typename M>\nstruct fenwick_tree {\n    using T = typename M::T;\n\
    \    int n;\n    std::vector<T> data;\n    fenwick_tree(int n) : n(n), data(n\
    \ + 1, M::id()) {}\n    void apply(int i, const T &x) {\n        for (i++; i <=\
    \ n; i += i & -i) { data[i] = M::op(data[i], x); }\n    }\n    T fold(int i) const\
    \ {\n        T ret = M::id();\n        for (; i > 0; i -= i & -i) { ret = M::op(ret,\
    \ data[i]); }\n        return ret;\n    }\n    T fold(int l, int r) const { return\
    \ M::op(M::inv(fold(l)), fold(r)); }\n};\n\ntemplate<typename M>\nstruct fenwick_tree_range\
    \ : public fenwick_tree<M> {\n    using S = fenwick_tree<M>;\n    using T = typename\
    \ M::T;\n    fenwick_tree_range(int n) : S(n) {}\n    void apply(int l, int r,\
    \ const T &x) { S::apply(l, x), S::apply(r, M::inv(x)); }\n    T operator[](int\
    \ i) const { return S::fold(i + 1); }\n};\n\nstruct rsq {\n    using T = int;\n\
    \    static T id() { return 0; }\n    static T op(const T &a, const T &b) { return\
    \ a + b; }\n    static T inv(const T &a) { return -a; }\n};\n#line 3 \"test/AOJ/DSL/Range-Add-Query-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n,\
    \ q;\n    cin >> n >> q;\n    fenwick_tree_range<rsq> ft(n);\n    for (int i =\
    \ 0; i < q; i++) {\n        int com;\n        cin >> com;\n        if (com ==\
    \ 0) {\n            int s, t, x;\n            cin >> s >> t >> x;\n          \
    \  s--, t--;\n            ft.apply(s, t + 1, x);\n        } else if (com == 1)\
    \ {\n            int i;\n            cin >> i;\n            i--;\n           \
    \ cout << ft[i] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp\"\
    \n#include\"../../../data-structure/fenwick-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    fenwick_tree_range<rsq>\
    \ ft(n);\n    for (int i = 0; i < q; i++) {\n        int com;\n        cin >>\
    \ com;\n        if (com == 0) {\n            int s, t, x;\n            cin >>\
    \ s >> t >> x;\n            s--, t--;\n            ft.apply(s, t + 1, x);\n  \
    \      } else if (com == 1) {\n            int i;\n            cin >> i;\n   \
    \         i--;\n            cout << ft[i] << endl;\n        }\n    }\n}"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Range-Add-Query-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/Range-Add-Query-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Range-Add-Query-0.test.cpp
- /verify/test/AOJ/DSL/Range-Add-Query-0.test.cpp.html
title: test/AOJ/DSL/Range-Add-Query-0.test.cpp
---
