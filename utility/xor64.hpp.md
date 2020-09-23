---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"utility/xor64.hpp\"\nlong long xor64(long long range) {\n\
    \    static unsigned long long x = 1145141919810ULL;\n    x ^= x << 13;\n    x\
    \ ^= x >> 7;\n    return (x ^= x << 17) % range;\n}\n"
  code: "long long xor64(long long range) {\n    static unsigned long long x = 1145141919810ULL;\n\
    \    x ^= x << 13;\n    x ^= x >> 7;\n    return (x ^= x << 17) % range;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/xor64.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/xor64.hpp
layout: document
title: Xorshift
---

