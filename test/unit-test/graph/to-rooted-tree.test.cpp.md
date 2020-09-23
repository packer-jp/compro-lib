---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/to-rooted-tree.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306B\u5909\u63DB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/graph/to-rooted-tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"graph/to-rooted-tree.hpp\"\n#include <vector>\n\nstd::vector<int>\
    \ to_rooted_tree(const std::vector<std::vector<int>> &adj, int s) {\n    std::vector<int>\
    \ ret(adj.size());\n    auto dfs = [&](auto &&self, int cur, int par) -> void\
    \ {\n        ret[cur] = par;\n        for (int i = 0; i < adj[cur].size(); i++)\
    \ {\n            if (adj[cur][i] == par) { continue; }\n            self(self,\
    \ adj[cur][i], cur);\n        }\n    };\n    dfs(dfs, s, -1);\n    return ret;\n\
    }\n#line 3 \"test/unit-test/graph/to-rooted-tree.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int N = 10;\n    vector<vector<int>>\
    \ adj(N, vector<int>());\n    auto add_edge = [&](int u, int v) { adj[u].push_back(v),\
    \ adj[v].push_back(u); };\n    add_edge(7, 2);\n    add_edge(2, 6);\n    add_edge(4,\
    \ 2);\n    add_edge(4, 3);\n    add_edge(5, 4);\n    add_edge(5, 1);\n    add_edge(1,\
    \ 0);\n    add_edge(0, 9);\n    add_edge(5, 8);\n    vector<int> r5 = {1, 5, 4,\
    \ 4, 5, -1, 2, 2, 5, 0};\n    assert(to_rooted_tree(adj, 5) == r5);\n    cout\
    \ << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../graph/to-rooted-tree.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int N = 10;\n    vector<vector<int>> adj(N,\
    \ vector<int>());\n    auto add_edge = [&](int u, int v) { adj[u].push_back(v),\
    \ adj[v].push_back(u); };\n    add_edge(7, 2);\n    add_edge(2, 6);\n    add_edge(4,\
    \ 2);\n    add_edge(4, 3);\n    add_edge(5, 4);\n    add_edge(5, 1);\n    add_edge(1,\
    \ 0);\n    add_edge(0, 9);\n    add_edge(5, 8);\n    vector<int> r5 = {1, 5, 4,\
    \ 4, 5, -1, 2, 2, 5, 0};\n    assert(to_rooted_tree(adj, 5) == r5);\n    cout\
    \ << \"Hello World\" << endl;\n}"
  dependsOn:
  - graph/to-rooted-tree.hpp
  isVerificationFile: true
  path: test/unit-test/graph/to-rooted-tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit-test/graph/to-rooted-tree.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/graph/to-rooted-tree.test.cpp
- /verify/test/unit-test/graph/to-rooted-tree.test.cpp.html
title: test/unit-test/graph/to-rooted-tree.test.cpp
---
