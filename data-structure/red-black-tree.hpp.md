---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/Volume15/RMQ-1.test.cpp
    title: test/AOJ/Volume15/RMQ-1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ITP2/Vector-1.test.cpp
    title: test/AOJ/ITP2/Vector-1.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data-structure/red-black-tree.hpp\"\n#include <vector>\n\
    \ntemplate<typename M>\nstruct red_black_tree {\n    enum COLOR { RED, BLACK };\n\
    \    using T = typename M::T;\n    struct node {\n        node *left, *right;\n\
    \        int color, level, size;\n        T val;\n        node() {}\n        node(T\
    \ val) : left(nullptr), right(nullptr), color(BLACK), level(0), size(1), val(val)\
    \ {}\n        node(node *left, node *right) : left(left), right(right), color(RED)\
    \ { update(); }\n        void update() {\n            if (!left) { return; }\n\
    \            level = left->level + (left->color == BLACK);\n            size =\
    \ left->size + right->size;\n            val = M::op(left->val, right->val);\n\
    \        }\n    };\n    node *root;\n    red_black_tree(node *root = nullptr)\
    \ : root(root) {}\n    int size() { return root ? root->size : 0; }\n    T get(int\
    \ idx) {\n        node *cur = root;\n        while (cur->left) {\n           \
    \ int size_l = cur->left->size;\n            if (idx < size_l) { cur = cur->left;\
    \ }\n            else { cur = cur->right, idx -= size_l; }\n        }\n      \
    \  return cur->val;\n    }\n    void merge(red_black_tree &right) {\n        if\
    \ (!root) {\n            root = right.root;\n            right.root = nullptr;\n\
    \            return;\n        }\n        if (!right.root) { return; }\n      \
    \  auto rotate = [](node *u, int d) -> node * {\n            node *v = d ? u->right\
    \ : u->left;\n            if (d) { u->right = v->left, v->left = u; }\n      \
    \      else { u->left = v->right, v->right = u; }\n            u->color = RED,\
    \ v->color = BLACK;\n            u->update(), v->update();\n            return\
    \ v;\n        };\n        auto merge_sub = [&](auto &&merge_sub, node *left, node\
    \ *right) -> node * {\n            if (left->level < right->level) {\n       \
    \         node *u = merge_sub(merge_sub, left, right->left);\n               \
    \ right->left = u, right->update();\n                if (right->color == BLACK\
    \ && u->color == RED && u->left->color == RED) {\n                    if (right->right->color\
    \ == BLACK) { return rotate(right, 0); }\n                    else {\n       \
    \                 right->color = RED, right->left->color = right->right->color\
    \ = BLACK;\n                        return right;\n                    }\n   \
    \             } else { return right; }\n            } else if (left->level > right->level)\
    \ {\n                node *u = merge_sub(merge_sub, left->right, right);\n   \
    \             left->right = u, left->update();\n                if (left->color\
    \ == BLACK && u->color == RED && u->right->color == RED) {\n                 \
    \   if (left->left->color == BLACK) { return rotate(left, 1); }\n            \
    \        else {\n                        left->color = RED, left->left->color\
    \ = left->right->color = BLACK;\n                        return left;\n      \
    \              }\n                } else { return left; }\n            } else\
    \ { return new node(left, right); }\n        };\n        (root = merge_sub(merge_sub,\
    \ root, right.root))->color = BLACK;\n        right.root = nullptr;\n    }\n \
    \   red_black_tree split(int size_l) {\n        if (size_l == 0) {\n         \
    \   node *right = root;\n            root = nullptr;\n            return right;\n\
    \        }\n        if (size_l == root->size) { return nullptr; }\n        root->left->color\
    \ = root->right->color = BLACK;\n        node *left = root->left;\n        red_black_tree\
    \ right = root->right;\n        delete root;\n        root = left;\n        if\
    \ (size_l < root->size) {\n            red_black_tree lr = split(size_l);\n  \
    \          lr.merge(right);\n            return lr;\n        } else {\n      \
    \      red_black_tree rr = right.split(size_l - root->size);\n            merge(right);\n\
    \            return rr;\n        }\n    }\n    void insert(int idx, T x) {\n \
    \       red_black_tree xt = new node(x), right = split(idx);\n        merge(xt),\
    \ merge(right);\n    }\n    void erase(int idx) {\n        red_black_tree xt =\
    \ split(idx);\n        red_black_tree right = xt.split(1);\n        delete xt.root;\n\
    \        merge(right);\n    }\n    T get_sum(int l, int r) {\n        red_black_tree\
    \ mid = split(l);\n        red_black_tree right = mid.split(r - l);\n        T\
    \ ret = mid.root->val;\n        merge(mid), merge(right);\n        return ret;\n\
    \    }\n};\n\nstruct int_rbt {\n    using T = int;\n    static T op(T a, T b)\
    \ { return std::min(a, b); }\n};\n"
  code: "#include <vector>\n\ntemplate<typename M>\nstruct red_black_tree {\n    enum\
    \ COLOR { RED, BLACK };\n    using T = typename M::T;\n    struct node {\n   \
    \     node *left, *right;\n        int color, level, size;\n        T val;\n \
    \       node() {}\n        node(T val) : left(nullptr), right(nullptr), color(BLACK),\
    \ level(0), size(1), val(val) {}\n        node(node *left, node *right) : left(left),\
    \ right(right), color(RED) { update(); }\n        void update() {\n          \
    \  if (!left) { return; }\n            level = left->level + (left->color == BLACK);\n\
    \            size = left->size + right->size;\n            val = M::op(left->val,\
    \ right->val);\n        }\n    };\n    node *root;\n    red_black_tree(node *root\
    \ = nullptr) : root(root) {}\n    int size() { return root ? root->size : 0; }\n\
    \    T get(int idx) {\n        node *cur = root;\n        while (cur->left) {\n\
    \            int size_l = cur->left->size;\n            if (idx < size_l) { cur\
    \ = cur->left; }\n            else { cur = cur->right, idx -= size_l; }\n    \
    \    }\n        return cur->val;\n    }\n    void merge(red_black_tree &right)\
    \ {\n        if (!root) {\n            root = right.root;\n            right.root\
    \ = nullptr;\n            return;\n        }\n        if (!right.root) { return;\
    \ }\n        auto rotate = [](node *u, int d) -> node * {\n            node *v\
    \ = d ? u->right : u->left;\n            if (d) { u->right = v->left, v->left\
    \ = u; }\n            else { u->left = v->right, v->right = u; }\n           \
    \ u->color = RED, v->color = BLACK;\n            u->update(), v->update();\n \
    \           return v;\n        };\n        auto merge_sub = [&](auto &&merge_sub,\
    \ node *left, node *right) -> node * {\n            if (left->level < right->level)\
    \ {\n                node *u = merge_sub(merge_sub, left, right->left);\n    \
    \            right->left = u, right->update();\n                if (right->color\
    \ == BLACK && u->color == RED && u->left->color == RED) {\n                  \
    \  if (right->right->color == BLACK) { return rotate(right, 0); }\n          \
    \          else {\n                        right->color = RED, right->left->color\
    \ = right->right->color = BLACK;\n                        return right;\n    \
    \                }\n                } else { return right; }\n            } else\
    \ if (left->level > right->level) {\n                node *u = merge_sub(merge_sub,\
    \ left->right, right);\n                left->right = u, left->update();\n   \
    \             if (left->color == BLACK && u->color == RED && u->right->color ==\
    \ RED) {\n                    if (left->left->color == BLACK) { return rotate(left,\
    \ 1); }\n                    else {\n                        left->color = RED,\
    \ left->left->color = left->right->color = BLACK;\n                        return\
    \ left;\n                    }\n                } else { return left; }\n    \
    \        } else { return new node(left, right); }\n        };\n        (root =\
    \ merge_sub(merge_sub, root, right.root))->color = BLACK;\n        right.root\
    \ = nullptr;\n    }\n    red_black_tree split(int size_l) {\n        if (size_l\
    \ == 0) {\n            node *right = root;\n            root = nullptr;\n    \
    \        return right;\n        }\n        if (size_l == root->size) { return\
    \ nullptr; }\n        root->left->color = root->right->color = BLACK;\n      \
    \  node *left = root->left;\n        red_black_tree right = root->right;\n   \
    \     delete root;\n        root = left;\n        if (size_l < root->size) {\n\
    \            red_black_tree lr = split(size_l);\n            lr.merge(right);\n\
    \            return lr;\n        } else {\n            red_black_tree rr = right.split(size_l\
    \ - root->size);\n            merge(right);\n            return rr;\n        }\n\
    \    }\n    void insert(int idx, T x) {\n        red_black_tree xt = new node(x),\
    \ right = split(idx);\n        merge(xt), merge(right);\n    }\n    void erase(int\
    \ idx) {\n        red_black_tree xt = split(idx);\n        red_black_tree right\
    \ = xt.split(1);\n        delete xt.root;\n        merge(right);\n    }\n    T\
    \ get_sum(int l, int r) {\n        red_black_tree mid = split(l);\n        red_black_tree\
    \ right = mid.split(r - l);\n        T ret = mid.root->val;\n        merge(mid),\
    \ merge(right);\n        return ret;\n    }\n};\n\nstruct int_rbt {\n    using\
    \ T = int;\n    static T op(T a, T b) { return std::min(a, b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/red-black-tree.hpp
  requiredBy: []
  timestamp: '2020-09-23 16:37:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/Volume15/RMQ-1.test.cpp
  - test/AOJ/ITP2/Vector-1.test.cpp
documentation_of: data-structure/red-black-tree.hpp
layout: document
title: "\u8D64\u9ED2\u6728"
---

