---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/prime-factorize.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/NTL/Prime-Factorize-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#line 1 \"mathematics/prime-factorize.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ T> std::vector<T> prime_factorize(T n) {\n    std::vector<T> ret;\n    for (T\
    \ i = 2; i * i <= n; i++) {\n        while (n % i == 0) {\n            ret.emplace_back(i);\n\
    \            n /= i;\n        }\n    }\n    if (n != 1) { ret.emplace_back(n);\
    \ }\n    return ret;\n}\n#line 3 \"test/AOJ/NTL/Prime-Factorize-0.test.cpp\"\n\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    cout << n << \":\";\n    auto v = prime_factorize(n);\n  \
    \  for (int i = 0; i < v.size(); i++) { cout << \" \" << v[i]; }\n    cout <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#include\"../../../mathematics/prime-factorize.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    cout << n\
    \ << \":\";\n    auto v = prime_factorize(n);\n    for (int i = 0; i < v.size();\
    \ i++) { cout << \" \" << v[i]; }\n    cout << endl;\n}\n"
  dependsOn:
  - mathematics/prime-factorize.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/Prime-Factorize-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/Prime-Factorize-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/Prime-Factorize-0.test.cpp
- /verify/test/AOJ/NTL/Prime-Factorize-0.test.cpp.html
title: test/AOJ/NTL/Prime-Factorize-0.test.cpp
---
