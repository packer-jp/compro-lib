---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/partition-table.hpp\"\n#include <vector>\n\n\
    template<typename T> std::vector<std::vector<T>> partition_table(int n, int k)\
    \ {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0] = 1;\n\
    \    for (int i = 0; i <= n; i++) {\n        for (int j = 1; j <= k; j++) {\n\
    \            ret[i][j] = ret[i][j - 1];\n            if (j <= i) { ret[i][j] +=\
    \ ret[i - j][j]; }\n        }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> partition_table(int\
    \ n, int k) {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0]\
    \ = 1;\n    for (int i = 0; i <= n; i++) {\n        for (int j = 1; j <= k; j++)\
    \ {\n            ret[i][j] = ret[i][j - 1];\n            if (j <= i) { ret[i][j]\
    \ += ret[i - j][j]; }\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/partition-table.hpp
  requiredBy: []
  timestamp: '2020-10-01 09:23:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL/Balls-and-Boxes-10-0.test.cpp
documentation_of: mathematics/partition-table.hpp
layout: document
title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
---

- `<T> std::vector<std::vector<T>> partiton_table(int n, int k)`  
  `T`は整数型もしくは`mod_int`。サイズ`n * k`の分割数テーブルを時間計算量`O(nk)`で作る。
  ここで、分割数`P(n, k)`は、`n`個の区別できないボールを`k`個の区別できない箱に入れる場合の数である。