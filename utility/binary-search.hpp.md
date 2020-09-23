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
    _deprecated_at_docs: docs/utility/binary-search.md
    document_title: "\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 1 \"utility/binary-search.hpp\"\n#include <cstdlib>\n\n/*\n\
    \ * @title \u4E8C\u5206\u63A2\u7D22\n * @docs docs/utility/binary-search.md\n\
    \ */\n\ntemplate<typename F> long long discrete_binary_search(long long ok, long\
    \ long ng, F is_ok) {\n    while (abs(ok - ng) > 1) {\n        long long mid =\
    \ (ok + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\n\ntemplate<typename F> double continuous_binary_search(double ok, double ng,\
    \ F is_ok, int n) {\n    for (int i = 0; i < n; i++) {\n        double mid = (ok\
    \ + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n"
  code: "#include <cstdlib>\n\n/*\n * @title \u4E8C\u5206\u63A2\u7D22\n * @docs docs/utility/binary-search.md\n\
    \ */\n\ntemplate<typename F> long long discrete_binary_search(long long ok, long\
    \ long ng, F is_ok) {\n    while (abs(ok - ng) > 1) {\n        long long mid =\
    \ (ok + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n\
    }\n\ntemplate<typename F> double continuous_binary_search(double ok, double ng,\
    \ F is_ok, int n) {\n    for (int i = 0; i < n; i++) {\n        double mid = (ok\
    \ + ng) / 2;\n        (is_ok(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/binary-search.hpp
  requiredBy: []
  timestamp: '2020-05-12 23:01:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1/Binary-Search-0.test.cpp
documentation_of: utility/binary-search.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22"
---

