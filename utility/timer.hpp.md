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
  bundledCode: "#line 1 \"utility/timer.hpp\"\nstruct timer {\n    unsigned long long\
    \ begin_cycle;\n    double cycle_per_sec = 2.8e9;\n    unsigned long long get_cycle()\
    \ {\n        unsigned low, high;\n        __asm__ volatile(\"rdtsc\":\"=a\"(low),\
    \ \"=d\"(high));\n        return ((unsigned long long) low) | ((unsigned long\
    \ long) high << 32);\n    }\n    double get_time() { return (get_cycle() - begin_cycle)\
    \ / cycle_per_sec; }\n    void init() { begin_cycle = get_cycle(); }\n} timer;\n"
  code: "struct timer {\n    unsigned long long begin_cycle;\n    double cycle_per_sec\
    \ = 2.8e9;\n    unsigned long long get_cycle() {\n        unsigned low, high;\n\
    \        __asm__ volatile(\"rdtsc\":\"=a\"(low), \"=d\"(high));\n        return\
    \ ((unsigned long long) low) | ((unsigned long long) high << 32);\n    }\n   \
    \ double get_time() { return (get_cycle() - begin_cycle) / cycle_per_sec; }\n\
    \    void init() { begin_cycle = get_cycle(); }\n} timer;"
  dependsOn: []
  isVerificationFile: false
  path: utility/timer.hpp
  requiredBy: []
  timestamp: '2020-09-23 17:29:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/timer.hpp
layout: document
title: "\u30BF\u30A4\u30DE\u30FC"
---

