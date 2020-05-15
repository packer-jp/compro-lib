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
    void add(int i, const T &x) {
        assert(0 <= i && i < n);
        for (i++; i <= n; i += i & -i) { data[i] = M::op(data[i], x); }
    }
    T get_sum(int i) const {
        assert(0 < i && i <= n);
        T ret = M::id();
        for (; i > 0; i -= i & -i) { ret = M::op(ret, data[i]); }
        return ret;
    }
    T get_sum(int l, int r) const {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        return M::op(get_sum(r), M::inv(get_sum(l)));
    }
};

template<typename M>
struct fenwick_tree_range {
    using T = typename M::T;
    fenwick_tree<M> ft;
    fenwick_tree_range(int n) : ft(n + 1) {}
    void add(int l, int r, const T &x) { ft.add(l, x), ft.add(r, -x); }
    T operator[](int i) const { return ft.get_sum(i + 1); }
};

struct rsq {
    using T = int;
    static T id() { return 0; }
    static T op(const T &a, const T &b) { return a + b; }
    static T inv(const T &a) { return -a; }
};