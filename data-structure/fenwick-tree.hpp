#include <vector>
#include <cassert>

/*
 * @title Fenwick木
 * @docs docs/data-structure/fenwick-tree.md
 */

template<typename M>
struct fenwick_tree {
    using T = typename M::T;
    int n;
    std::vector<T> data;
    fenwick_tree(int n) : n(n), data(n + 1, M::id()) {}
    void apply(int i, const T &x) {
        for (i++; i <= n; i += i & -i) { data[i] = M::op(data[i], x); }
    }
    T fold(int i) const {
        T ret = M::identity();
        for (; i > 0; i -= i & -i) { ret = M::op(ret, data[i]); }
        return ret;
    }
    T fold(int l, int r) const { return M::op(fold(r), M::inv(fold(l))); }
};

template<typename M>
struct fenwick_tree_range : public fenwick_tree<M> {
    using S = fenwick_tree<M>;
    using T = typename M::T;
    fenwick_tree_range(int n) { S::fenwick_tree(n); }
    void apply(int l, int r, const T &x) { S::apply(l, x), S::apply(r, -x); }
    T operator[](int i) const { return S::fold(i + 1); }
};

struct rsq {
    using T = int;
    static T id() { return 0; }
    static T op(const T &a, const T &b) { return a + b; }
    static T inv(const T &a) { return -a; }
};
