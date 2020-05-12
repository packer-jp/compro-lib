#include <vector>
#include <cassert>

/*
 * @title Fenwick木
 * @docs docs/data-structure/fenwick-tree.md
 */

template<typename T>
struct fenwick_tree {
    int n;
    std::vector<T> data;
    fenwick_tree(int n) : n(n), data(n + 1, 0) {}
    void add(int i, T x) {
        assert(0 <= i && i < n);
        for (i++; i <= n; i += i & -i) { data[i] += x; }
    }
    T get_sum(int i) const {
        assert(0 < i && i <= n);
        T ret = 0;
        for (; i > 0; i -= i & -i) { ret += data[i]; }
        return ret;
    }
    T get_sum(int l, int r) const {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        return get_sum(r) - get_sum(l);
    }
};

template<typename T>
struct fenwick_tree_range {
    fenwick_tree<T> ft;
    fenwick_tree_range(int n) : ft(fenwick_tree<T>(n + 1)) {}
    void add(int l, int r, T x) { ft.add(l, x), ft.add(r, -x); }
    T operator[](int i) const { return ft.get_sum(i + 1); }
};