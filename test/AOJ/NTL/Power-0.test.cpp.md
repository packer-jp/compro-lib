---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mathematics/mod-int.hpp
    title: "\u5270\u4F59\u74B0 / \u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp
  bundledCode: "#line 1 \"test/AOJ/NTL/Power-0.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp\"\
    \n#line 1 \"mathematics/mod-int.hpp\"\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n#include <cassert>\n\ntemplate<int MOD = 1000000007>\nstruct\
    \ mod_int {\n    int val;\n    mod_int(long long val_ = 0) : val(val_ % MOD) {\
    \ if (val < 0) { val += MOD; }}\n    bool operator==(const mod_int &rhs) const\
    \ { return val == rhs.val; }\n    bool operator!=(const mod_int &rhs) const {\
    \ return std::rel_ops::operator!=(*this, rhs); }\n    mod_int &operator+=(const\
    \ mod_int &rhs) {\n        if ((val += rhs.val) >= MOD) { val -= MOD; }\n    \
    \    return *this;\n    }\n    mod_int &operator-=(const mod_int &rhs) {\n   \
    \     if ((val += MOD - rhs.val) >= MOD) { val -= MOD; }\n        return *this;\n\
    \    }\n    mod_int &operator*=(const mod_int &rhs) {\n        val = (int) ((long\
    \ long) val * rhs.val % MOD);\n        return *this;\n    }\n    mod_int &operator/=(const\
    \ mod_int &rhs) { return *this *= rhs.inv(); }\n    mod_int operator+() const\
    \ { return *this; }\n    mod_int operator-() const { return -val; }\n    mod_int\
    \ operator++() { return *this += 1; }\n    mod_int operator--() { return *this\
    \ -= 1; }\n    mod_int operator++(signed) {\n        const mod_int ret(*this);\n\
    \        ++*this;\n        return ret;\n    }\n    mod_int operator--(signed)\
    \ {\n        const mod_int ret(*this);\n        --*this;\n        return ret;\n\
    \    }\n    mod_int operator+(const mod_int &rhs) const { return mod_int(*this)\
    \ += rhs; }\n    mod_int operator-(const mod_int &rhs) const { return mod_int(*this)\
    \ -= rhs; }\n    mod_int operator*(const mod_int &rhs) const { return mod_int(*this)\
    \ *= rhs; }\n    mod_int operator/(const mod_int &rhs) const { return mod_int(*this)\
    \ /= rhs; }\n    mod_int inv() const {\n        assert(val != 0);\n        int\
    \ a = val, b = MOD, x = 1, u = 0;\n        while (b) {\n            int t = a\
    \ / b;\n            std::swap(a -= t * b, b);\n            std::swap(x -= t *\
    \ u, u);\n        }\n        return x;\n    }\n    mod_int pow(long long n) const\
    \ {\n        if (n < 0) { return pow(-n).inv(); }\n        mod_int ret = 1, mul\
    \ = *this;\n        while (n) {\n            if (n & 1) { ret *= mul; }\n    \
    \        mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n \
    \   }\n    friend std::istream &operator>>(std::istream &is, mod_int &rhs) {\n\
    \        long long v;\n        is >> v;\n        rhs = v;\n        return is;\n\
    \    }\n    friend std::ostream &operator<<(std::ostream &os, const mod_int &rhs)\
    \ { return os << rhs.val; }\n    struct combination {\n        std::vector<mod_int>\
    \ fact{1, 1}, f_inv{1, 1}, inv{0, 1};\n        void calc(int n) {\n          \
    \  while (fact.size() <= n) {\n                int i = fact.size();\n        \
    \        fact.push_back(fact[i - 1] * i);\n                inv.push_back(-inv[MOD\
    \ % i] * (MOD / i));\n                f_inv.push_back(f_inv[i - 1] * inv[i]);\n\
    \            }\n        }\n        mod_int P(int n, int r) { return r < 0 || n\
    \ < r ? 0 : (calc(n), fact[n] * f_inv[n - r]); }\n        mod_int C(int n, int\
    \ r) { return r < 0 || n < r ? 0 : (calc(n), fact[n] * f_inv[r] * f_inv[n - r]);\
    \ }\n        mod_int H(int n, int r) { return C(n + r - 1, r); }\n    };\n};\n\
    #line 3 \"test/AOJ/NTL/Power-0.test.cpp\"\n\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    mod_int<> m;\n    int n;\n    cin >> m >> n;\n   \
    \ cout << m.pow(n) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp\"\
    \n#include\"../../../mathematics/mod-int.hpp\"\n\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    mod_int<> m;\n    int n;\n    cin >> m >>\
    \ n;\n    cout << m.pow(n) << endl;\n}\n"
  dependsOn:
  - mathematics/mod-int.hpp
  isVerificationFile: true
  path: test/AOJ/NTL/Power-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL/Power-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL/Power-0.test.cpp
- /verify/test/AOJ/NTL/Power-0.test.cpp.html
title: test/AOJ/NTL/Power-0.test.cpp
---
