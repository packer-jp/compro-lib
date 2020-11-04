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
    \        }\n    }\n};\n"
  code: "#include <iostream>\n#include <string>\n\nusing state = std::string::const_iterator;\n\
    struct parse_error {};\n\nvoid consume(state &begin, char expected) {\n    if\
    \ (*begin == expected) {\n        begin++;\n    } else {\n        std::cerr <<\
    \ \"Expected '\" << expected << \"' but got '\" << *begin << \"'\" << std::endl;\n\
    \        std::cerr << \"Rest string is '\";\n        while (*begin) { std::cerr\
    \ << *begin++; }\n        std::cerr << \"'\" << std::endl;\n        throw parse_error();\n\
    \    }\n}\n\nstruct parser {\n    int number(state &begin) {\n        int ret\
    \ = 0;\n        while (isdigit(*begin)) {\n            ret *= 10;\n          \
    \  ret += *begin - '0';\n            begin++;\n        }\n        return ret;\n\
    \    }\n    int term(state &begin) {\n        int ret = factor(begin);\n     \
    \   while (true) {\n            if (*begin == '*') {\n                consume(begin,\
    \ '*');\n                ret *= factor(begin);\n            } else if (*begin\
    \ == '/') {\n                consume(begin, '/');\n                ret /= factor(begin);\n\
    \            } else {\n                break;\n            }\n        }\n    \
    \    return ret;\n    }\n    int expr(state &begin) {\n        int ret = term(begin);\n\
    \        while (true) {\n            if (*begin == '+') {\n                consume(begin,\
    \ '+');\n                ret += term(begin);\n            } else if (*begin ==\
    \ '-') {\n                consume(begin, '-');\n                ret -= term(begin);\n\
    \            } else {\n                break;\n            }\n        }\n    \
    \    return ret;\n    }\n    int factor(state &begin) {\n        if (*begin ==\
    \ '(') {\n            consume(begin, '(');\n            int ret = expr(begin);\n\
    \            consume(begin, ')');\n            return ret;\n        } else {\n\
    \            return number(begin);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/parse.hpp
  requiredBy: []
  timestamp: '2020-11-04 16:58:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/Volume1/Smart-Calculator-0.test.cpp
documentation_of: string/parse.hpp
layout: document
title: "\u69CB\u6587\u89E3\u6790"
---
