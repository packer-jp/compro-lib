---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
    title: test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"mathematics/get-prime-table.hpp\"\n#include <vector>\n\n\
    std::vector<bool> get_prime_table(int n) {\n    std::vector<bool> ret(n + 1, true);\n\
    \    if (n >= 0) { ret[0] = false; }\n    if (n >= 1) { ret[1] = false; }\n  \
    \  for (int i = 2; i * i <= n; i++) {\n        if (!ret[i]) { continue; }\n  \
    \      for (int j = i << 1; j <= n; j += i) {\n            ret[j] = false;\n \
    \       }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\nstd::vector<bool> get_prime_table(int n) {\n    std::vector<bool>\
    \ ret(n + 1, true);\n    if (n >= 0) { ret[0] = false; }\n    if (n >= 1) { ret[1]\
    \ = false; }\n    for (int i = 2; i * i <= n; i++) {\n        if (!ret[i]) { continue;\
    \ }\n        for (int j = i << 1; j <= n; j += i) {\n            ret[j] = false;\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/get-prime-table.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1/Prime-Numbers-0.test.cpp
documentation_of: mathematics/get-prime-table.hpp
layout: document
redirect_from:
- /library/mathematics/get-prime-table.hpp
- /library/mathematics/get-prime-table.hpp.html
title: mathematics/get-prime-table.hpp
---
