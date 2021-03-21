---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mathematics/moebius.hpp
    title: "Moebius \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: mathematics/prime-factorize.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: string/run-length-encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
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
  bundledCode: "#line 1 \"test/unit-test/mathematics/moebius.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/moebius.hpp\"\n#include <map>\n#include <vector>\n\ntemplate<typename\
    \ T> std::map<T, int> moebius(T n) {\n    std::map<T, int> ret;\n    std::vector<T>\
    \ primes;\n    for (T i = 2; i * i <= n; i++) {\n        if (n % i == 0) {\n \
    \           primes.push_back(i);\n            while (n % i == 0) { n /= i; }\n\
    \        }\n    }\n    if (n != 1) { primes.push_back(n); }\n    int m = primes.size();\n\
    \    for (int i = 0; i < (1 << m); i++) {\n        int mul = 1;\n        T d =\
    \ 1;\n        for (int j = 0; j < m; j++) {\n            if (i >> j & 1) { mul\
    \ *= -1, d *= primes[j]; }\n        }\n        ret[d] = mul;\n    }\n    return\
    \ ret;\n}\n#line 2 \"mathematics/prime-factorize.hpp\"\n\ntemplate<typename T>\
    \ std::vector<T> prime_factorize(T n) {\n    std::vector<T> ret;\n    for (T i\
    \ = 2; i * i <= n; i++) {\n        while (n % i == 0) {\n            ret.emplace_back(i);\n\
    \            n /= i;\n        }\n    }\n    if (n != 1) { ret.emplace_back(n);\
    \ }\n    return ret;\n}\n#line 2 \"string/run-length-encoding.hpp\"\n\ntemplate<typename\
    \ T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T> src)\
    \ {\n    std::vector<std::pair<T, int>> ret;\n    if (src.size() > 0) { ret.push_back({src[0],\
    \ 1}); }\n    for (int i = 1; i < src.size(); i++) {\n        if (src[i] == ret.back().first)\
    \ { ret.back().second++; }\n        else { ret.push_back({src[i], 1}); }\n   \
    \ }\n    return ret;\n}\n#line 5 \"test/unit-test/mathematics/moebius.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int n =\
    \ 1260;\n    map<int, int> mb = moebius(n);\n    for (int i = 1; i <= n; i++)\
    \ {\n        auto pf = run_length_encoding(prime_factorize(i));\n        int m\
    \ = (pf.size() & 1) ? -1 : 1;\n        if (n % i) { m = 0; }\n        for (int\
    \ i = 0; i < pf.size(); i++) {\n            if (pf[i].second > 1) { m = 0; }\n\
    \        }\n        assert(mb[i] == m);\n    }\n\n    cout << \"Hello World\"\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/moebius.hpp\"\n#include\"../../../mathematics/prime-factorize.hpp\"\
    \n#include\"../../../string/run-length-encoding.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int n = 1260;\n    map<int, int> mb\
    \ = moebius(n);\n    for (int i = 1; i <= n; i++) {\n        auto pf = run_length_encoding(prime_factorize(i));\n\
    \        int m = (pf.size() & 1) ? -1 : 1;\n        if (n % i) { m = 0; }\n  \
    \      for (int i = 0; i < pf.size(); i++) {\n            if (pf[i].second > 1)\
    \ { m = 0; }\n        }\n        assert(mb[i] == m);\n    }\n\n    cout << \"\
    Hello World\" << endl;\n}"
  dependsOn:
  - mathematics/moebius.hpp
  - mathematics/prime-factorize.hpp
  - string/run-length-encoding.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/moebius.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unit-test/mathematics/moebius.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/moebius.test.cpp
- /verify/test/unit-test/mathematics/moebius.test.cpp.html
title: test/unit-test/mathematics/moebius.test.cpp
---
