---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1/Binary-Search-0.test.cpp
    title: test/AOJ/ALDS1/Binary-Search-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"utility/binary-search.hpp\"\n#include <cstdlib>\n\ntemplate<typename\
    \ F> long long discrete_binary_search(long long ok, long long ng, F is_ok) {\n\
    \    while (abs(ok - ng) > 1) {\n        long long mid = (ok + ng) / 2;\n    \
    \    (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n\ntemplate<typename\
    \ F> double continuous_binary_search(double ok, double ng, F is_ok, int n) {\n\
    \    for (int i = 0; i < n; i++) {\n        double mid = (ok + ng) / 2;\n    \
    \    (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n"
  code: "#include <cstdlib>\n\ntemplate<typename F> long long discrete_binary_search(long\
    \ long ok, long long ng, F is_ok) {\n    while (abs(ok - ng) > 1) {\n        long\
    \ long mid = (ok + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n  \
    \  return ok;\n}\n\ntemplate<typename F> double continuous_binary_search(double\
    \ ok, double ng, F is_ok, int n) {\n    for (int i = 0; i < n; i++) {\n      \
    \  double mid = (ok + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n\
    \    return ok;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/binary-search.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1/Binary-Search-0.test.cpp
documentation_of: utility/binary-search.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22"
---

