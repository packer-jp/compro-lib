---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/get-prime-table.hpp
    title: "\u7D20\u6570\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ/ALDS1/Prime-Numbers-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n#line 1 \"mathematics/get-prime-table.hpp\"\n#include <vector>\n\nstd::vector<bool>\
    \ get_prime_table(int n) {\n    std::vector<bool> ret(n + 1, true);\n    if (n\
    \ >= 0) { ret[0] = false; }\n    if (n >= 1) { ret[1] = false; }\n    for (int\
    \ i = 2; i * i <= n; i++) {\n        if (!ret[i]) { continue; }\n        for (int\
    \ j = i << 1; j <= n; j += i) {\n            ret[j] = false;\n        }\n    }\n\
    \    return ret;\n}\n#line 3 \"test/AOJ/ALDS1/Prime-Numbers-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    vector<bool> pt = get_prime_table(100000000);\n\
    \    int n;\n    cin >> n;\n    int ans = 0;\n    for (int i = 0; i < n; i++)\
    \ {\n        int a;\n        cin >> a;\n        ans += pt[a];\n    }\n    cout\
    \ << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja\"\
    \n#include\"../../../mathematics/get-prime-table.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    vector<bool> pt = get_prime_table(100000000);\n\
    \    int n;\n    cin >> n;\n    int ans = 0;\n    for (int i = 0; i < n; i++)\
    \ {\n        int a;\n        cin >> a;\n        ans += pt[a];\n    }\n    cout\
    \ << ans << endl;\n}"
  dependsOn:
  - mathematics/get-prime-table.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
- /verify/test/AOJ/ALDS1/Prime-Numbers-0.test.cpp.html
title: test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
---
