---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1/Pattern-Search-0.test.cpp
    title: test/AOJ/ALDS1/Pattern-Search-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/rolling-hash-2d.hpp\"\n#include <random>\n#include\
    \ <vector>\n#include <cassert>\n\nstruct rolling_hash_2d {\n    using ull = unsigned\
    \ long long;\n    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static\
    \ constexpr ull MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MOD = (1ULL\
    \ << 61) - 1;\n    static constexpr ull POSITIVIZER = MOD << 2;\n    static std::vector<ull>\
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
    \ rng()};\n"
  code: "#include <random>\n#include <vector>\n#include <cassert>\n\nstruct rolling_hash_2d\
    \ {\n    using ull = unsigned long long;\n    static constexpr ull MASK30 = (1ULL\
    \ << 30) - 1;\n    static constexpr ull MASK31 = (1ULL << 31) - 1;\n    static\
    \ constexpr ull MOD = (1ULL << 61) - 1;\n    static constexpr ull POSITIVIZER\
    \ = MOD << 2;\n    static std::vector<ull> pow_base_y, pow_base_x;\n    int h,\
    \ w;\n    std::vector<std::vector<ull>> hash;\n    static void push_pow_y(int\
    \ h) {\n        while (pow_base_y.size() <= h) { pow_base_y.push_back(calc_mod(mul(pow_base_y.back(),\
    \ pow_base_y[1]))); }\n    }\n    static void push_pow_x(int w) {\n        while\
    \ (pow_base_x.size() <= w) { pow_base_x.push_back(calc_mod(mul(pow_base_x.back(),\
    \ pow_base_x[1]))); }\n    }\n    static ull rng() {\n        std::random_device\
    \ rd;\n        return std::uniform_int_distribution<ull>(MOD >> 1, MOD - 1)(rd);\n\
    \    }\n    static ull mul(ull a, ull b) {\n        ull au = a >> 31;\n      \
    \  ull ad = a & MASK31;\n        ull bu = b >> 31;\n        ull bd = b & MASK31;\n\
    \        ull mid = ad * bu + au * bd;\n        return (au * bu << 1) + (mid >>\
    \ 30) + ((mid & MASK30) << 31) + ad * bd;\n    }\n    static ull calc_mod(ull\
    \ val) {\n        val = (val & MOD) + (val >> 61);\n        if (val >= MOD) {\
    \ val -= MOD; }\n        return val;\n    }\n    static ull connect_y(ull uhs,\
    \ ull dhs, int dh) {\n        push_pow_y(dh);\n        return calc_mod(mul(uhs,\
    \ pow_base_y[dh]) + dhs);\n    }\n    static ull connect_x(ull lhs, ull rhs, int\
    \ rw) {\n        push_pow_x(rw);\n        return calc_mod(mul(lhs, pow_base_x[rw])\
    \ + rhs);\n    }\n    template<typename T> rolling_hash_2d(const std::vector<std::vector<T>>\
    \ &src)\n        : h(src.size()), w(src[0].size()), hash(h + 1, std::vector<ull>(w\
    \ + 1)) {\n        for (int i = 0; i < h; i++) {\n            for (int j = 0;\
    \ j < w; j++) {\n                hash[i + 1][j + 1] = calc_mod((mul(hash[i][j\
    \ + 1], pow_base_y[1]) + src[i][j]));\n            }\n        }\n        for (int\
    \ i = 1; i <= h; i++) {\n            for (int j = 0; j < w; j++) {\n         \
    \       hash[i][j + 1] = calc_mod((mul(hash[i][j], pow_base_x[1]) + hash[i][j\
    \ + 1]));\n            }\n        }\n        push_pow_y(h);\n        push_pow_x(w);\n\
    \    }\n    ull get_hash(int y0, int x0, int y1, int x1) const {\n        ull\
    \ hl = calc_mod(POSITIVIZER - mul(hash[y0][x0], pow_base_y[y1 - y0]) + hash[y1][x0]);\n\
    \        ull hr = calc_mod(POSITIVIZER - mul(hash[y0][x1], pow_base_y[y1 - y0])\
    \ + hash[y1][x1]);\n        return calc_mod(POSITIVIZER - mul(hl, pow_base_x[x1\
    \ - x0]) + hr);\n    }\n};\nstd::vector<rolling_hash_2d::ull> rolling_hash_2d::pow_base_y{1,\
    \ rng()};\nstd::vector<rolling_hash_2d::ull> rolling_hash_2d::pow_base_x{1, rng()};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash-2d.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1/Pattern-Search-0.test.cpp
documentation_of: string/rolling-hash-2d.hpp
layout: document
title: "2 \u6B21\u5143\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

