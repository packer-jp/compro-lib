---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/xor-eliminate.hpp
    title: "xor \u6383\u304D\u51FA\u3057"
  - icon: ':heavy_check_mark:'
    path: utility/bit-reverse.hpp
    title: "\u30D3\u30C3\u30C8\u30EA\u30D0\u30FC\u30B9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/mathematics/xor-eliminate.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/xor-eliminate.hpp\"\n#include <vector>\n#include <bitset>\n\
    \ntemplate<typename T> std::vector<T> xor_eliminate(std::vector<T> src) {\n  \
    \  std::vector<T> ret;\n    for (int i = 0; i < src.size(); i++) {\n        for\
    \ (int j = src.size() - 1; j > i; j--) {\n            int x = src[j]._Find_first(),\
    \ y = src[j - 1]._Find_first();\n            if (x < y) { src[j - 1] ^= src[j];\
    \ }\n            if (x <= y) { src[j] ^= src[j - 1]; }\n        }\n        if\
    \ (src[i].none()) { break; }\n        ret.emplace_back(src[i]);\n    }\n    for\
    \ (int i = ret.size() - 1; i > 0; i--) {\n        for (int j = 0; j < i; j++)\
    \ {\n            if (ret[j][ret[i]._Find_first()]) { ret[j] ^= ret[i]; }\n   \
    \     }\n    }\n    return ret;\n}\n#line 2 \"utility/bit-reverse.hpp\"\n\ntemplate<typename\
    \ T> T bit_reverse(T x) {\n    for (int i = 0; i < x.size() / 2; i++) {\n    \
    \    bool tmp = x[x.size() - i - 1];\n        x[x.size() - i - 1] = x[i], x[i]\
    \ = tmp;\n    }\n    return x;\n}\n#line 4 \"test/unit-test/mathematics/xor-eliminate.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    bitset<5>\
    \ a0(\"11000\"), a1(\"10110\"), a2(\"11111\"), a3(\"00111\"), a4(\"01110\");\n\
    \    vector<bitset<5>> a = {a0, a1, a2, a3, a4};\n    for (auto &x:a) { x = bit_reverse(x);\
    \ }\n    vector<bitset<5>> b = xor_eliminate(a);\n    for (auto &x:b) { x = bit_reverse(x);\
    \ }\n    for (auto x:b) { cerr << x << endl; }\n    cout << \"Hello World\" <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include \"../../../mathematics/xor-eliminate.hpp\"\n#include \"../../../utility/bit-reverse.hpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    bitset<5>\
    \ a0(\"11000\"), a1(\"10110\"), a2(\"11111\"), a3(\"00111\"), a4(\"01110\");\n\
    \    vector<bitset<5>> a = {a0, a1, a2, a3, a4};\n    for (auto &x:a) { x = bit_reverse(x);\
    \ }\n    vector<bitset<5>> b = xor_eliminate(a);\n    for (auto &x:b) { x = bit_reverse(x);\
    \ }\n    for (auto x:b) { cerr << x << endl; }\n    cout << \"Hello World\" <<\
    \ endl;\n}"
  dependsOn:
  - mathematics/xor-eliminate.hpp
  - utility/bit-reverse.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/xor-eliminate.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/mathematics/xor-eliminate.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/xor-eliminate.test.cpp
- /verify/test/unit-test/mathematics/xor-eliminate.test.cpp.html
title: test/unit-test/mathematics/xor-eliminate.test.cpp
---
