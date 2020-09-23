---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/unit-test/mathematics/xor-eliminate.test.cpp
    title: test/unit-test/mathematics/xor-eliminate.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/utility/bit-reverse.md
    document_title: "\u30D3\u30C3\u30C8\u30EA\u30D0\u30FC\u30B9"
    links: []
  bundledCode: "#line 1 \"utility/bit-reverse.hpp\"\n#include <bitset>\n\n/*\n * @title\
    \ \u30D3\u30C3\u30C8\u30EA\u30D0\u30FC\u30B9\n * @docs docs/utility/bit-reverse.md\n\
    \ */\n\ntemplate<typename T> T bit_reverse(T x) {\n    for (int i = 0; i < x.size()\
    \ / 2; i++) {\n        bool tmp = x[x.size() - i - 1];\n        x[x.size() - i\
    \ - 1] = x[i], x[i] = tmp;\n    }\n    return x;\n}\n"
  code: "#include <bitset>\n\n/*\n * @title \u30D3\u30C3\u30C8\u30EA\u30D0\u30FC\u30B9\
    \n * @docs docs/utility/bit-reverse.md\n */\n\ntemplate<typename T> T bit_reverse(T\
    \ x) {\n    for (int i = 0; i < x.size() / 2; i++) {\n        bool tmp = x[x.size()\
    \ - i - 1];\n        x[x.size() - i - 1] = x[i], x[i] = tmp;\n    }\n    return\
    \ x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/bit-reverse.hpp
  requiredBy: []
  timestamp: '2020-09-01 03:22:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/unit-test/mathematics/xor-eliminate.test.cpp
documentation_of: utility/bit-reverse.hpp
layout: document
title: "\u30D3\u30C3\u30C8\u30EA\u30D0\u30FC\u30B9"
---

