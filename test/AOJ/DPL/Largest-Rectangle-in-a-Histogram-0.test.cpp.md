---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/histogram-largest-rectangle.hpp
    title: utility/histogram-largest-rectangle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp
  bundledCode: "#line 1 \"test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp\"\
    \n#line 1 \"utility/histogram-largest-rectangle.hpp\"\n#include <vector>\n#include\
    \ <stack>\n\ntemplate<typename T> T histogram_largest_rectangle(const std::vector<T>\
    \ &h) {\n    int n = h.size();\n    std::vector<int> left(n);\n    {\n       \
    \ std::stack<int> stk;\n        for (int i = 0; i < n; i++) {\n            while\
    \ (!stk.empty() && h[stk.top()] >= h[i]) { stk.pop(); }\n            left[i] =\
    \ stk.empty() ? 0 : (stk.top() + 1);\n            stk.emplace(i);\n        }\n\
    \    }\n    std::vector<int> right(n);\n    {\n        std::stack<int> stk;\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            while (!stk.empty() &&\
    \ h[stk.top()] >= h[i]) { stk.pop(); }\n            right[i] = stk.empty() ? n\
    \ : stk.top();\n            stk.emplace(i);\n        }\n    }\n    T ret = 0;\n\
    \    for (int i = 0; i < n; i++) { ret = std::max(ret, h[i] * (right[i] - left[i]));\
    \ }\n    return ret;\n}\n#line 3 \"test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N;\n\
    \    cin >> N;\n    vector<long long> h(N);\n    for (int i = 0; i < N; i++) {\
    \ cin >> h[i]; }\n    cout << histogram_largest_rectangle(h) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp\"\
    \n#include \"../../../utility/histogram-largest-rectangle.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int N;\n    cin >> N;\n    vector<long\
    \ long> h(N);\n    for (int i = 0; i < N; i++) { cin >> h[i]; }\n    cout << histogram_largest_rectangle(h)\
    \ << endl;\n}"
  dependsOn:
  - utility/histogram-largest-rectangle.hpp
  isVerificationFile: true
  path: test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
- /verify/test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp.html
title: test/AOJ/DPL/Largest-Rectangle-in-a-Histogram-0.test.cpp
---
