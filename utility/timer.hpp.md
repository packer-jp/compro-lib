---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/utility/timer.md
    document_title: "\u30BF\u30A4\u30DE\u30FC"
    links: []
  bundledCode: "#line 1 \"utility/timer.hpp\"\n/*\n * @title \u30BF\u30A4\u30DE\u30FC\
    \n * @docs docs/utility/timer.md\n */\n\nstruct timer {\n    unsigned long long\
    \ begin_cycle;\n    double cycle_per_sec = 2.8e9;\n    unsigned long long get_cycle()\
    \ {\n        unsigned low, high;\n        __asm__ volatile(\"rdtsc\":\"=a\"(low),\
    \ \"=d\"(high));\n        return ((unsigned long long) low) | ((unsigned long\
    \ long) high << 32);\n    }\n    double get_time() { return (get_cycle() - begin_cycle)\
    \ / cycle_per_sec; }\n    void init() { begin_cycle = get_cycle(); }\n} timer;\n"
  code: "/*\n * @title \u30BF\u30A4\u30DE\u30FC\n * @docs docs/utility/timer.md\n\
    \ */\n\nstruct timer {\n    unsigned long long begin_cycle;\n    double cycle_per_sec\
    \ = 2.8e9;\n    unsigned long long get_cycle() {\n        unsigned low, high;\n\
    \        __asm__ volatile(\"rdtsc\":\"=a\"(low), \"=d\"(high));\n        return\
    \ ((unsigned long long) low) | ((unsigned long long) high << 32);\n    }\n   \
    \ double get_time() { return (get_cycle() - begin_cycle) / cycle_per_sec; }\n\
    \    void init() { begin_cycle = get_cycle(); }\n} timer;"
  dependsOn: []
  isVerificationFile: false
  path: utility/timer.hpp
  requiredBy: []
  timestamp: '2020-08-14 03:00:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/timer.hpp
layout: document
title: "\u30BF\u30A4\u30DE\u30FC"
---

