---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/xor-eliminate.test.cpp
    title: test/unit-test/mathematics/xor-eliminate.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"utility/bit-reverse.hpp\"\n#include <bitset>\n\ntemplate<typename\
    \ T> T bit_reverse(T x) {\n    for (int i = 0; i < x.size() / 2; i++) {\n    \
    \    bool tmp = x[x.size() - i - 1];\n        x[x.size() - i - 1] = x[i], x[i]\
    \ = tmp;\n    }\n    return x;\n}\n"
  code: "#include <bitset>\n\ntemplate<typename T> T bit_reverse(T x) {\n    for (int\
    \ i = 0; i < x.size() / 2; i++) {\n        bool tmp = x[x.size() - i - 1];\n \
    \       x[x.size() - i - 1] = x[i], x[i] = tmp;\n    }\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/bit-reverse.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/xor-eliminate.test.cpp
documentation_of: utility/bit-reverse.hpp
layout: document
redirect_from:
- /library/utility/bit-reverse.hpp
- /library/utility/bit-reverse.hpp.html
title: utility/bit-reverse.hpp
---