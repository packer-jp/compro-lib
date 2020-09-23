---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mathematics/permutation.hpp
    title: "\u9806\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/mathematics/permutation.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#line 1 \"mathematics/permutation.hpp\"\n#include <algorithm>\n#include <iostream>\n\
    #include <vector>\n\nstruct permutation {\n    int n;\n    std::vector<int> data;\n\
    \    permutation(int n) : n(n), data(n) { for (int i = 0; i < n; i++) { data[i]\
    \ = i; }}\n    permutation(const std::vector<int> &src) : n(src.size()), data(src)\
    \ {}\n    bool next() { return std::next_permutation(data.begin(), data.end());\
    \ }\n    bool prev() { return std::prev_permutation(data.begin(), data.end());\
    \ }\n    bool operator==(const permutation &rhs) const { return data == rhs.data;\
    \ }\n    bool operator!=(const permutation &rhs) const { return std::rel_ops::operator!=(*this,\
    \ rhs); }\n    int operator[](int i) const { return data[i]; }\n    permutation\
    \ &operator*=(const permutation &rhs) {\n        std::vector<int> tmp(data);\n\
    \        for (int i = 0; i < n; i++) { data[i] = tmp[rhs[i]]; }\n        return\
    \ *this;\n    }\n    permutation &operator/=(const permutation &rhs) { return\
    \ *this *= rhs.inv(); }\n    permutation operator*(const permutation &rhs) const\
    \ { return permutation(*this) *= rhs; }\n    permutation operator/(const permutation\
    \ &rhs) const { return permutation(*this) /= rhs; }\n    permutation inv() const\
    \ {\n        std::vector<int> ret(n);\n        for (int i = 0; i < n; i++) { ret[data[i]]\
    \ = i; }\n        return ret;\n    }\n    permutation pow(long long m) const {\n\
    \        std::vector<int> ret(n);\n        std::vector<bool> used(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            if (used[i]) { continue; }\n   \
    \         std::vector<int> cyc;\n            int cur = i;\n            do {\n\
    \                used[cur] = true;\n                cyc.push_back(cur);\n    \
    \            cur = data[cur];\n            } while (cur != i);\n            for\
    \ (int j = 0; j < cyc.size(); j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()];\
    \ }\n        }\n        return ret;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const permutation &rhs) {\n        os << \"{\";\n        for (int i = 0;\
    \ i < rhs.n; i++) { os << rhs[i] << (i + 1 != rhs.n ? \", \" : \"\"); }\n    \
    \    os << \"}\";\n        return os;\n    }\n};\n#line 3 \"test/unit-test/mathematics/permutation.test.cpp\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    vector<int>\
    \ e = {0, 1, 2, 3, 4};\n    vector<int> a = {3, 2, 1, 4, 0};\n    vector<int>\
    \ b = {1, 2, 0, 3, 4};\n    vector<int> ab = {2, 1, 3, 4, 0};\n    vector<int>\
    \ a9 = {0, 2, 1, 3, 4};\n    vector<int> b6 = {0, 1, 2, 3, 4};\n\n    assert(permutation(5)\
    \ == permutation(e));\n    assert(permutation(a) * permutation(b) == permutation(ab));\n\
    \    assert(permutation(ab) / permutation(b) == permutation(a));\n    assert(permutation(a).pow(0)\
    \ == permutation(e));\n    assert(permutation(a).pow(9) == permutation(a9));\n\
    \    assert(permutation(b).pow(6) == permutation(b6));\n\n    cout << \"Hello\
    \ World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include\"../../../mathematics/permutation.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    vector<int> e = {0, 1, 2, 3, 4};\n \
    \   vector<int> a = {3, 2, 1, 4, 0};\n    vector<int> b = {1, 2, 0, 3, 4};\n \
    \   vector<int> ab = {2, 1, 3, 4, 0};\n    vector<int> a9 = {0, 2, 1, 3, 4};\n\
    \    vector<int> b6 = {0, 1, 2, 3, 4};\n\n    assert(permutation(5) == permutation(e));\n\
    \    assert(permutation(a) * permutation(b) == permutation(ab));\n    assert(permutation(ab)\
    \ / permutation(b) == permutation(a));\n    assert(permutation(a).pow(0) == permutation(e));\n\
    \    assert(permutation(a).pow(9) == permutation(a9));\n    assert(permutation(b).pow(6)\
    \ == permutation(b6));\n\n    cout << \"Hello World\" << endl;\n}"
  dependsOn:
  - mathematics/permutation.hpp
  isVerificationFile: true
  path: test/unit-test/mathematics/permutation.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit-test/mathematics/permutation.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/mathematics/permutation.test.cpp
- /verify/test/unit-test/mathematics/permutation.test.cpp.html
title: test/unit-test/mathematics/permutation.test.cpp
---
