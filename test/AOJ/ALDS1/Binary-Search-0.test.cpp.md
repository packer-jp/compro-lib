---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/binary-search.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
  bundledCode: "#line 1 \"test/AOJ/ALDS1/Binary-Search-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja\"\
    \n#line 1 \"utility/binary-search.hpp\"\n#include <cstdlib>\n\n/*\n * @title \u4E8C\
    \u5206\u63A2\u7D22\n * @docs docs/utility/binary-search.md\n */\n\ntemplate<typename\
    \ F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {\n\
    \    while (abs(ok - ng) > 1) {\n        long long mid = (ok + ng) / 2;\n    \
    \    (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate<typename\
    \ F> double continuous_binary_search(double ok, double ng, F is_ok, int n) {\n\
    \    for (int i = 0; i < n; i++) {\n        double mid = (ok + ng) / 2;\n    \
    \    (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n#line 3 \"test/AOJ/ALDS1/Binary-Search-0.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    vector<int> S(n + 1);\n    for (int i = 0; i < n; i++) { cin\
    \ >> S[i]; }\n    S[n] = INT_MAX;\n    int q;\n    cin >> q;\n    vector<int>\
    \ T(n);\n    for (int i = 0; i < q; i++) { cin >> T[i]; }\n    int ans = 0;\n\
    \    for (int i = 0; i < q; i++) {\n        int idx = discrete_binary_search(n,\
    \ -1, [&](int x) { return S[x] >= T[i]; });\n        if (S[idx] == T[i]) { ans++;\
    \ }\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja\"\
    \n#include \"../../../utility/binary-search.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ S(n + 1);\n    for (int i = 0; i < n; i++) { cin >> S[i]; }\n    S[n] = INT_MAX;\n\
    \    int q;\n    cin >> q;\n    vector<int> T(n);\n    for (int i = 0; i < q;\
    \ i++) { cin >> T[i]; }\n    int ans = 0;\n    for (int i = 0; i < q; i++) {\n\
    \        int idx = discrete_binary_search(n, -1, [&](int x) { return S[x] >= T[i];\
    \ });\n        if (S[idx] == T[i]) { ans++; }\n    }\n    cout << ans << endl;\n\
    }"
  dependsOn:
  - utility/binary-search.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1/Binary-Search-0.test.cpp
  requiredBy: []
  timestamp: '2020-05-12 23:01:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1/Binary-Search-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1/Binary-Search-0.test.cpp
- /verify/test/AOJ/ALDS1/Binary-Search-0.test.cpp.html
title: test/AOJ/ALDS1/Binary-Search-0.test.cpp
---
