---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mathematics/bell-number-table.hpp
    title: mathematics/bell-number-table.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/stirling-number-2-table.hpp\"\n#include <vector>\n\
    \ntemplate<typename T> std::vector<std::vector<T>> stirling_number_2_table(int\
    \ n, int k) {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0]\
    \ = 1;\n    if (k == 0) { return ret; }\n    for (int i = 1; i <= n; i++) {\n\
    \        ret[i][1] = 1;\n        for (int j = 2; j <= i && j <= k; j++) { ret[i][j]\
    \ = ret[i - 1][j - 1] + j * ret[i - 1][j]; }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> stirling_number_2_table(int\
    \ n, int k) {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0]\
    \ = 1;\n    if (k == 0) { return ret; }\n    for (int i = 1; i <= n; i++) {\n\
    \        ret[i][1] = 1;\n        for (int j = 2; j <= i && j <= k; j++) { ret[i][j]\
    \ = ret[i - 1][j - 1] + j * ret[i - 1][j]; }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/stirling-number-2-table.hpp
  requiredBy:
  - mathematics/bell-number-table.hpp
  timestamp: '2020-10-01 10:19:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
  - test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
documentation_of: mathematics/stirling-number-2-table.hpp
layout: document
title: "\u7B2C 2 \u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u30C6\u30FC\u30D6\
  \u30EB"
---

- `<T> std::vector<std::vector<T>> stirling_number_2_table(int n, int k)`  
  `T`は整数型もしくは`mod_int`。サイズ`n * k`の第 2 種スターリング数テーブルを時間計算量`O(nk)`で作る。
  ここで、第 2 種スターリング数`S(n, k)`は、`n`個の区別できるボールを`k`個の区別できない箱に入れる場合の数である。ただし、各箱には`1`つ以上のボールを入れなければならない。