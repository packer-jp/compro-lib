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
    static std::vector<node> nodes;
    static int vecsize;
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
                return cur;
            }
            if (idx > size_l) { cur = cur->right, idx -= size_l + 1; }
        }
    }
    T get(int idx) { return (root = get_node(idx))->val; }
    void merge(splay_tree right) {
        if (!root) {
            root = right.root;
            return;
        }
        if (!right.root) { return; }
        root = get_node(root->size - 1);
        root->right = right.root, right.root->par = root;
        root->update();
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
    void insert(int idx, T x) {
        nodes[vecsize++] = x;
        splay_tree right = split(idx);
        merge(&nodes[vecsize - 1]), merge(right);
    }
    void erase(int idx) {
        splay_tree right = split(idx).split(1);
        merge(right);
    }
    /*
    void display(node *root) {
        if (root->left) { display(root->left); }
        cerr << root->val << " ";
        if (root->right) { display(root->right); }
    }
    void display() {
        cerr << "st : ";
        if (root) { display(root); }
        cerr << endl;
    }
    */

};

struct int_st {
    using T = int;
    static T op(T a, T b) { return std::min(a, b); }
};
template<> std::vector<splay_tree<int_st>::node> splay_tree<int_st>::nodes(220000);
template<> int splay_tree<int_st>::vecsize(0);