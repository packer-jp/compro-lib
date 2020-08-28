#include <vector>

/*
 * @title 赤黒木
 * @docs docs/data-structure/red-black-tree.md
 */

template<typename M>
struct red_black_tree {
    enum COLOR { RED, BLACK };
    using T = typename M::T;
    struct node {
        node *left, *right;
        int color, level, size;
        T val;
        node() {}
        node(T val) : left(nullptr), right(nullptr), color(BLACK), level(0), size(1), val(val) {}
        node(node *left, node *right) : left(left), right(right), color(RED) { update(); }
        void update() {
            if (!left) { return; }
            level = left->level + (left->color == BLACK);
            size = left->size + right->size;
            val = M::op(left->val, right->val);
        }
    };
    node *root;
    red_black_tree(node *root = nullptr) : root(root) {}
    int size() { return root ? root->size : 0; }
    T get(int idx) {
        node *cur = root;
        while (cur->left) {
            int size_l = cur->left->size;
            if (idx < size_l) { cur = cur->left; }
            else { cur = cur->right, idx -= size_l; }
        }
        return cur->val;
    }
    void merge(red_black_tree &right) {
        if (!root) {
            root = right.root;
            right.root = nullptr;
            return;
        }
        if (!right.root) { return; }
        auto rotate = [](node *u, int d) -> node * {
            node *v = d ? u->right : u->left;
            if (d) { u->right = v->left, v->left = u; }
            else { u->left = v->right, v->right = u; }
            u->color = RED, v->color = BLACK;
            u->update(), v->update();
            return v;
        };
        auto merge_sub = [&](auto &&merge_sub, node *left, node *right) -> node * {
            if (left->level < right->level) {
                node *u = merge_sub(merge_sub, left, right->left);
                right->left = u, right->update();
                if (right->color == BLACK && u->color == RED && u->left->color == RED) {
                    if (right->right->color == BLACK) { return rotate(right, 0); }
                    else {
                        right->color = RED, right->left->color = right->right->color = BLACK;
                        return right;
                    }
                } else { return right; }
            } else if (left->level > right->level) {
                node *u = merge_sub(merge_sub, left->right, right);
                left->right = u, left->update();
                if (left->color == BLACK && u->color == RED && u->right->color == RED) {
                    if (left->left->color == BLACK) { return rotate(left, 1); }
                    else {
                        left->color = RED, left->left->color = left->right->color = BLACK;
                        return left;
                    }
                } else { return left; }
            } else { return new node(left, right); }
        };
        (root = merge_sub(merge_sub, root, right.root))->color = BLACK;
        right.root = nullptr;
    }
    red_black_tree split(int size_l) {
        if (size_l == 0) {
            node *right = root;
            root = nullptr;
            return right;
        }
        if (size_l == root->size) { return nullptr; }
        root->left->color = root->right->color = BLACK;
        node *left = root->left;
        red_black_tree right = root->right;
        delete root;
        root = left;
        if (size_l < root->size) {
            red_black_tree lr = split(size_l);
            lr.merge(right);
            return lr;
        } else {
            red_black_tree rr = right.split(size_l - root->size);
            merge(right);
            return rr;
        }
    }
    void insert(int idx, T x) {
        red_black_tree xt = new node(x), right = split(idx);
        merge(xt), merge(right);
    }
    void erase(int idx) {
        red_black_tree right = split(idx).split(1);
        merge(right);
    }
    T get_sum(int l, int r) {
        red_black_tree mid = split(l);
        red_black_tree right = mid.split(r - l);
        T ret = mid.root->val;
        merge(mid), merge(right);
        return ret;
    }
};

struct int_rbt {
    using T = int;
    static T op(T a, T b) { return std::min(a, b); }
};