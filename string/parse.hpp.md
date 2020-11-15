---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/Volume1/Smart-Calculator-0.test.cpp
    title: test/AOJ/Volume1/Smart-Calculator-0.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/parse.hpp\"\n#include <iostream>\n#include <string>\n\
    \nusing state = std::string::const_iterator;\nstruct parse_error {};\n\nvoid consume(state\
    \ &cur, char expected) {\n    if (*cur == expected) {\n        cur++;\n    } else\
    \ {\n        std::cerr << \"Expected '\" << expected << \"' but got '\" << *cur\
    \ << \"'\" << std::endl;\n        std::cerr << \"Rest string is '\";\n       \
    \ while (*cur) { std::cerr << *cur++; }\n        std::cerr << \"'\" << std::endl;\n\
    \        throw parse_error();\n    }\n}\n\n\nstruct parser {\n    int expr(state\
    \ &cur) {\n        int ret = term(cur);\n        while (true) {\n            if\
    \ (*cur == '+') {\n                consume(cur, '+');\n                ret +=\
    \ term(cur);\n            } else if (*cur == '-') {\n                consume(cur,\
    \ '-');\n                ret -= term(cur);\n            } else {\n           \
    \     break;\n            }\n        }\n        return ret;\n    }\n    int term(state\
    \ &cur) {\n        int ret = factor(cur);\n        while (true) {\n          \
    \  if (*cur == '*') {\n                consume(cur, '*');\n                ret\
    \ *= factor(cur);\n            } else if (*cur == '/') {\n                consume(cur,\
    \ '/');\n                ret /= factor(cur);\n            } else {\n         \
    \       break;\n            }\n        }\n        return ret;\n    }\n    int\
    \ factor(state &cur) {\n        if (*cur == '(') {\n            consume(cur, '(');\n\
    \            int ret = expr(cur);\n            consume(cur, ')');\n          \
    \  return ret;\n        } else {\n            return number(cur);\n        }\n\
    \    }\n    int number(state &cur) {\n        int ret = 0;\n        while (isdigit(*cur))\
    \ {\n            ret *= 10;\n            ret += *cur - '0';\n            cur++;\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include <iostream>\n#include <string>\n\nusing state = std::string::const_iterator;\n\
    struct parse_error {};\n\nvoid consume(state &cur, char expected) {\n    if (*cur\
    \ == expected) {\n        cur++;\n    } else {\n        std::cerr << \"Expected\
    \ '\" << expected << \"' but got '\" << *cur << \"'\" << std::endl;\n        std::cerr\
    \ << \"Rest string is '\";\n        while (*cur) { std::cerr << *cur++; }\n  \
    \      std::cerr << \"'\" << std::endl;\n        throw parse_error();\n    }\n\
    }\n\n\nstruct parser {\n    int expr(state &cur) {\n        int ret = term(cur);\n\
    \        while (true) {\n            if (*cur == '+') {\n                consume(cur,\
    \ '+');\n                ret += term(cur);\n            } else if (*cur == '-')\
    \ {\n                consume(cur, '-');\n                ret -= term(cur);\n \
    \           } else {\n                break;\n            }\n        }\n     \
    \   return ret;\n    }\n    int term(state &cur) {\n        int ret = factor(cur);\n\
    \        while (true) {\n            if (*cur == '*') {\n                consume(cur,\
    \ '*');\n                ret *= factor(cur);\n            } else if (*cur == '/')\
    \ {\n                consume(cur, '/');\n                ret /= factor(cur);\n\
    \            } else {\n                break;\n            }\n        }\n    \
    \    return ret;\n    }\n    int factor(state &cur) {\n        if (*cur == '(')\
    \ {\n            consume(cur, '(');\n            int ret = expr(cur);\n      \
    \      consume(cur, ')');\n            return ret;\n        } else {\n       \
    \     return number(cur);\n        }\n    }\n    int number(state &cur) {\n  \
    \      int ret = 0;\n        while (isdigit(*cur)) {\n            ret *= 10;\n\
    \            ret += *cur - '0';\n            cur++;\n        }\n        return\
    \ ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/parse.hpp
  requiredBy: []
  timestamp: '2020-11-05 01:51:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/Volume1/Smart-Calculator-0.test.cpp
documentation_of: string/parse.hpp
layout: document
title: "\u69CB\u6587\u89E3\u6790"
---
