---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/get-divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp
  bundledCode: "#line 1 \"test/AOJ/ITP1/How-Many-Divisors-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp\"\
    \n#line 1 \"mathematics/get-divisors.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate<typename T> std::vector<T> get_divisors(T n) {\n    std::vector<T>\
    \ ret;\n    T i;\n    for (i = 1; i * i < n; i++) {\n        if (n % i == 0) {\n\
    \            ret.emplace_back(i);\n            ret.emplace_back(n / i);\n    \
    \    }\n    }\n    if (i * i == n) { ret.emplace_back(i); }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n#line 3 \"test/AOJ/ITP1/How-Many-Divisors-0.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int a,\
    \ b, c;\n    cin >> a >> b >> c;\n    vector<int> div = get_divisors(c);\n   \
    \ int ans = 0;\n    for (int i = 0; i < (int) div.size(); i++) { ans += a <= div[i]\
    \ && div[i] <= b; }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp\"\
    \n#include\"../../../mathematics/get-divisors.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int a, b, c;\n    cin >> a >> b >> c;\n\
    \    vector<int> div = get_divisors(c);\n    int ans = 0;\n    for (int i = 0;\
    \ i < (int) div.size(); i++) { ans += a <= div[i] && div[i] <= b; }\n    cout\
    \ << ans << endl;\n}\n"
  dependsOn:
  - mathematics/get-divisors.hpp
  isVerificationFile: true
  path: test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
- /verify/test/AOJ/ITP1/How-Many-Divisors-0.test.cpp.html
title: test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
---
