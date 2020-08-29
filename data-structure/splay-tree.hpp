#include <vector>

/*
 * @title Splay木
 * @docs docs/data-structure/splay-tree.md
 */

template<typename M>
struct splay_tree {
    using T = typename M::T;
    struct node {
        node *left, *right, *par;
        int size;
        T val, res;
        node() {}
        node(T val) : left(nullptr), right(nullptr), par(nullptr), size(1), val(val), res(val) {}
        void rotate() {
            node *p, *pp, *c;
            p = par, pp = p->par;
            if (p->left == this) { c = right, right = p, p->left = c; }
            else { c = left, left = p, p->right = c; }
            if (pp) {
                if (pp->left == p) { pp->left = this; }
                else { pp->right = this; }
            }
            if (c) { c->par = p; }
            par = pp, p->par = this;
            p->update();
            update();
        }
        int state() {
            if (!par) { return 0; }
            if (par->left == this) { return 1; }
            else { return -1; }
        }
        void splay() {
            while (state() != 0) {
                if (par->state() == 0) { rotate(); }
                else if (state() == par->state()) { par->rotate(), rotate(); }
                else { rotate(), rotate(); }
            }
        }
        void update() {
            size = 1, res = val;
            if (left) { size += left->size, res = M::op(left->res, res); }
            if (right) { size += right->size, res = M::op(res, right->res); }
        }
    };
    node *root;
    splay_tree(node *root = nullptr) : root(root) {}
    int size() {
        if (!root) { return 0; }
        return root->size;
    }
    node *get_node(int idx) {
        node *cur = root;
        while (true) {
            int size_l = cur->left ? cur->left->size : 0;
            if (idx < size_l) { cur = cur->left; }
            if (idx == size_l) {
                cur->splay();
                return root = cur;
            }
            if (idx > size_l) { cur = cur->right, idx -= size_l + 1; }
        }
    }
    T get(int idx) { return get_node(idx)->val; }
    int lower_bound(T x) {
        if (!root) { return 0; }
        node *cur = root;
        int ret = cur->left ? cur->left->size : 0;
        while (true) {
            if (M::gr(x, cur->val)) {
                if (cur->right) {
                    cur = cur->right;
                    ret += cur->left ? cur->left->size : 0;
                } else {
                    cur->splay(), root = cur;
                    return ret + 1;
                }
            } else {
                if (cur->left) {
                    cur = cur->left;
                    ret -= cur->right ? cur->right->size + 1 : 1;
                } else {
                    cur->splay(), root = cur;
                    return ret;
                }
            }
        }
    }
    splay_tree split(int size_left) {
        if (size_left == 0) {
            node *root_r = root;
            root = nullptr;
            return root_r;
        }
        if (size_left == root->size) { return nullptr; }
        node *root_r = get_node(size_left);
        root = root_r->left;
        root_r->left = nullptr, root->par = nullptr;
        root_r->update();
        return root_r;
    }
    void merge(splay_tree right) {
        if (!root) {
            root = right.root;
            return;
        }
        if (!right.root) { return; }
        get_node(root->size - 1);
        root->right = right.root, right.root->par = root;
        root->update();
    }
    void insert(int idx, T x) {
        splay_tree xt = new node(x), right = split(idx);
        merge(xt), merge(right);
    }
    void erase(int idx) {
        splay_tree right = split(idx).split(1);
        merge(right);
    }
    T get_sum(int l, int r) {
        splay_tree mid = split(l);
        splay_tree right = mid.split(r - l);
        T ret = mid.root->res;
        merge(mid), merge(right);
        return ret;
    }
};

struct int_st {
    using T = int;
    static T op(T a, T b) { return std::min(a, b); }
    static bool gr(const T &a, const T &b) { return a > b; }
};