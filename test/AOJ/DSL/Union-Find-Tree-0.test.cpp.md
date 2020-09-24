---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/union-find-tree.hpp
    title: "Union-Find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp
  bundledCode: "#line 1 \"test/AOJ/DSL/Union-Find-Tree-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp\"\
    \n#line 1 \"data-structure/union-find-tree.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ S>\nstruct union_find_tree {\n    using T = typename S::T;\n    std::vector<int>\
    \ parent, size_;\n    std::vector<T> val;\n    union_find_tree(const std::vector<T>\
    \ &val) : parent(val.size(), -1), size_(val.size(), 1), val(val) {}\n    union_find_tree(int\
    \ n) : union_find_tree(std::vector<T>(n, S::initial())) {}\n    int root(int i)\
    \ {\n        if (parent[i] == -1) { return i; }\n        else { return parent[i]\
    \ = root(parent[i]); }\n    }\n    void unite(int i, int j) {\n        if ((i\
    \ = root(i)) == (j = root(j))) { return; }\n        if (size_[i] < size_[j]) {\
    \ std::swap(i, j); }\n        size_[i] += size_[j];\n        val[i] = S::op(val[i],\
    \ val[j]);\n        parent[j] = i;\n    }\n    bool same(int i, int j) { return\
    \ root(i) == root(j); }\n    int size(int i) { return size_[root(i)]; }\n    void\
    \ set(int i, const T &x) { val[root(i)] = x; }\n    T operator[](int i) { return\
    \ val[root(i)]; }\n};\n\nstruct normal_uf {\n    struct T {};\n    static T initial()\
    \ { return {}; }\n    static T op(const T &a, const T &b) { return {}; }\n};\n\
    #line 3 \"test/AOJ/DSL/Union-Find-Tree-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    union_find_tree<normal_uf>\
    \ uf(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) { uf.unite(x, y); }\n        else if\
    \ (com == 1) { cout << uf.same(x, y) << endl; }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp\"\
    \n#include\"../../../data-structure/union-find-tree.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    union_find_tree<normal_uf>\
    \ uf(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) { uf.unite(x, y); }\n        else if\
    \ (com == 1) { cout << uf.same(x, y) << endl; }\n    }\n}"
  dependsOn:
  - data-structure/union-find-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-24 22:53:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/Union-Find-Tree-0.test.cpp
- /verify/test/AOJ/DSL/Union-Find-Tree-0.test.cpp.html
title: test/AOJ/DSL/Union-Find-Tree-0.test.cpp
---
