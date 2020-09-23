---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/strongly-connected-components.hpp
    title: graph/strongly-connected-components.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp
  bundledCode: "#line 1 \"test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp\"\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp\"\
    \n#line 1 \"graph/strongly-connected-components.hpp\"\n#include <vector>\n\nstd::vector<int>\
    \ strongly_connected_components(const std::vector<std::vector<int>> &adj) {\n\
    \    int n = adj.size();\n    std::vector<int> vs;\n    {\n        std::vector<bool>\
    \ visited(n);\n        auto dfs = [&](auto &&self, int cur) -> void {\n      \
    \      if (visited[cur]) { return; }\n            visited[cur] = true;\n     \
    \       for (int i = 0; i < adj[cur].size(); i++) { self(self, adj[cur][i]); }\n\
    \            vs.push_back(cur);\n        };\n        for (int i = 0; i < n; i++)\
    \ { dfs(dfs, i); }\n    }\n    std::vector<int> ret(n);\n    {\n        std::vector<bool>\
    \ visited(n);\n        std::vector<std::vector<int>> radj(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int j = 0; j < adj[i].size(); j++) {\
    \ radj[adj[i][j]].push_back(i); }\n        }\n        int k = 0;\n        auto\
    \ dfs = [&](auto &&self, int cur) -> void {\n            visited[cur] = true;\n\
    \            ret[cur] = k;\n            for (int i = 0; i < radj[cur].size();\
    \ i++) {\n                if (!visited[radj[cur][i]]) { self(self, radj[cur][i]);\
    \ }\n            }\n        };\n        for (int i = n - 1; i >= 0; i--) { if\
    \ (!visited[vs[i]]) { dfs(dfs, vs[i]), k++; }}\n    }\n    return ret;\n}\n#line\
    \ 3 \"test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>>\
    \ adj(V);\n    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >>\
    \ s >> t;\n        adj[s].push_back(t);\n    }\n    vector<int> cmp = strongly_connected_components(adj);\n\
    \    int Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        cout << (cmp[u] == cmp[v]) << endl;\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp\"\
    \n#include\"../../../graph/strongly-connected-components.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>>\
    \ adj(V);\n    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >>\
    \ s >> t;\n        adj[s].push_back(t);\n    }\n    vector<int> cmp = strongly_connected_components(adj);\n\
    \    int Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        cout << (cmp[u] == cmp[v]) << endl;\n  \
    \  }\n}"
  dependsOn:
  - graph/strongly-connected-components.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
- /verify/test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp.html
title: test/AOJ/GRL/Strongly-Connected-Components-0.test.cpp
---
