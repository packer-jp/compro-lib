---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"marathon/marathon.hpp\"\nvoid simulated_annealing() {\n\
    \    timer.init();\n    double T = 5.95;\n    double start_temp = 0.01;\n    double\
    \ end_temp = 0.01;\n    int it = 0, pre_score;\n    double time;\n    while ((time\
    \ = timer.get_time()) < T) {\n        it++;\n        double temp = start_temp\
    \ + (end_temp - start_temp) * time / T;\n        int new_score;\n        // \u30B9\
    \u30B3\u30A2\u304C\u9AD8\u3044\u307B\u3069\u3044\u3044\n        double prob =\
    \ exp((new_score - pre_score) / temp);\n        if (prob < (double) xor64(10000000)\
    \ / 10000000) {\n            // rejected\n        } else {\n            // accepted\n\
    \        }\n    }\n}\n\nstruct state {\n    int val;\n};\nstate beam_search()\
    \ {\n    int T = 1000;\n    int beam_width = 100;\n    vector<state> pre_states;\n\
    \    for (int i = 0; i < T; i++) {\n        vector<state> next_states;\n     \
    \   // pre_states\u304B\u3089\u6B21\u306E\u72B6\u614B\u3092\u8A08\u7B97\u3057\
    next_states\u306B\u7A81\u3063\u8FBC\u3080\n        vector<int> idx(next_states.size());\n\
    \        for (int i = 0; i < idx.size(); i++) { idx[i] = i; }\n        nth_element(idx.begin(),\
    \ idx.begin() + beam_width - 1, idx.end(), [&](int l, int r) {\n            //\
    \ l\u306E\u307B\u3046\u304C\u512A\u5148\u5EA6\u304C\u9AD8\u3044\u6642\u3001true\n\
    \            return next_states[l].val > next_states[r].val;\n        });\n  \
    \      pre_states.clear();\n        for (int i = 0; i < min(beam_width, (int)\
    \ idx.size()); i++) {\n            pre_states.push_back(next_states[idx[i]]);\n\
    \        }\n    }\n    state ret;\n    for (int i = 0; i < pre_states.size();\
    \ i++) {\n        if (ret.val < pre_states[i].val) { ret = pre_states[i]; }\n\
    \    }\n    return ret;\n}\n"
  code: "void simulated_annealing() {\n    timer.init();\n    double T = 5.95;\n \
    \   double start_temp = 0.01;\n    double end_temp = 0.01;\n    int it = 0, pre_score;\n\
    \    double time;\n    while ((time = timer.get_time()) < T) {\n        it++;\n\
    \        double temp = start_temp + (end_temp - start_temp) * time / T;\n    \
    \    int new_score;\n        // \u30B9\u30B3\u30A2\u304C\u9AD8\u3044\u307B\u3069\
    \u3044\u3044\n        double prob = exp((new_score - pre_score) / temp);\n   \
    \     if (prob < (double) xor64(10000000) / 10000000) {\n            // rejected\n\
    \        } else {\n            // accepted\n        }\n    }\n}\n\nstruct state\
    \ {\n    int val;\n};\nstate beam_search() {\n    int T = 1000;\n    int beam_width\
    \ = 100;\n    vector<state> pre_states;\n    for (int i = 0; i < T; i++) {\n \
    \       vector<state> next_states;\n        // pre_states\u304B\u3089\u6B21\u306E\
    \u72B6\u614B\u3092\u8A08\u7B97\u3057next_states\u306B\u7A81\u3063\u8FBC\u3080\n\
    \        vector<int> idx(next_states.size());\n        for (int i = 0; i < idx.size();\
    \ i++) { idx[i] = i; }\n        nth_element(idx.begin(), idx.begin() + beam_width\
    \ - 1, idx.end(), [&](int l, int r) {\n            // l\u306E\u307B\u3046\u304C\
    \u512A\u5148\u5EA6\u304C\u9AD8\u3044\u6642\u3001true\n            return next_states[l].val\
    \ > next_states[r].val;\n        });\n        pre_states.clear();\n        for\
    \ (int i = 0; i < min(beam_width, (int) idx.size()); i++) {\n            pre_states.push_back(next_states[idx[i]]);\n\
    \        }\n    }\n    state ret;\n    for (int i = 0; i < pre_states.size();\
    \ i++) {\n        if (ret.val < pre_states[i].val) { ret = pre_states[i]; }\n\
    \    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: marathon/marathon.hpp
  requiredBy: []
  timestamp: '2020-08-08 15:28:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/marathon.hpp
layout: document
redirect_from:
- /library/marathon/marathon.hpp
- /library/marathon/marathon.hpp.html
title: marathon/marathon.hpp
---
