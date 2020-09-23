---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"template.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define int long long\n#define rep(i, n) for (int i = 0; i < (int) (n);\
    \ i++)\n#define reps(i, n) for (int i = 1; i <= (int) (n); i++)\n#define all(x)\
    \ (x).begin(), (x).end()\n#define uniq(x) (x).erase(unique(all(x)), (x).end())\n\
    #define bit(n) (1LL << (n))\n#define dump(x) cerr << #x \" = \" << (x) << endl\n\
    using vint = vector<int>;\nusing vvint = vector<vint>;\nusing pint = pair<int,\
    \ int>;\nusing vpint = vector<pint>;\ntemplate<typename T> using priority_queue_rev\
    \ = priority_queue<T, vector<T>, greater<T>>;\nconstexpr double PI = 3.1415926535897932384626433832795028;\n\
    constexpr int DY[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr int DX[9] = {1,\
    \ 0, -1, 0, 1, -1, -1, 1, 0};\nint sign(int x) { return (x > 0) - (x < 0); }\n\
    int gcd(int a, int b) {\n    while (b) { swap(a %= b, b); }\n    return a;\n}\n\
    int lcm(int a, int b) { return a / gcd(a, b) * b; }\nint cdiv(int a, int b) {\
    \ return (a - 1 + b) / b; }\ntemplate<typename T> void fin(T mes) {\n    cout\
    \ << mes << endl;\n    exit(0);\n}\ntemplate<typename T> T sq(T x) { return x\
    \ * x; }\ntemplate<typename T, typename U> bool chmax(T &a, const U &b) {\n  \
    \  if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\ntemplate<typename T, typename U> bool chmin(T &a, const U &b) {\n    if (b\
    \ < a) {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\
    template<typename T, typename U> ostream &operator<<(ostream &os, const pair<T,\
    \ U> &rhs) {\n    os << \"(\" << rhs.first << \", \" << rhs.second << \")\";\n\
    \    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream &os, const\
    \ vector<T> &rhs) {\n    os << \"{\";\n    for (auto itr = rhs.begin(); itr !=\
    \ rhs.end(); itr++) {\n        os << *itr << (next(itr) != rhs.end() ? \", \"\
    \ : \"\");\n    }\n    os << \"}\";\n    return os;\n}\ntemplate<typename T> ostream\
    \ &operator<<(ostream &os, const deque<T> &rhs) {\n    os << \"{\";\n    for (auto\
    \ itr = rhs.begin(); itr != rhs.end(); itr++) {\n        os << *itr << (next(itr)\
    \ != rhs.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\n\
    template<typename T> ostream &operator<<(ostream &os, const set<T> &rhs) {\n \
    \   os << \"{\";\n    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {\n\
    \        os << *itr << (next(itr) != rhs.end() ? \", \" : \"\");\n    }\n    os\
    \ << \"}\";\n    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream\
    \ &os, const multiset<T> &rhs) {\n    os << \"{\";\n    for (auto itr = rhs.begin();\
    \ itr != rhs.end(); itr++) {\n        os << *itr << (next(itr) != rhs.end() ?\
    \ \", \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\ntemplate<typename\
    \ T, typename U> ostream &operator<<(ostream &os, const map<T, U> &rhs) {\n  \
    \  os << \"{\";\n    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {\n\
    \        os << *itr << (next(itr) != rhs.end() ? \", \" : \"\");\n    }\n    os\
    \ << \"}\";\n    return os;\n}\nstruct setup {\n    static constexpr int PREC\
    \ = 20;\n    setup() {\n        cout << fixed << setprecision(PREC);\n       \
    \ cerr << fixed << setprecision(PREC);\n    };\n} setup;\n\nsigned main() {\n\
    }\n\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#define int long long\n\
    #define rep(i, n) for (int i = 0; i < (int) (n); i++)\n#define reps(i, n) for\
    \ (int i = 1; i <= (int) (n); i++)\n#define all(x) (x).begin(), (x).end()\n#define\
    \ uniq(x) (x).erase(unique(all(x)), (x).end())\n#define bit(n) (1LL << (n))\n\
    #define dump(x) cerr << #x \" = \" << (x) << endl\nusing vint = vector<int>;\n\
    using vvint = vector<vint>;\nusing pint = pair<int, int>;\nusing vpint = vector<pint>;\n\
    template<typename T> using priority_queue_rev = priority_queue<T, vector<T>, greater<T>>;\n\
    constexpr double PI = 3.1415926535897932384626433832795028;\nconstexpr int DY[9]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1, 0};\nconstexpr int DX[9] = {1, 0, -1, 0, 1, -1,\
    \ -1, 1, 0};\nint sign(int x) { return (x > 0) - (x < 0); }\nint gcd(int a, int\
    \ b) {\n    while (b) { swap(a %= b, b); }\n    return a;\n}\nint lcm(int a, int\
    \ b) { return a / gcd(a, b) * b; }\nint cdiv(int a, int b) { return (a - 1 + b)\
    \ / b; }\ntemplate<typename T> void fin(T mes) {\n    cout << mes << endl;\n \
    \   exit(0);\n}\ntemplate<typename T> T sq(T x) { return x * x; }\ntemplate<typename\
    \ T, typename U> bool chmax(T &a, const U &b) {\n    if (a < b) {\n        a =\
    \ b;\n        return true;\n    }\n    return false;\n}\ntemplate<typename T,\
    \ typename U> bool chmin(T &a, const U &b) {\n    if (b < a) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\ntemplate<typename T, typename\
    \ U> ostream &operator<<(ostream &os, const pair<T, U> &rhs) {\n    os << \"(\"\
    \ << rhs.first << \", \" << rhs.second << \")\";\n    return os;\n}\ntemplate<typename\
    \ T> ostream &operator<<(ostream &os, const vector<T> &rhs) {\n    os << \"{\"\
    ;\n    for (auto itr = rhs.begin(); itr != rhs.end(); itr++) {\n        os <<\
    \ *itr << (next(itr) != rhs.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n\
    \    return os;\n}\ntemplate<typename T> ostream &operator<<(ostream &os, const\
    \ deque<T> &rhs) {\n    os << \"{\";\n    for (auto itr = rhs.begin(); itr !=\
    \ rhs.end(); itr++) {\n        os << *itr << (next(itr) != rhs.end() ? \", \"\
    \ : \"\");\n    }\n    os << \"}\";\n    return os;\n}\ntemplate<typename T> ostream\
    \ &operator<<(ostream &os, const set<T> &rhs) {\n    os << \"{\";\n    for (auto\
    \ itr = rhs.begin(); itr != rhs.end(); itr++) {\n        os << *itr << (next(itr)\
    \ != rhs.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\n\
    template<typename T> ostream &operator<<(ostream &os, const multiset<T> &rhs)\
    \ {\n    os << \"{\";\n    for (auto itr = rhs.begin(); itr != rhs.end(); itr++)\
    \ {\n        os << *itr << (next(itr) != rhs.end() ? \", \" : \"\");\n    }\n\
    \    os << \"}\";\n    return os;\n}\ntemplate<typename T, typename U> ostream\
    \ &operator<<(ostream &os, const map<T, U> &rhs) {\n    os << \"{\";\n    for\
    \ (auto itr = rhs.begin(); itr != rhs.end(); itr++) {\n        os << *itr << (next(itr)\
    \ != rhs.end() ? \", \" : \"\");\n    }\n    os << \"}\";\n    return os;\n}\n\
    struct setup {\n    static constexpr int PREC = 20;\n    setup() {\n        cout\
    \ << fixed << setprecision(PREC);\n        cerr << fixed << setprecision(PREC);\n\
    \    };\n} setup;\n\nsigned main() {\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2020-09-19 02:50:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: template.cpp
---
