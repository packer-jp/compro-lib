---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/binomial-table.hpp\"\n#include <vector>\n\n\
    template<typename T> std::vector<std::vector<T>> binomial_table(int n) {\n   \
    \ std::vector ret(n + 1, std::vector<T>(n + 1));\n    for (int i = 0; i <= N;\
    \ i++)ret[i][0] = ret[i][1] = 1;\n    for (int i = 0; i <= N; i++) {\n       \
    \ for (int j = 1; j < i; j++) {\n            ret[i][j] = ret[i - 1][j - 1] + ret[i\
    \ - 1][j];\n        }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::vector<T>> binomial_table(int\
    \ n) {\n    std::vector ret(n + 1, std::vector<T>(n + 1));\n    for (int i = 0;\
    \ i <= N; i++)ret[i][0] = ret[i][1] = 1;\n    for (int i = 0; i <= N; i++) {\n\
    \        for (int j = 1; j < i; j++) {\n            ret[i][j] = ret[i - 1][j -\
    \ 1] + ret[i - 1][j];\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/binomial-table.hpp
  requiredBy: []
  timestamp: '2021-01-16 20:30:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mathematics/binomial-table.hpp
layout: document
redirect_from:
- /library/mathematics/binomial-table.hpp
- /library/mathematics/binomial-table.hpp.html
title: mathematics/binomial-table.hpp
---
