template<typename M>
struct splay_tree {
    using T = typename M::T;
    struct node {
        node *left, *right, *parent;
        int size;
        T value;
        node() : left(nullptr), right(nullptr), parent(nullptr), size(1) {}
        void rotate() {
            node *p, *pp, *c;
            p = parent, pp = p->parent;
            if (p->left == this) { c = right, right = p, p->left = c; }
            else { c = left, left = p, p->right = c; }
            if (pp) {
                if (pp->left == p) { pp->left = this; }
                else { pp->right = this; }
            }
            if (c) { c->parent = p; }
            parent = pp, p->parent = this;
            p->update();
            update();
        }
        void splay() {}
        void update() {
            size = 1;
            if (left) { size += left->size(); }
            if (right) { size += right->size(); }
        }
    };
};

struct int_st {
    using T = int;
};