---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/Prime-Factorize-0.test.cpp
    title: test/AOJ/NTL/Prime-Factorize-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/moebius.test.cpp
    title: test/unit-test/mathematics/moebius.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/prime-factorize.hpp\"\n#include <vector>\n\n\
    template<typename T> std::vector<T> prime_factorize(T n) {\n    std::vector<T>\
    \ ret;\n    for (T i = 2; i * i <= n; i++) {\n        while (n % i == 0) {\n \
    \           ret.emplace_back(i);\n            n /= i;\n        }\n    }\n    if\
    \ (n != 1) { ret.emplace_back(n); }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<T> prime_factorize(T\
    \ n) {\n    std::vector<T> ret;\n    for (T i = 2; i * i <= n; i++) {\n      \
    \  while (n % i == 0) {\n            ret.emplace_back(i);\n            n /= i;\n\
    \        }\n    }\n    if (n != 1) { ret.emplace_back(n); }\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/prime-factorize.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/moebius.test.cpp
  - test/AOJ/NTL/Prime-Factorize-0.test.cpp
documentation_of: mathematics/prime-factorize.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---

- `<T> std::vector<T> prime_factorize(T n)`  
`n`を素因数分解した結果を返す。時間計算量`O(sqrt n)`。