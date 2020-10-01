---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/bell-number-table.hpp\"\n#include <vector>\n\
    \ntemplate<typename T> std::vector<std::vector<T>> bell_number_table(int n, int\
    \ k) {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0] = 1;\n\
    \    for (int i = 1; i <= n; i++) {\n        ret[i][1] = 1;\n        for (int\
    \ j = 2; j <= k; j++) { ret[i][j] = ret[i][j - 1] + ret[i - 1][j - 1] + j * ret[i\
    \ - 1][j]; }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> bell_number_table(int\
    \ n, int k) {\n    std::vector ret(n + 1, std::vector<T>(k + 1));\n    ret[0][0]\
    \ = 1;\n    for (int i = 1; i <= n; i++) {\n        ret[i][1] = 1;\n        for\
    \ (int j = 2; j <= k; j++) { ret[i][j] = ret[i][j - 1] + ret[i - 1][j - 1] + j\
    \ * ret[i - 1][j]; }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/bell-number-table.hpp
  requiredBy: []
  timestamp: '2020-10-01 10:08:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DPL/Balls-and-Boxes-7-0.test.cpp
documentation_of: mathematics/bell-number-table.hpp
layout: document
redirect_from:
- /library/mathematics/bell-number-table.hpp
- /library/mathematics/bell-number-table.hpp.html
title: mathematics/bell-number-table.hpp
---
