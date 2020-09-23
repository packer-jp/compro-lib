---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
    title: test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/get-divisors.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate<typename T> std::vector<T> get_divisors(T n) {\n    std::vector<T>\
    \ ret;\n    T i;\n    for (i = 1; i * i < n; i++) {\n        if (n % i == 0) {\n\
    \            ret.emplace_back(i);\n            ret.emplace_back(n / i);\n    \
    \    }\n    }\n    if (i * i == n) { ret.emplace_back(i); }\n    std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\ntemplate<typename T> std::vector<T>\
    \ get_divisors(T n) {\n    std::vector<T> ret;\n    T i;\n    for (i = 1; i *\
    \ i < n; i++) {\n        if (n % i == 0) {\n            ret.emplace_back(i);\n\
    \            ret.emplace_back(n / i);\n        }\n    }\n    if (i * i == n) {\
    \ ret.emplace_back(i); }\n    std::sort(ret.begin(), ret.end());\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/get-divisors.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ITP1/How-Many-Divisors-0.test.cpp
documentation_of: mathematics/get-divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---

