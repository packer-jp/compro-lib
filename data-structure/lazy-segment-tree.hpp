#include <vector>
#include <cassert>
#include <limits>

/*
 * @title 遅延評価セグメント木
 * @docs docs/data-structure/lazy-segment-tree.md
 */

template<typename M>
struct lazy_segment_tree {
    using T = typename M::T;
    using E = typename M::E;
    int n;
    std::vector<T> data;
    std::vector<E> lazy;
    lazy_segment_tree(int n) : n(n), data(n << 1, M::id_T()), lazy(n << 1, M::id_E()) {}
    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, M::id_E()) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = M::op_TT(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void propagate(int i) {
        if (i < 1) { return; }
        data[i] = M::op_TE(data[i], lazy[i], i >= n ? 1 : 2 << std::__lg((n - 1) / i));
        if (i < n) {
            lazy[i << 1 | 0] = M::op_EE(lazy[i << 1 | 0], lazy[i]);
            lazy[i << 1 | 1] = M::op_EE(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = M::id_E();
    }
    void add(int l, int r, const E &x) {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
        static auto apply = [&](int i) { lazy[i] = M::op_EE(lazy[i], x), propagate(i); };
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) { apply(i++); }
            if (j & 1) { apply(--j); }
        }
        for (int i = 1; l >>= 1, r >>= 1; i <<= 1) {
            data[l] = M::op_TT(M::op_TE(data[l << 1 | 0], lazy[l << 1 | 0], i),
                               M::op_TE(data[l << 1 | 1], lazy[l << 1 | 1], i));
            data[r] = M::op_TT(M::op_TE(data[r << 1 | 0], lazy[r << 1 | 0], i),
                               M::op_TE(data[r << 1 | 1], lazy[r << 1 | 1], i));
        }
    }
    T get_sum(int l, int r) {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) { propagate(l >> i), propagate(r >> i); }
        T a = M::id_T(), b = M::id_T();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { propagate(l), a = op_TT(a, data[l++]); }
            if (r & 1) { propagate(--r), b = op_TT(data[r], b); }
        }
        return M::op_TT(a, b);
    }
};

struct rminq_and_ruq {
    using T = int;
    using E = int;
    static T id_T() { return std::numeric_limits<T>::max(); };
    static E id_E() { return -1; };
    static T op_TT(const T &a, const T &b) { return std::min(a, b); }
    static E op_EE(const T &a, const T &b) { return b == id_E() ? a : b; }
    static T op_TE(const T &a, const T &b, int) { return b == id_E() ? a : b; }
};

struct rsq_and_raq {
    using T = int;
    using E = int;
    static T id_T() { return 0; };
    static E id_E() { return 0; };
    static T op_TT(const T &a, const T &b) { return a + b; }
    static E op_EE(const T &a, const T &b) { return a + b; }
    static T op_TE(const T &a, const T &b, int c) { return a + b * c; }
};