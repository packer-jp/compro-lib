---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja
  bundledCode: "#line 1 \"test/unit-test/string/trie.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#line 2 \"string/trie.hpp\"\n\n\
    template<int K>\nstruct trie {\n    std::vector<std::vector<int>> adj;\n    std::vector<int>\
    \ cnt;\n    trie() : adj(1, std::vector<int>(K, -1)), cnt(1) {}\n    void insert(const\
    \ std::vector<int> &s, int m = 1) {\n        int cur = 0;\n        for (int c:s)\
    \ {\n            if (adj[cur][c] == -1) {\n                adj[cur][c] = adj.size();\n\
    \                adj.emplace_back(K, -1);\n                cnt.emplace_back(0);\n\
    \            }\n            cur = adj[cur][c];\n        }\n        cnt[cur] +=\
    \ m;\n    }\n    std::vector<int> count_prefix(const std::vector<int> &s) {\n\
    \        std::vector<int> ret(s.size() + 1);\n        ret[0] = cnt[0];\n     \
    \   int cur = 0;\n        for (int i = 0; i < s.size(); i++) {\n            if\
    \ (adj[cur][s[i]] == -1) { break; }\n            cur = adj[cur][s[i]];\n     \
    \       ret[i + 1] = cnt[cur];\n        }\n        return ret;\n    }\n};\n#line\
    \ 5 \"test/unit-test/string/trie.test.cpp\"\n\nint main() {\n    trie<2> tr;\n\
    \    tr.insert({0, 1, 1, 0});\n    tr.insert({0, 1});\n    tr.insert({0, 1});\n\
    \    tr.insert({});\n    tr.insert({0, 1, 1, 0, 1});\n    tr.insert({0, 1, 0,\
    \ 0, 1});\n    tr.insert({0, 1, 1, 0, 1, 1});\n    tr.insert({1, 0, 1, 1, 1, 1});\n\
    \    assert(tr.count_prefix({0, 1, 1, 0, 1}) == vector<int>({1, 0, 2, 0, 1, 1}));\n\
    \    tr.insert({0, 1}, -1);\n    assert(tr.count_prefix({0, 1, 1, 0, 1}) == vector<int>({1,\
    \ 0, 1, 0, 1, 1}));\n    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include\"../../../string/trie.hpp\"\
    \n\nint main() {\n    trie<2> tr;\n    tr.insert({0, 1, 1, 0});\n    tr.insert({0,\
    \ 1});\n    tr.insert({0, 1});\n    tr.insert({});\n    tr.insert({0, 1, 1, 0,\
    \ 1});\n    tr.insert({0, 1, 0, 0, 1});\n    tr.insert({0, 1, 1, 0, 1, 1});\n\
    \    tr.insert({1, 0, 1, 1, 1, 1});\n    assert(tr.count_prefix({0, 1, 1, 0, 1})\
    \ == vector<int>({1, 0, 2, 0, 1, 1}));\n    tr.insert({0, 1}, -1);\n    assert(tr.count_prefix({0,\
    \ 1, 1, 0, 1}) == vector<int>({1, 0, 1, 0, 1, 1}));\n    cout << \"Hello World\"\
    \ << endl;\n}"
  dependsOn:
  - string/trie.hpp
  isVerificationFile: true
  path: test/unit-test/string/trie.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/unit-test/string/trie.test.cpp
layout: document
redirect_from:
- /verify/test/unit-test/string/trie.test.cpp
- /verify/test/unit-test/string/trie.test.cpp.html
title: test/unit-test/string/trie.test.cpp
---
