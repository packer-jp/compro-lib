---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/parse.hpp
    title: "\u69CB\u6587\u89E3\u6790"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp
  bundledCode: "#line 1 \"test/AOJ/Volume1/Smart-Calculator-0.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp\"\
    \n#line 1 \"string/parse.hpp\"\n#include <iostream>\n#include <string>\n\nusing\
    \ state = std::string::const_iterator;\nstruct parse_error {};\n\nvoid consume(state\
    \ &begin, char expected) {\n    if (*begin == expected) {\n        begin++;\n\
    \    } else {\n        std::cerr << \"Expected '\" << expected << \"' but got\
    \ '\" << *begin << \"'\" << std::endl;\n        std::cerr << \"Rest string is\
    \ '\";\n        while (*begin) { std::cerr << *begin++; }\n        std::cerr <<\
    \ \"'\" << std::endl;\n        throw parse_error();\n    }\n}\n\nstruct parser\
    \ {\n    int number(state &begin) {\n        int ret = 0;\n        while (isdigit(*begin))\
    \ {\n            ret *= 10;\n            ret += *begin - '0';\n            begin++;\n\
    \        }\n        return ret;\n    }\n    int term(state &begin) {\n       \
    \ int ret = factor(begin);\n        while (true) {\n            if (*begin ==\
    \ '*') {\n                consume(begin, '*');\n                ret *= factor(begin);\n\
    \            } else if (*begin == '/') {\n                consume(begin, '/');\n\
    \                ret /= factor(begin);\n            } else {\n               \
    \ break;\n            }\n        }\n        return ret;\n    }\n    int expr(state\
    \ &begin) {\n        int ret = term(begin);\n        while (true) {\n        \
    \    if (*begin == '+') {\n                consume(begin, '+');\n            \
    \    ret += term(begin);\n            } else if (*begin == '-') {\n          \
    \      consume(begin, '-');\n                ret -= term(begin);\n           \
    \ } else {\n                break;\n            }\n        }\n        return ret;\n\
    \    }\n    int factor(state &begin) {\n        if (*begin == '(') {\n       \
    \     consume(begin, '(');\n            int ret = expr(begin);\n            consume(begin,\
    \ ')');\n            return ret;\n        } else {\n            return number(begin);\n\
    \        }\n    }\n};\n#line 3 \"test/AOJ/Volume1/Smart-Calculator-0.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N;\n\
    \    cin >> N;\n    cin.ignore();\n    for (int i = 0; i < N; i++) {\n       \
    \ string s;\n        getline(cin, s);\n        state begin = s.begin();\n    \
    \    int ans = parser().expr(begin);\n        consume(begin, '=');\n        cout\
    \ << ans << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp\"\
    \n#include \"../../../string/parse.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    int N;\n    cin >> N;\n    cin.ignore();\n    for\
    \ (int i = 0; i < N; i++) {\n        string s;\n        getline(cin, s);\n   \
    \     state begin = s.begin();\n        int ans = parser().expr(begin);\n    \
    \    consume(begin, '=');\n        cout << ans << endl;\n    }\n    return 0;\n\
    }"
  dependsOn:
  - string/parse.hpp
  isVerificationFile: true
  path: test/AOJ/Volume1/Smart-Calculator-0.test.cpp
  requiredBy: []
  timestamp: '2020-11-04 16:58:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/Volume1/Smart-Calculator-0.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/Volume1/Smart-Calculator-0.test.cpp
- /verify/test/AOJ/Volume1/Smart-Calculator-0.test.cpp.html
title: test/AOJ/Volume1/Smart-Calculator-0.test.cpp
---
