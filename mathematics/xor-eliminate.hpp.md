---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/xor-eliminate.test.cpp
    title: test/unit-test/mathematics/xor-eliminate.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/xor-eliminate.hpp\"\n#include <vector>\n#include\
    \ <bitset>\n\ntemplate<typename T> std::vector<T> xor_eliminate(std::vector<T>\
    \ src) {\n    std::vector<T> ret;\n    for (int i = 0; i < src.size(); i++) {\n\
    \        for (int j = src.size() - 1; j > i; j--) {\n            int x = src[j]._Find_first(),\
    \ y = src[j - 1]._Find_first();\n            if (x < y) { src[j - 1] ^= src[j];\
    \ }\n            if (x <= y) { src[j] ^= src[j - 1]; }\n        }\n        if\
    \ (src[i].none()) { break; }\n        ret.emplace_back(src[i]);\n    }\n    for\
    \ (int i = ret.size() - 1; i > 0; i--) {\n        for (int j = 0; j < i; j++)\
    \ {\n            if (ret[j][ret[i]._Find_first()]) { ret[j] ^= ret[i]; }\n   \
    \     }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <bitset>\n\ntemplate<typename T> std::vector<T>\
    \ xor_eliminate(std::vector<T> src) {\n    std::vector<T> ret;\n    for (int i\
    \ = 0; i < src.size(); i++) {\n        for (int j = src.size() - 1; j > i; j--)\
    \ {\n            int x = src[j]._Find_first(), y = src[j - 1]._Find_first();\n\
    \            if (x < y) { src[j - 1] ^= src[j]; }\n            if (x <= y) { src[j]\
    \ ^= src[j - 1]; }\n        }\n        if (src[i].none()) { break; }\n       \
    \ ret.emplace_back(src[i]);\n    }\n    for (int i = ret.size() - 1; i > 0; i--)\
    \ {\n        for (int j = 0; j < i; j++) {\n            if (ret[j][ret[i]._Find_first()])\
    \ { ret[j] ^= ret[i]; }\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/xor-eliminate.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/mathematics/xor-eliminate.test.cpp
documentation_of: mathematics/xor-eliminate.hpp
layout: document
title: "xor \u6383\u304D\u51FA\u3057"
---

