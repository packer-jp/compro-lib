---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/mod-calc.hpp
    title: "mod \u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/mathematics/mod-calc.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/mod-calc.hpp\"\n#include <map>\n\nint safe_mod(long long\
    \ a, int m) {\n    a %= m;\n    if (a < 0) { a += m; }\n    return a;\n};\n\n\
    int mod_inv(long long a, int m) {\n    long long b = m, x = 1, u = 0;\n    while\
    \ (b) {\n        int t = a / b;\n        std::swap(a -= t * b, b);\n        std::swap(x\
    \ -= t * u, u);\n    }\n    return safe_mod(x, m);\n};\n\nint mod_pow(long long\
    \ a, long long n, int m) {\n    if (n < 0) { return mod_inv(mod_pow(a, -n, m),\
    \ m); }\n    long long ret = 1, mul = a;\n    while (n) {\n        if (n & 1)\
    \ { (ret *= mul) %= m; }\n        (mul *= mul) %= m, n >>= 1;\n    }\n    return\
    \ ret;\n}\n\nint mod_log(long long a, long long b, int m) {\n    a %= m, b %=\
    \ m;\n    std::map<int, int> mp;\n    int rt;\n    long long ap = a;\n    for\
    \ (rt = 1; rt * rt < m; rt++) {\n        if (!mp.count(ap)) { mp[ap] = rt; }\n\
    \        (ap *= a) %= m;\n    }\n    ap = mod_inv(ap, m);\n    if (mp.count(b))\
    \ { return mp[b]; }\n    mp[1] = 0;\n    for (int i = 1; i < rt; i++) {\n    \
    \    (b *= ap) %= m;\n        if (mp.count(b)) { return i * rt + mp[b]; }\n  \
    \  }\n    return -1;\n}\n#line 3 \"test/unit-test/mathematics/mod-calc.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    cout <<\
    \ \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/mod-calc.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - mathematics/mod-calc.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/mod-calc.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 22:18:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/mathematics/mod-calc.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/mod-calc.test.cpp
- /verify/test/unit-test/mathematics/mod-calc.test.cpp.html
title: test/unit-test/mathematics/mod-calc.test.cpp
---
