---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mathematics/convolute.hpp
    title: "\u7573\u307F\u8FBC\u307F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
    title: test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unit-test/mathematics/mod-calc.test.cpp
    title: test/unit-test/mathematics/mod-calc.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mathematics/mod-calc.hpp\"\n#include <map>\n\nint safe_mod(long\
    \ long a, int m) {\n    a %= m;\n    if (a < 0) { a += m; }\n    return a;\n};\n\
    \nint mod_inv(long long a, int m) {\n    long long b = m, x = 1, u = 0;\n    while\
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
    \  }\n    return -1;\n}\n"
  code: "#include <map>\n\nint safe_mod(long long a, int m) {\n    a %= m;\n    if\
    \ (a < 0) { a += m; }\n    return a;\n};\n\nint mod_inv(long long a, int m) {\n\
    \    long long b = m, x = 1, u = 0;\n    while (b) {\n        int t = a / b;\n\
    \        std::swap(a -= t * b, b);\n        std::swap(x -= t * u, u);\n    }\n\
    \    return safe_mod(x, m);\n};\n\nint mod_pow(long long a, long long n, int m)\
    \ {\n    if (n < 0) { return mod_inv(mod_pow(a, -n, m), m); }\n    long long ret\
    \ = 1, mul = a;\n    while (n) {\n        if (n & 1) { (ret *= mul) %= m; }\n\
    \        (mul *= mul) %= m, n >>= 1;\n    }\n    return ret;\n}\n\nint mod_log(long\
    \ long a, long long b, int m) {\n    a %= m, b %= m;\n    std::map<int, int> mp;\n\
    \    int rt;\n    long long ap = a;\n    for (rt = 1; rt * rt < m; rt++) {\n \
    \       if (!mp.count(ap)) { mp[ap] = rt; }\n        (ap *= a) %= m;\n    }\n\
    \    ap = mod_inv(ap, m);\n    if (mp.count(b)) { return mp[b]; }\n    mp[1] =\
    \ 0;\n    for (int i = 1; i < rt; i++) {\n        (b *= ap) %= m;\n        if\
    \ (mp.count(b)) { return i * rt + mp[b]; }\n    }\n    return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mathematics/mod-calc.hpp
  requiredBy:
  - mathematics/convolute.hpp
  timestamp: '2020-10-12 22:18:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Math/Convolution-mod-1000000007-0.test.cpp
  - test/unit-test/mathematics/mod-calc.test.cpp
documentation_of: mathematics/mod-calc.hpp
layout: document
redirect_from:
- /library/mathematics/mod-calc.hpp
- /library/mathematics/mod-calc.hpp.html
title: mathematics/mod-calc.hpp
---
