---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/re-rooting.hpp
    title: graph/re-rooting.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp
  bundledCode: "#line 1 \"test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp\"\
    \n#line 1 \"graph/re-rooting.hpp\"\n#include <vector>\n\ntemplate<typename M>\n\
    std::vector<typename M::T> re_rooting(const std::vector<std::vector<int>> &adj,\n\
    \                                      const std::vector<std::vector<typename\
    \ M::E>> &cost) {\n    using T = typename M::T;\n    int n = adj.size();\n   \
    \ std::vector<std::vector<T>> dp(n);\n    auto dfs0 = [&](auto &&dfs0, int cur,\
    \ int par) -> T {\n        dp[cur].resize(adj[cur].size());\n        T cum = M::id();\n\
    \        for (int i = 0; i < adj[cur].size(); i++) {\n            if (adj[cur][i]\
    \ == par) { continue; }\n            dp[cur][i] = M::op_TE(dfs0(dfs0, adj[cur][i],\
    \ cur), cost[cur][i]);\n            cum = M::op_TT(cum, dp[cur][i]);\n       \
    \ }\n        return cum;\n    };\n    dfs0(dfs0, 0, -1);\n    std::vector<T> ret(n);\n\
    \    auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop) -> void {\n      \
    \  int m = adj[cur].size();\n        std::vector<T> l_cum(m + 1), r_cum(m + 1);\n\
    \        l_cum[0] = r_cum[m] = M::id();\n        for (int i = 0; i < m; i++) {\n\
    \            if (adj[cur][i] == par) { dp[cur][i] = M::op_TE(drop, cost[cur][i]);\
    \ }\n            l_cum[i + 1] = M::op_TT(l_cum[i], dp[cur][i]);\n        }\n \
    \       for (int i = m - 1; i >= 0; i--) { r_cum[i] = M::op_TT(dp[cur][i], r_cum[i\
    \ + 1]); }\n        for (int i = 0; i < m; i++) {\n            if (adj[cur][i]\
    \ == par) { continue; }\n            dfs1(dfs1, adj[cur][i], cur, M::op_TT(l_cum[i],\
    \ r_cum[i + 1]));\n        }\n        ret[cur] = l_cum[m];\n    };\n    dfs1(dfs1,\
    \ 0, -1, M::id());\n    return ret;\n}\n\nstruct diameter_rr {\n    using T =\
    \ int;\n    using E = int;\n    static T id() { return 0; }\n    static T op_TT(const\
    \ T &a, const T &b) { return std::max(a, b); }\n    static T op_TE(const T &a,\
    \ const E &b) { return a + b; }\n};\n#line 3 \"test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    vector<vector<int>> adj(n, vector<int>()), cost(n, vector<int>());\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        adj[s].push_back(t), adj[t].push_back(s);\n        cost[s].push_back(w),\
    \ cost[t].push_back(w);\n    }\n    vector<int> cands = re_rooting<diameter_rr>(adj,\
    \ cost);\n    int ans = 0;\n    for (int i = 0; i < n; i++) { ans = max(ans, cands[i]);\
    \ }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp\"\
    \n#include \"../../../graph/re-rooting.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>>\
    \ adj(n, vector<int>()), cost(n, vector<int>());\n    for (int i = 0; i < n -\
    \ 1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        adj[s].push_back(t),\
    \ adj[t].push_back(s);\n        cost[s].push_back(w), cost[t].push_back(w);\n\
    \    }\n    vector<int> cands = re_rooting<diameter_rr>(adj, cost);\n    int ans\
    \ = 0;\n    for (int i = 0; i < n; i++) { ans = max(ans, cands[i]); }\n    cout\
    \ << ans << endl;\n}"
  dependsOn:
  - graph/re-rooting.hpp
  isVerificationFile: true
  path: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
- /verify/test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp.html
title: test/AOJ/GRL/Diameter-of-a-Tree-0.test.cpp
---
