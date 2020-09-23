---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/Prime-Factorize-1.test.cpp
    title: test/AOJ/NTL/Prime-Factorize-1.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/multi-prime-factorize.hpp\"\n#include <vector>\n\
    \nstd::vector<int> smallest_prime_factors(int n) {\n    std::vector<int> ret(n\
    \ + 1);\n    for (int i = 0; i <= n; i++) { ret[i] = i; }\n    for (int i = 2;\
    \ i * i <= n; i++) {\n        if (ret[i] < i) { continue; }\n        for (int\
    \ j = i * i; j <= n; j += i) {\n            if (ret[j] == j) { ret[j] = i; }\n\
    \        }\n    }\n    return ret;\n}\n\nstd::vector<int> prime_factorize(int\
    \ n, const std::vector<int> &spf) {\n    std::vector<int> ret;\n    while (n >\
    \ 1) {\n        ret.emplace_back(spf[n]);\n        n /= spf[n];\n    }\n    return\
    \ ret;\n}\n"
  code: "#include <vector>\n\nstd::vector<int> smallest_prime_factors(int n) {\n \
    \   std::vector<int> ret(n + 1);\n    for (int i = 0; i <= n; i++) { ret[i] =\
    \ i; }\n    for (int i = 2; i * i <= n; i++) {\n        if (ret[i] < i) { continue;\
    \ }\n        for (int j = i * i; j <= n; j += i) {\n            if (ret[j] ==\
    \ j) { ret[j] = i; }\n        }\n    }\n    return ret;\n}\n\nstd::vector<int>\
    \ prime_factorize(int n, const std::vector<int> &spf) {\n    std::vector<int>\
    \ ret;\n    while (n > 1) {\n        ret.emplace_back(spf[n]);\n        n /= spf[n];\n\
    \    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/multi-prime-factorize.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/Prime-Factorize-1.test.cpp
documentation_of: mathematics/multi-prime-factorize.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3 (\u8907\u6570\u30AF\u30A8\u30EA)"
---

