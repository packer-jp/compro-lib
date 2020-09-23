---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/run-length-encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/string/run-length-encoding.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"string/run-length-encoding.hpp\"\n#include <vector>\n\ntemplate<typename\
    \ T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T> src)\
    \ {\n    std::vector<std::pair<T, int>> ret;\n    if (src.size() > 0) { ret.push_back({src[0],\
    \ 1}); }\n    for (int i = 1; i < src.size(); i++) {\n        if (src[i] == ret.back().first)\
    \ { ret.back().second++; }\n        else { ret.push_back({src[i], 1}); }\n   \
    \ }\n    return ret;\n}\n#line 3 \"test/unit-test/string/run-length-encoding.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    vector<int>\
    \ a = {5, 5, 6, 3, 1, 1, 4, 5, 1, 4};\n    vector<pair<int, int>> b = {{5, 2},\
    \ {6, 1}, {3, 1}, {1, 2}, {4, 1}, {5, 1}, {1, 1}, {4, 1}};\n    assert(run_length_encoding(a)\
    \ == b);\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../string/run-length-encoding.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    vector<int> a = {5, 5, 6, 3, 1, 1, 4,\
    \ 5, 1, 4};\n    vector<pair<int, int>> b = {{5, 2}, {6, 1}, {3, 1}, {1, 2}, {4,\
    \ 1}, {5, 1}, {1, 1}, {4, 1}};\n    assert(run_length_encoding(a) == b);\n   \
    \ cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - string/run-length-encoding.hpp
  isVerificationFile: true
  path: test/unit-test/string/run-length-encoding.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit-test/string/run-length-encoding.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/string/run-length-encoding.test.cpp
- /verify/test/unit-test/string/run-length-encoding.test.cpp.html
title: test/unit-test/string/run-length-encoding.test.cpp
---
