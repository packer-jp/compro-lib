---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/utility/xor64.md
    document_title: Xorshift
    links: []
  bundledCode: "#line 1 \"utility/xor64.hpp\"\n/*\n * @title Xorshift\n * @docs docs/utility/xor64.md\n\
    \ */\n\nlong long xor64(long long range) {\n    static unsigned long long x =\
    \ 1145141919810ULL;\n    x ^= x << 13;\n    x ^= x >> 7;\n    return (x ^= x <<\
    \ 17) % range;\n}\n"
  code: "/*\n * @title Xorshift\n * @docs docs/utility/xor64.md\n */\n\nlong long\
    \ xor64(long long range) {\n    static unsigned long long x = 1145141919810ULL;\n\
    \    x ^= x << 13;\n    x ^= x >> 7;\n    return (x ^= x << 17) % range;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/xor64.hpp
  requiredBy: []
  timestamp: '2020-08-14 03:11:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/xor64.hpp
layout: document
title: Xorshift
---

