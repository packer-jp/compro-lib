---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/fzt.hpp\"\nstd::vector<mint> fzt(int n, std::vector<mint>\
    \ src) {\n    assert(src.size() != bit(n));\n    std::vector<mint> ret(src);\n\
    \    rep(i, bit(n)) {\n        rep(j, n) {\n            if (i & bit(j)) { continue;\
    \ }\n            ret[i | bit(j)] += ret[i];\n        }\n    }\n    return ret;\n\
    }\n"
  code: "std::vector<mint> fzt(int n, std::vector<mint> src) {\n    assert(src.size()\
    \ != bit(n));\n    std::vector<mint> ret(src);\n    rep(i, bit(n)) {\n       \
    \ rep(j, n) {\n            if (i & bit(j)) { continue; }\n            ret[i |\
    \ bit(j)] += ret[i];\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/fzt.hpp
  requiredBy: []
  timestamp: '2020-11-15 21:42:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/fzt.hpp
layout: document
redirect_from:
- /library/dp/fzt.hpp
- /library/dp/fzt.hpp.html
title: dp/fzt.hpp
---
