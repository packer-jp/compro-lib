---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unit-test/string/run-length-encoding.test.cpp
    title: test/unit-test/string/run-length-encoding.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/moebius.test.cpp
    title: test/unit-test/mathematics/moebius.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/run-length-encoding.hpp\"\n#include <vector>\n\n\
    template<typename T> std::vector<std::pair<T, int>> run_length_encoding(const\
    \ std::vector<T> src) {\n    std::vector<std::pair<T, int>> ret;\n    if (src.size()\
    \ > 0) { ret.push_back({src[0], 1}); }\n    for (int i = 1; i < src.size(); i++)\
    \ {\n        if (src[i] == ret.back().first) { ret.back().second++; }\n      \
    \  else { ret.push_back({src[i], 1}); }\n    }\n    return ret;\n}\n"
  code: "#include <vector>\n\ntemplate<typename T> std::vector<std::pair<T, int>>\
    \ run_length_encoding(const std::vector<T> src) {\n    std::vector<std::pair<T,\
    \ int>> ret;\n    if (src.size() > 0) { ret.push_back({src[0], 1}); }\n    for\
    \ (int i = 1; i < src.size(); i++) {\n        if (src[i] == ret.back().first)\
    \ { ret.back().second++; }\n        else { ret.push_back({src[i], 1}); }\n   \
    \ }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/run-length-encoding.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unit-test/string/run-length-encoding.test.cpp
  - test/unit-test/mathematics/moebius.test.cpp
documentation_of: string/run-length-encoding.hpp
layout: document
title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---

