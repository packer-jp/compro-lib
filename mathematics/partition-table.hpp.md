---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DPL/Balls-and-Boxes-5-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-5-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DPL/Balls-and-Boxes-5-0.test.cpp
documentation_of: mathematics/partition-table.hpp
layout: document
redirect_from:
- /library/mathematics/partition-table.hpp
- /library/mathematics/partition-table.hpp.html
title: mathematics/partition-table.hpp
---
