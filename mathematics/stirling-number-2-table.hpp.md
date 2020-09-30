---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
    title: test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/stirling-number-2-table.hpp\"\n#include <vector>\n\
    \ntemplate<typename T> std::vector<std::vector<T>> stirling_number_2_table(int\
    \ n) {\n    std::vector ret(n + 1, std::vector<T>(n + 1));\n    ret[0][0] = 1;\n\
    \    for (int i = 1; i <= n; i++) {\n        ret[i][1] = ret[i][i] = 1;\n    \
    \    for (int j = 2; j < i; j++) { ret[i][j] = ret[i - 1][j - 1] + j * ret[i -\
    \ 1][j]; }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> stirling_number_2_table(int\
    \ n) {\n    std::vector ret(n + 1, std::vector<T>(n + 1));\n    ret[0][0] = 1;\n\
    \    for (int i = 1; i <= n; i++) {\n        ret[i][1] = ret[i][i] = 1;\n    \
    \    for (int j = 2; j < i; j++) { ret[i][j] = ret[i - 1][j - 1] + j * ret[i -\
    \ 1][j]; }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/stirling-number-2-table.hpp
  requiredBy: []
  timestamp: '2020-09-30 20:48:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL/Balls-and-Boxes-9-0.test.cpp
documentation_of: mathematics/stirling-number-2-table.hpp
layout: document
redirect_from:
- /library/mathematics/stirling-number-2-table.hpp
- /library/mathematics/stirling-number-2-table.hpp.html
title: mathematics/stirling-number-2-table.hpp
---
