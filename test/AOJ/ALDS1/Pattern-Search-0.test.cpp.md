---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-2d.hpp
    title: "2 \u6B21\u5143\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C&lang=ja
  bundledCode: "#line 1 \"test/AOJ/ALDS1/Pattern-Search-0.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C&lang=ja\"\
    \n#line 1 \"string/rolling-hash-2d.hpp\"\n#include <random>\n#include <vector>\n\
    #include <cassert>\n\nstruct rolling_hash_2d {\n    using ull = unsigned long\
    \ long;\n    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static constexpr\
    \ ull MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MOD = (1ULL << 61)\
    \ - 1;\n    static constexpr ull POSITIVIZER = MOD << 2;\n    static std::vector<ull>\
    \ pow_base_y, pow_base_x;\n    int h, w;\n    std::vector<std::vector<ull>> hash;\n\
    \    static void push_pow_y(int h) {\n        while (pow_base_y.size() <= h) {\
    \ pow_base_y.push_back(calc_mod(mul(pow_base_y.back(), pow_base_y[1]))); }\n \
    \   }\n    static void push_pow_x(int w) {\n        while (pow_base_x.size() <=\
    \ w) { pow_base_x.push_back(calc_mod(mul(pow_base_x.back(), pow_base_x[1])));\
    \ }\n    }\n    static ull rng() {\n        std::random_device rd;\n        return\
    \ std::uniform_int_distribution<ull>(MOD >> 1, MOD - 1)(rd);\n    }\n    static\
    \ ull mul(ull a, ull b) {\n        ull au = a >> 31;\n        ull ad = a & MASK31;\n\
    \        ull bu = b >> 31;\n        ull bd = b & MASK31;\n        ull mid = ad\
    \ * bu + au * bd;\n        return (au * bu << 1) + (mid >> 30) + ((mid & MASK30)\
    \ << 31) + ad * bd;\n    }\n    static ull calc_mod(ull val) {\n        val =\
    \ (val & MOD) + (val >> 61);\n        if (val >= MOD) { val -= MOD; }\n      \
    \  return val;\n    }\n    static ull connect_y(ull uhs, ull dhs, int dh) {\n\
    \        push_pow_y(dh);\n        return calc_mod(mul(uhs, pow_base_y[dh]) + dhs);\n\
    \    }\n    static ull connect_x(ull lhs, ull rhs, int rw) {\n        push_pow_x(rw);\n\
    \        return calc_mod(mul(lhs, pow_base_x[rw]) + rhs);\n    }\n    template<typename\
    \ T> rolling_hash_2d(const std::vector<std::vector<T>> &src)\n        : h(src.size()),\
    \ w(src[0].size()), hash(h + 1, std::vector<ull>(w + 1)) {\n        for (int i\
    \ = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n            \
    \    hash[i + 1][j + 1] = calc_mod((mul(hash[i][j + 1], pow_base_y[1]) + src[i][j]));\n\
    \            }\n        }\n        for (int i = 1; i <= h; i++) {\n          \
    \  for (int j = 0; j < w; j++) {\n                hash[i][j + 1] = calc_mod((mul(hash[i][j],\
    \ pow_base_x[1]) + hash[i][j + 1]));\n            }\n        }\n        push_pow_y(h);\n\
    \        push_pow_x(w);\n    }\n    ull get_hash(int y0, int x0, int y1, int x1)\
    \ const {\n        ull hl = calc_mod(POSITIVIZER - mul(hash[y0][x0], pow_base_y[y1\
    \ - y0]) + hash[y1][x0]);\n        ull hr = calc_mod(POSITIVIZER - mul(hash[y0][x1],\
    \ pow_base_y[y1 - y0]) + hash[y1][x1]);\n        return calc_mod(POSITIVIZER -\
    \ mul(hl, pow_base_x[x1 - x0]) + hr);\n    }\n};\nstd::vector<rolling_hash_2d::ull>\
    \ rolling_hash_2d::pow_base_y{1, rng()};\nstd::vector<rolling_hash_2d::ull> rolling_hash_2d::pow_base_x{1,\
    \ rng()};\n#line 3 \"test/AOJ/ALDS1/Pattern-Search-0.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int H, W, R, C;\n    cin >> H >> W;\n\
    \    vector<string> F(H);\n    vector<vector<char>> Fv(H, vector<char>(W));\n\
    \    for (int i = 0; i < H; i++) {\n        cin >> F[i];\n        copy(F[i].begin(),\
    \ F[i].end(), Fv[i].begin());\n    }\n    cin >> R >> C;\n    vector<string> P(R);\n\
    \    vector<vector<char>> Pv(R, vector<char>(C));\n    for (int i = 0; i < R;\
    \ i++) {\n        cin >> P[i];\n        copy(P[i].begin(), P[i].end(), Pv[i].begin());\n\
    \    }\n    rolling_hash_2d Fh(Fv), Ph(Pv);\n    for (int i = 0; i < H - R + 1;\
    \ i++) {\n        for (int j = 0; j < W - C + 1; j++) {\n            if (Fh.get_hash(i,\
    \ j, i + R, j + C) == Ph.get_hash(0, 0, R, C)) {\n                cout << i <<\
    \ \" \" << j << endl;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C&lang=ja\"\
    \n#include\"../../../string/rolling-hash-2d.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    int H, W, R, C;\n    cin >> H >> W;\n\
    \    vector<string> F(H);\n    vector<vector<char>> Fv(H, vector<char>(W));\n\
    \    for (int i = 0; i < H; i++) {\n        cin >> F[i];\n        copy(F[i].begin(),\
    \ F[i].end(), Fv[i].begin());\n    }\n    cin >> R >> C;\n    vector<string> P(R);\n\
    \    vector<vector<char>> Pv(R, vector<char>(C));\n    for (int i = 0; i < R;\
    \ i++) {\n        cin >> P[i];\n        copy(P[i].begin(), P[i].end(), Pv[i].begin());\n\
    \    }\n    rolling_hash_2d Fh(Fv), Ph(Pv);\n    for (int i = 0; i < H - R + 1;\
    \ i++) {\n        for (int j = 0; j < W - C + 1; j++) {\n            if (Fh.get_hash(i,\
    \ j, i + R, j + C) == Ph.get_hash(0, 0, R, C)) {\n                cout << i <<\
    \ \" \" << j << endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - string/rolling-hash-2d.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1/Pattern-Search-0.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1/Pattern-Search-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1/Pattern-Search-0.test.cpp
- /verify/test/AOJ/ALDS1/Pattern-Search-0.test.cpp.html
title: test/AOJ/ALDS1/Pattern-Search-0.test.cpp
---
