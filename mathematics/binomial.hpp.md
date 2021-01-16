---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/binomial.hpp\"\ntemplate<typename T>\nT binomial(long\
    \ long n, int r) {\n    if (r < 0 || n < r)return 0;\n    T ret = 1;\n    for\
    \ (int i = 1; i <= r; i++) { ret *= (N - i + 1) / i; }\n    return ret;\n}\n"
  code: "template<typename T>\nT binomial(long long n, int r) {\n    if (r < 0 ||\
    \ n < r)return 0;\n    T ret = 1;\n    for (int i = 1; i <= r; i++) { ret *= (N\
    \ - i + 1) / i; }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/binomial.hpp
  requiredBy: []
  timestamp: '2021-01-16 20:32:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mathematics/binomial.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570"
---
