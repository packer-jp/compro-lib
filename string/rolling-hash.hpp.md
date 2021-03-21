---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1/String-Search-0.test.cpp
    title: test/AOJ/ALDS1/String-Search-0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\n#include <random>\n#include <vector>\n\
    #include <cassert>\n\nstruct rolling_hash {\n    using ull = unsigned long long;\n\
    \    static constexpr ull MASK30 = (1ULL << 30) - 1;\n    static constexpr ull\
    \ MASK31 = (1ULL << 31) - 1;\n    static constexpr ull MOD = (1ULL << 61) - 1;\n\
    \    static constexpr ull POSITIVIZER = MOD << 2;\n    static std::vector<ull>\
    \ pow_base;\n    int n;\n    std::vector<ull> hash;\n    static void push_pow(int\
    \ n) {\n        while (pow_base.size() <= n) { pow_base.push_back(calc_mod(mul(pow_base.back(),\
    \ pow_base[1]))); }\n    }\n    static ull rng() {\n        std::random_device\
    \ rd;\n        return std::uniform_int_distribution<ull>(MOD >> 1, MOD - 1)(rd);\n\
    \    }\n    static ull mul(ull a, ull b) {\n        ull au = a >> 31;\n      \
    \  ull ad = a & MASK31;\n        ull bu = b >> 31;\n        ull bd = b & MASK31;\n\
    \        ull mid = ad * bu + au * bd;\n        return (au * bu << 1) + (mid >>\
    \ 30) + ((mid & MASK30) << 31) + ad * bd;\n    }\n    static ull calc_mod(ull\
    \ val) {\n        val = (val & MOD) + (val >> 61);\n        if (val >= MOD) {\
    \ val -= MOD; }\n        return val;\n    }\n    static ull connect(ull lhs, ull\
    \ rhs, int rn) {\n        push_pow(rn);\n        return calc_mod(mul(lhs, pow_base[rn])\
    \ + rhs);\n    }\n    template<typename T> rolling_hash(const std::vector<T> &src)\
    \ : n(src.size()), hash(n + 1) {\n        for (int i = 0; i < src.size(); i++)\
    \ { hash[i + 1] = calc_mod(mul(hash[i], pow_base[1]) + src[i]); }\n        push_pow(n);\n\
    \    }\n    ull get_hash(int l, int r) const { return calc_mod(POSITIVIZER - mul(hash[l],\
    \ pow_base[r - l]) + hash[r]); }\n};\nstd::vector<rolling_hash::ull> rolling_hash::pow_base{1,\
    \ rng()};\n"
  code: "#include <random>\n#include <vector>\n#include <cassert>\n\nstruct rolling_hash\
    \ {\n    using ull = unsigned long long;\n    static constexpr ull MASK30 = (1ULL\
    \ << 30) - 1;\n    static constexpr ull MASK31 = (1ULL << 31) - 1;\n    static\
    \ constexpr ull MOD = (1ULL << 61) - 1;\n    static constexpr ull POSITIVIZER\
    \ = MOD << 2;\n    static std::vector<ull> pow_base;\n    int n;\n    std::vector<ull>\
    \ hash;\n    static void push_pow(int n) {\n        while (pow_base.size() <=\
    \ n) { pow_base.push_back(calc_mod(mul(pow_base.back(), pow_base[1]))); }\n  \
    \  }\n    static ull rng() {\n        std::random_device rd;\n        return std::uniform_int_distribution<ull>(MOD\
    \ >> 1, MOD - 1)(rd);\n    }\n    static ull mul(ull a, ull b) {\n        ull\
    \ au = a >> 31;\n        ull ad = a & MASK31;\n        ull bu = b >> 31;\n   \
    \     ull bd = b & MASK31;\n        ull mid = ad * bu + au * bd;\n        return\
    \ (au * bu << 1) + (mid >> 30) + ((mid & MASK30) << 31) + ad * bd;\n    }\n  \
    \  static ull calc_mod(ull val) {\n        val = (val & MOD) + (val >> 61);\n\
    \        if (val >= MOD) { val -= MOD; }\n        return val;\n    }\n    static\
    \ ull connect(ull lhs, ull rhs, int rn) {\n        push_pow(rn);\n        return\
    \ calc_mod(mul(lhs, pow_base[rn]) + rhs);\n    }\n    template<typename T> rolling_hash(const\
    \ std::vector<T> &src) : n(src.size()), hash(n + 1) {\n        for (int i = 0;\
    \ i < src.size(); i++) { hash[i + 1] = calc_mod(mul(hash[i], pow_base[1]) + src[i]);\
    \ }\n        push_pow(n);\n    }\n    ull get_hash(int l, int r) const { return\
    \ calc_mod(POSITIVIZER - mul(hash[l], pow_base[r - l]) + hash[r]); }\n};\nstd::vector<rolling_hash::ull>\
    \ rolling_hash::pow_base{1, rng()};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1/String-Search-0.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

