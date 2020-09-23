---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low-link.hpp
    title: graph/low-link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/GRL/Articulation-Points-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja\"\
    \n#line 1 \"graph/low-link.hpp\"\n#include <vector>\n#include <algorithm>\n\n\
    struct low_link {\n    int n;\n    std::vector<int> ord, low, articulations;\n\
    \    std::vector<std::vector<int>> adj;\n    std::vector<std::pair<int, int>>\
    \ bridges;\n    low_link(const std::vector<std::vector<int>> &adj) : n(adj.size()),\
    \ adj(adj), ord(n), low(n) {\n        std::vector<bool> visited(n);\n        int\
    \ k = 0;\n        auto dfs = [&](auto &&self, int cur, int par) -> void {\n  \
    \          visited[cur] = true;\n            ord[cur] = k++;\n            low[cur]\
    \ = ord[cur];\n            int cnt = 0;\n            bool is_articulation = false;\n\
    \            for (int to : adj[cur]) {\n                if (!visited[to]) {\n\
    \                    cnt++;\n                    self(self, to, cur);\n      \
    \              low[cur] = std::min(low[cur], low[to]);\n                    is_articulation\
    \ |= ord[cur] <= low[to];\n                    if (ord[cur] < low[to]) { bridges.emplace_back(std::minmax(cur,\
    \ to)); }\n                } else if (to != par) { low[cur] = std::min(low[cur],\
    \ ord[to]); }\n            }\n            if (par == -1) { is_articulation = cnt\
    \ >= 2; }\n            if (is_articulation) { articulations.emplace_back(cur);\
    \ }\n        };\n        dfs(dfs, 0, -1);\n    }\n};\n#line 3 \"test/AOJ/GRL/Articulation-Points-0.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int V,\
    \ E;\n    cin >> V >> E;\n    vector<vector<int>> adj(V);\n    for (int i = 0;\
    \ i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n        adj[s].emplace_back(t);\n\
    \        adj[t].emplace_back(s);\n    }\n    low_link ll(adj);\n    sort(ll.articulations.begin(),\
    \ ll.articulations.end());\n    for (auto p:ll.articulations) { cout << p << endl;\
    \ }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja\"\
    \n#include \"../../../graph/low-link.hpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>>\
    \ adj(V);\n    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >>\
    \ s >> t;\n        adj[s].emplace_back(t);\n        adj[t].emplace_back(s);\n\
    \    }\n    low_link ll(adj);\n    sort(ll.articulations.begin(), ll.articulations.end());\n\
    \    for (auto p:ll.articulations) { cout << p << endl; }\n}"
  dependsOn:
  - graph/low-link.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Articulation-Points-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Articulation-Points-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Articulation-Points-0.test.cpp
- /verify/test/AOJ/GRL/Articulation-Points-0.test.cpp.html
title: test/AOJ/GRL/Articulation-Points-0.test.cpp
---
