---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/multi-prime-factorize.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (\u8907\u6570\u30AF\u30A8\u30EA)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
  bundledCode: "#line 1 \"test/AOJ/NTL/Prime-Factorize-1.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#line 1 \"mathematics/multi-prime-factorize.hpp\"\n#include <vector>\n#include\
    \ <numeric>\n\nstruct multi_prime_factorize {\n    std::vector<int> spf;\n   \
    \ multi_prime_factorize(int n) : spf(n + 1) {\n        std::iota(spf.begin(),\
    \ spf.end(), 0LL);\n        for (int i = 2; i * i <= n; i++) {\n            if\
    \ (spf[i] < i) { continue; }\n            for (int j = i * i; j <= n; j += i)\
    \ {\n                if (spf[j] == j) { spf[j] = i; }\n            }\n       \
    \ }\n    }\n    std::vector<int> prime_factorize(int n) {\n        std::vector<int>\
    \ ret;\n        while (n > 1) {\n            ret.emplace_back(spf[n]);\n     \
    \       n /= spf[n];\n        }\n        return ret;\n    }\n};\n#line 3 \"test/AOJ/NTL/Prime-Factorize-1.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n;\n\
    \    cin >> n;\n    cout << n << \":\";\n    multi_prime_factorize mpf(n);\n \
    \   auto v = mpf.prime_factorize(n);\n    for (int i = 0; i < v.size(); i++) {\
    \ cout << \" \" << v[i]; }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja\"\
    \n#include\"../../../mathematics/multi-prime-factorize.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    cout << n\
    \ << \":\";\n    multi_prime_factorize mpf(n);\n    auto v = mpf.prime_factorize(n);\n\
    \    for (int i = 0; i < v.size(); i++) { cout << \" \" << v[i]; }\n    cout <<\
    \ endl;\n}\n"
  dependsOn:
  - mathematics/multi-prime-factorize.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/Prime-Factorize-1.test.cpp
  requiredBy: []
  timestamp: '2020-10-01 15:34:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/Prime-Factorize-1.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/Prime-Factorize-1.test.cpp
- /verify/test/AOJ/NTL/Prime-Factorize-1.test.cpp.html
title: test/AOJ/NTL/Prime-Factorize-1.test.cpp
---
