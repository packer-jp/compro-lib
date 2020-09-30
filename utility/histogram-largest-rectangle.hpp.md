---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
    title: test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utility/histogram-largest-rectangle.hpp\"\n#include <vector>\n\
    #include <stack>\n\ntemplate<typename T> T histogram_largest_rectangle(const std::vector<T>\
    \ &h) {\n    int n = h.size();\n    std::vector<int> left(n);\n    {\n       \
    \ std::stack<int> stk;\n        for (int i = 0; i < n; i++) {\n            while\
    \ (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }\n            left[i] =\
    \ stk.empty() ? 0 : (stk.top() + 1);\n            stk.emplace(i);\n        }\n\
    \    }\n    std::vector<int> right(n);\n    {\n        std::stack<int> stk;\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            while (!stk.empty() &&\
    \ h[stk.top()] >= h[i]) { stk.pop(); }\n            right[i] = stk.empty() ? n\
    \ : stk.top();\n            stk.emplace(i);\n        }\n    }\n    T ret = 0;\n\
    \    for (int i = 0; i < n; i++) { ret = std::max(ret, h[i] * (right[i] - left[i]));\
    \ }\n    return ret;\n}\n"
  code: "#include <vector>\n#include <stack>\n\ntemplate<typename T> T histogram_largest_rectangle(const\
    \ std::vector<T> &h) {\n    int n = h.size();\n    std::vector<int> left(n);\n\
    \    {\n        std::stack<int> stk;\n        for (int i = 0; i < n; i++) {\n\
    \            while (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }\n   \
    \         left[i] = stk.empty() ? 0 : (stk.top() + 1);\n            stk.emplace(i);\n\
    \        }\n    }\n    std::vector<int> right(n);\n    {\n        std::stack<int>\
    \ stk;\n        for (int i = n - 1; i >= 0; i--) {\n            while (!stk.empty()\
    \ && h[stk.top()] >= h[i]) { stk.pop(); }\n            right[i] = stk.empty()\
    \ ? n : stk.top();\n            stk.emplace(i);\n        }\n    }\n    T ret =\
    \ 0;\n    for (int i = 0; i < n; i++) { ret = std::max(ret, h[i] * (right[i] -\
    \ left[i])); }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/histogram-largest-rectangle.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
documentation_of: utility/histogram-largest-rectangle.hpp
layout: document
title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u6700\u5927\u9577\u65B9\u5F62"
---

