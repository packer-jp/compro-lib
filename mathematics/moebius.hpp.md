---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/moebius.test.cpp
    title: test/unit-test/mathematics/moebius.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/moebius.hpp\"\n#include <map>\n#include <vector>\n\
    \ntemplate<typename T> std::map<T, int> moebius(T n) {\n    std::map<T, int> ret;\n\
    \    std::vector<T> primes;\n    for (T i = 2; i * i <= n; i++) {\n        if\
    \ (n % i == 0) {\n            primes.push_back(i);\n            while (n % i ==\
    \ 0) { n /= i; }\n        }\n    }\n    if (n != 1) { primes.push_back(n); }\n\
    \    int m = primes.size();\n    for (int i = 0; i < (1 << m); i++) {\n      \
    \  int mul = 1;\n        T d = 1;\n        for (int j = 0; j < m; j++) {\n   \
    \         if (i >> j & 1) { mul *= -1, d *= primes[j]; }\n        }\n        ret[d]\
    \ = mul;\n    }\n    return ret;\n}\n"
  code: "#include <map>\n#include <vector>\n\ntemplate<typename T> std::map<T, int>\
    \ moebius(T n) {\n    std::map<T, int> ret;\n    std::vector<T> primes;\n    for\
    \ (T i = 2; i * i <= n; i++) {\n        if (n % i == 0) {\n            primes.push_back(i);\n\
    \            while (n % i == 0) { n /= i; }\n        }\n    }\n    if (n != 1)\
    \ { primes.push_back(n); }\n    int m = primes.size();\n    for (int i = 0; i\
    \ < (1 << m); i++) {\n        int mul = 1;\n        T d = 1;\n        for (int\
    \ j = 0; j < m; j++) {\n            if (i >> j & 1) { mul *= -1, d *= primes[j];\
    \ }\n        }\n        ret[d] = mul;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/moebius.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/moebius.test.cpp
documentation_of: mathematics/moebius.hpp
layout: document
title: "Moebius \u95A2\u6570"
---

