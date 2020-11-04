---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define int long long\n#define rep(i, n) for (int i = 0; i < (int) (n);\
    \ i++)\n#define reps(i, n) for (int i = 1; i <= (int) (n); i++)\n#define all(a)\
    \ (a).begin(), (a).end()\n#define uniq(a) (a).erase(unique(all(a)), (a).end())\n\
    #define bit(n) (1LL << (n))\n#define dump(a) cerr << #a \" = \" << (a) << endl\n\
    #define fin(a) cout << (a) << endl; return\nusing vint = vector<int>;\nusing pint\
    \ = pair<int, int>;\nusing vpint = vector<pint>;\ntemplate<typename T> using priority_queue_rev\
    \ = priority_queue<T, vector<T>, greater<T>>;\nconstexpr double PI = 3.1415926535897932384626433832795028;\n\
    constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr int DX[9] = {1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0};\nint sign(int a) { return (a > 0) - (a < 0); }\n\
    int cdiv(int a, int b) { return (a - 1 + b) / b; }\ntemplate<typename T> T sq(T\
    \ a) { return a * a; }\ntemplate<typename T, typename U> bool chmax(T &a, const\
    \ U &b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\ntemplate<typename T, typename U> bool chmin(T &a, const U\
    \ &b) {\n    if (b < a) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate<typename T, typename U> ostream &operator<<(ostream &os,\
    \ const pair<T, U> &a) {\n    os << \"(\" << a.first << \", \" << a.second <<\
    \ \")\";\n    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); itr++) {\n        os << *itr << (next(itr) != a.end() ? \",\
    \ \" : \"\");\n    }\n    os << \")\";\n    return os;\n}\ntemplate<typename T>\
    \ ostream &operator<<(ostream &os, const deque<T> &a) {\n    os << \"(\";\n  \
    \  for (auto itr = a.begin(); itr != a.end(); itr++) {\n        os << *itr <<\
    \ (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os << \")\";\n    return\
    \ os;\n}\ntemplate<typename T> ostream &operator<<(ostream &os, const set<T> &a)\
    \ {\n    os << \"{\";\n    for (auto itr = a.begin(); itr != a.end(); itr++) {\n\
    \        os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os\
    \ << \"}\";\n    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const multiset<T> &a) {\n    os << \"{\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); itr++) {\n        os << *itr << (next(itr) != a.end() ? \",\
    \ \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\ntemplate<typename T,\
    \ typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {\n    os <<\
    \ \"{\";\n    for (auto itr = a.begin(); itr != a.end(); itr++) {\n        os\
    \ << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n\
    \    return os;\n}\nstruct setup {\n    static constexpr int PREC = 20;\n    setup()\
    \ {\n        cout << fixed << setprecision(PREC);\n        cerr << fixed << setprecision(PREC);\n\
    \    };\n} setup;\n\nvoid solve() {\n\n}\n\nsigned main() {\n    solve();\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define int long long\n\
    #define rep(i, n) for (int i = 0; i < (int) (n); i++)\n#define reps(i, n) for\
    \ (int i = 1; i <= (int) (n); i++)\n#define all(a) (a).begin(), (a).end()\n#define\
    \ uniq(a) (a).erase(unique(all(a)), (a).end())\n#define bit(n) (1LL << (n))\n\
    #define dump(a) cerr << #a \" = \" << (a) << endl\n#define fin(a) cout << (a)\
    \ << endl; return\nusing vint = vector<int>;\nusing pint = pair<int, int>;\nusing\
    \ vpint = vector<pint>;\ntemplate<typename T> using priority_queue_rev = priority_queue<T,\
    \ vector<T>, greater<T>>;\nconstexpr double PI = 3.1415926535897932384626433832795028;\n\
    constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr int DX[9] = {1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0};\nint sign(int a) { return (a > 0) - (a < 0); }\n\
    int cdiv(int a, int b) { return (a - 1 + b) / b; }\ntemplate<typename T> T sq(T\
    \ a) { return a * a; }\ntemplate<typename T, typename U> bool chmax(T &a, const\
    \ U &b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\ntemplate<typename T, typename U> bool chmin(T &a, const U\
    \ &b) {\n    if (b < a) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate<typename T, typename U> ostream &operator<<(ostream &os,\
    \ const pair<T, U> &a) {\n    os << \"(\" << a.first << \", \" << a.second <<\
    \ \")\";\n    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const vector<T> &a) {\n    os << \"(\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); itr++) {\n        os << *itr << (next(itr) != a.end() ? \",\
    \ \" : \"\");\n    }\n    os << \")\";\n    return os;\n}\ntemplate<typename T>\
    \ ostream &operator<<(ostream &os, const deque<T> &a) {\n    os << \"(\";\n  \
    \  for (auto itr = a.begin(); itr != a.end(); itr++) {\n        os << *itr <<\
    \ (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os << \")\";\n    return\
    \ os;\n}\ntemplate<typename T> ostream &operator<<(ostream &os, const set<T> &a)\
    \ {\n    os << \"{\";\n    for (auto itr = a.begin(); itr != a.end(); itr++) {\n\
    \        os << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os\
    \ << \"}\";\n    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const multiset<T> &a) {\n    os << \"{\";\n    for (auto itr = a.begin();\
    \ itr != a.end(); itr++) {\n        os << *itr << (next(itr) != a.end() ? \",\
    \ \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\ntemplate<typename T,\
    \ typename U> ostream &operator<<(ostream &os, const map<T, U> &a) {\n    os <<\
    \ \"{\";\n    for (auto itr = a.begin(); itr != a.end(); itr++) {\n        os\
    \ << *itr << (next(itr) != a.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n\
    \    return os;\n}\nstruct setup {\n    static constexpr int PREC = 20;\n    setup()\
    \ {\n        cout << fixed << setprecision(PREC);\n        cerr << fixed << setprecision(PREC);\n\
    \    };\n} setup;\n\nvoid solve() {\n\n}\n\nsigned main() {\n    solve();\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2020-11-04 16:58:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---
