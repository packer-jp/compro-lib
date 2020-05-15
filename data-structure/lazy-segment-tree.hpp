#include <vector>
#include <cassert>
#include <limits>

/*
 * @title 遅延評価セグメント木
 * @docs docs/data-structure/lazy-segment-tree.md
 */

template<typename T, typename E, T(*OP_TT)(T, T), E(*OP_EE)(E, E), T(*OP_TE)(T, E, int), T(*ID_T)(), E(*ID_E)()>
struct lazy_segment_tree {
    int n;
    std::vector<T> data;
    std::vector<E> lazy;
    lazy_segment_tree(int n) : n(n), data(n << 1, ID_T()), lazy(n << 1, ID_E()) {}
    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, ID_E()) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = OP_TT(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void propagate(int i) {
        if (i < 1) { return; }
        data[i] = OP_TE(data[i], lazy[i], i >= n ? 1 : 2 << std::__lg((n - 1) / i));
        if (i < n) {
            lazy[i << 1 | 0] = OP_EE(lazy[i << 1 | 0], lazy[i]);
            lazy[i << 1 | 1] = OP_EE(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = ID_E();
    }
    void add(int l, int r, const E &x) {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
        static auto apply = [&](int i) { lazy[i] = OP_EE(lazy[i], x), propagate(i); };
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) { apply(i++); }
            if (j & 1) { apply(--j); }
        }
        for (int i = 1; l >>= 1, r >>= 1; i <<= 1) {
            data[l] = OP_TT(OP_TE(data[l << 1 | 0], lazy[l << 1 | 0], i), OP_TE(data[l << 1 | 1], lazy[l << 1 | 1], i));
            data[r] = OP_TT(OP_TE(data[r << 1 | 0], lazy[r << 1 | 0], i), OP_TE(data[r << 1 | 1], lazy[r << 1 | 1], i));
        }
    }
    T get_sum(int l, int r) {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) { propagate(l >> i), propagate(r >> i); }
        T a = ID_T(), b = ID_T();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { propagate(l), a = OP_TT(a, data[l++]); }
            if (r & 1) { propagate(--r), b = OP_TT(data[r], b); }
        }
        return OP_TT(a, b);
    }
};

struct rminq_and_ruq {
    using T = long long;
    using E = long long;
    static T ID_T() { return std::numeric_limits<T>::max(); };
    static E ID_E() { return -1; };
    static T OP_TT(T a, T b) { return std::min(a, b); }
    static E OP_EE(T a, T b) { return b == ID_E() ? a : b; }
    static T OP_TE(T a, T b, int c) { return b == ID_E() ? a : b; }
    using type = lazy_segment_tree<T, E, OP_TT, OP_EE, OP_TE, ID_T, ID_E>;
};

struct rsq_and_raq {
    using T = long long;
    using E = long long;
    static T ID_T() { return 0; };
    static E ID_E() { return 0; };
    static T OP_TT(T a, T b) { return a + b; }
    static E OP_EE(T a, T b) { return a + b; }
    static T OP_TE(T a, T b, int c) { return a + b * c; }
    using type = lazy_segment_tree<T, E, OP_TT, OP_EE, OP_TE, ID_T, ID_E>;
};