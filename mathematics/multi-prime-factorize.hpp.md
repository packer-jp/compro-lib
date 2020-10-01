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
    links: []
  bundledCode: "#line 1 \"mathematics/multi-prime-factorize.hpp\"\n#include <vector>\n\
    #include <numeric>\n\nstruct multi_prime_factorize {\n    std::vector<int> spf;\n\
    \    multi_prime_factorize(int n) : spf(n + 1) {\n        std::iota(spf.begin(),\
    \ spf.end(), 0LL);\n        for (int i = 2; i * i <= n; i++) {\n            if\
    \ (spf[i] < i) { continue; }\n            for (int j = i * i; j <= n; j += i)\
    \ {\n                if (spf[j] == j) { spf[j] = i; }\n            }\n       \
    \ }\n    }\n    std::vector<int> prime_factorize(int a) {\n        std::vector<int>\
    \ ret;\n        while (a > 1) {\n            ret.emplace_back(spf[a]);\n     \
    \       a /= spf[a];\n        }\n        return ret;\n    }\n};\n"
  code: "#include <vector>\n#include <numeric>\n\nstruct multi_prime_factorize {\n\
    \    std::vector<int> spf;\n    multi_prime_factorize(int n) : spf(n + 1) {\n\
    \        std::iota(spf.begin(), spf.end(), 0LL);\n        for (int i = 2; i *\
    \ i <= n; i++) {\n            if (spf[i] < i) { continue; }\n            for (int\
    \ j = i * i; j <= n; j += i) {\n                if (spf[j] == j) { spf[j] = i;\
    \ }\n            }\n        }\n    }\n    std::vector<int> prime_factorize(int\
    \ a) {\n        std::vector<int> ret;\n        while (a > 1) {\n            ret.emplace_back(spf[a]);\n\
    \            a /= spf[a];\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/multi-prime-factorize.hpp
  requiredBy: []
  timestamp: '2020-10-01 15:53:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/Prime-Factorize-1.test.cpp
documentation_of: mathematics/multi-prime-factorize.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3 (\u8907\u6570\u30AF\u30A8\u30EA)"
---

- `struct multi_prime_factorize`  
  複数の素因数分解クエリを処理する。

  - `(constructor)(int n)`
  最大で`n`まで素因数分解できるように初期化。時間計算量`O(n log n)`。

  - `std::vector<int> prime_factorize(int a)`
  `a`を素因数分解した結果を返す。時間計算量`O(log a)`。
