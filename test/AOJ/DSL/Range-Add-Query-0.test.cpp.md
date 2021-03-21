---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick-tree.hpp
    title: "Fenwick \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
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
    \ntemplate<typename S>\nstruct fenwick_tree {\n    using T = typename S::T;\n\
    \    int n;\n    std::vector<T> data;\n    fenwick_tree(int n) : n(n), data(n\
    \ + 1, S::zero()) {}\n    void add(int i, const T &x) {\n        for (i++; i <=\
    \ n; i += i & -i) { data[i] = S::plus(data[i], x); }\n    }\n    T sum(int i)\
    \ const {\n        T ret = S::zero();\n        for (; i > 0; i -= i & -i) { ret\
    \ = S::plus(ret, data[i]); }\n        return ret;\n    }\n    T sum(int l, int\
    \ r) const { return S::plus(S::minus(sum(l)), sum(r)); }\n};\n\ntemplate<typename\
    \ S>\nstruct fenwick_tree_range : public fenwick_tree<S> {\n    using F = fenwick_tree<S>;\n\
    \    using T = typename S::T;\n    fenwick_tree_range(int n) : F(n) {}\n    void\
    \ add(int l, int r, const T &x) { F::add(l, x), F::add(r, S::minus(x)); }\n  \
    \  T operator[](int i) const { return F::sum(i + 1); }\n};\n\nstruct rsq {\n \
    \   using T = int;\n    static T zero() { return 0; }\n    static T plus(const\
    \ T &a, const T &b) { return a + b; }\n    static T minus(const T &a) { return\
    \ -a; }\n};\n#line 3 \"test/AOJ/DSL/Range-Add-Query-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    fenwick_tree_range<rsq>\
    \ ft(n);\n    for (int i = 0; i < q; i++) {\n        int com;\n        cin >>\
    \ com;\n        if (com == 0) {\n            int s, t, x;\n            cin >>\
    \ s >> t >> x;\n            s--, t--;\n            ft.add(s, t + 1, x);\n    \
    \    } else if (com == 1) {\n            int i;\n            cin >> i;\n     \
    \       i--;\n            cout << ft[i] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp\"\
    \n#include\"../../../data-structure/fenwick-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    fenwick_tree_range<rsq>\
    \ ft(n);\n    for (int i = 0; i < q; i++) {\n        int com;\n        cin >>\
    \ com;\n        if (com == 0) {\n            int s, t, x;\n            cin >>\
    \ s >> t >> x;\n            s--, t--;\n            ft.add(s, t + 1, x);\n    \
    \    } else if (com == 1) {\n            int i;\n            cin >> i;\n     \
    \       i--;\n            cout << ft[i] << endl;\n        }\n    }\n}"
  dependsOn:
  - data-structure/fenwick-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Range-Add-Query-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 00:11:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/Range-Add-Query-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Range-Add-Query-0.test.cpp
- /verify/test/AOJ/DSL/Range-Add-Query-0.test.cpp.html
title: test/AOJ/DSL/Range-Add-Query-0.test.cpp
---
