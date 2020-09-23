---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Sample/Many-A-Plus-B-0.test.cpp
    title: test/Library-Checker/Sample/Many-A-Plus-B-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"utility/fast-io.hpp\"\n#include <iostream>\n\nstruct fast_io\
    \ {\n    static constexpr int SIZE_IN = 1 << 26, SIZE_OUT = 1 << 26;\n    char\
    \ data_in[SIZE_IN], data_out[SIZE_OUT], *p_in, *p_out, s[30];\n    fast_io() {\
    \ fread(data_in, 1, SIZE_IN, stdin), p_in = data_in, p_out = data_out; }\n   \
    \ ~fast_io() { fwrite(data_out, 1, p_out - data_out, stdout); }\n    void putchar(char\
    \ x) { *p_out++ = x; }\n    template<typename T> void putint(T x) {\n        if\
    \ (x < 0) { *p_out++ = '-', x = -x; }\n        int i = 0;\n        do { s[i++]\
    \ = x % 10 + '0'; } while (x /= 10);\n        while (i--) { *p_out++ = s[i]; }\n\
    \    }\n    template<typename T=int> T getint() {\n        while (!isdigit(*p_in)\
    \ && *p_in != '-') { p_in++; }\n        bool negative = *p_in == '-';\n      \
    \  T ret = negative ? 0 : *p_in - '0';\n        while (isdigit(*++p_in)) { (ret\
    \ *= 10) += *p_in - '0'; };\n        return negative ? -ret : ret;\n    }\n} io;\n"
  code: "#include <iostream>\n\nstruct fast_io {\n    static constexpr int SIZE_IN\
    \ = 1 << 26, SIZE_OUT = 1 << 26;\n    char data_in[SIZE_IN], data_out[SIZE_OUT],\
    \ *p_in, *p_out, s[30];\n    fast_io() { fread(data_in, 1, SIZE_IN, stdin), p_in\
    \ = data_in, p_out = data_out; }\n    ~fast_io() { fwrite(data_out, 1, p_out -\
    \ data_out, stdout); }\n    void putchar(char x) { *p_out++ = x; }\n    template<typename\
    \ T> void putint(T x) {\n        if (x < 0) { *p_out++ = '-', x = -x; }\n    \
    \    int i = 0;\n        do { s[i++] = x % 10 + '0'; } while (x /= 10);\n    \
    \    while (i--) { *p_out++ = s[i]; }\n    }\n    template<typename T=int> T getint()\
    \ {\n        while (!isdigit(*p_in) && *p_in != '-') { p_in++; }\n        bool\
    \ negative = *p_in == '-';\n        T ret = negative ? 0 : *p_in - '0';\n    \
    \    while (isdigit(*++p_in)) { (ret *= 10) += *p_in - '0'; };\n        return\
    \ negative ? -ret : ret;\n    }\n} io;"
  dependsOn: []
  isVerificationFile: false
  path: utility/fast-io.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Sample/Many-A-Plus-B-0.test.cpp
documentation_of: utility/fast-io.hpp
layout: document
redirect_from:
- /library/utility/fast-io.hpp
- /library/utility/fast-io.hpp.html
title: utility/fast-io.hpp
---
