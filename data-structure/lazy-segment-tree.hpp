#include <cassert>
#include <limits>
#include <vector>

template <typename S> struct lazy_segment_tree {
    using T = typename S::T;
    using E = typename S::E;
    int n;
    std::vector<T> data;
    std::vector<E> lazy;
    lazy_segment_tree(int n) : n(n), data(n << 1, S::id_T()), lazy(n << 1, S::id_E()) {
    }
    lazy_segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1), lazy(n << 1, S::id_E()) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = S::op_TT(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    void propagate(int i) {
        if (i < 1) {
            return;
        }
        data[i] = S::op_TE(data[i], lazy[i]);
        if (i < n) {
            lazy[i << 1 | 0] = S::op_EE(lazy[i << 1 | 0], lazy[i]);
            lazy[i << 1 | 1] = S::op_EE(lazy[i << 1 | 1], lazy[i]);
        }
        lazy[i] = S::id_E();
    }
    void apply(int l, int r, const E &x) {
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i);
            propagate(r >> i);
        }
        auto update = [&](int i) { lazy[i] = S::op_EE(lazy[i], x), propagate(i); };
        for (int i = l, j = r + 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1) {
                update(i++);
            }
            if (j & 1) {
                update(--j);
            }
        }
        while (l >>= 1, r >>= 1) {
            data[l] =
                S::op_TT(S::op_TE(data[l << 1 | 0], lazy[l << 1 | 0]), S::op_TE(data[l << 1 | 1], lazy[l << 1 | 1]));
            data[r] =
                S::op_TT(S::op_TE(data[r << 1 | 0], lazy[r << 1 | 0]), S::op_TE(data[r << 1 | 1], lazy[r << 1 | 1]));
        }
    }
    T fold(int l, int r) {
        l += n, r += n - 1;
        for (int i = std::__lg(r); i > 0; i--) {
            propagate(l >> i), propagate(r >> i);
        }
        T a = S::id_T(), b = S::id_T();
        for (r++; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                propagate(l), a = S::op_TT(a, data[l++]);
            }
            if (r & 1) {
                propagate(--r), b = S::op_TT(data[r], b);
            }
        }
        return S::op_TT(a, b);
    }
};

struct rminq_and_ruq {
    using T = int;
    using E = int;
    static T id_T() {
        return std::numeric_limits<T>::max();
    };
    static E id_E() {
        return -1;
    };
    static T op_TT(const T &a, const T &b) {
        return std::min(a, b);
    }
    static E op_EE(const E &a, const E &b) {
        return b == id_E() ? a : b;
    }
    static T op_TE(const T &a, const E &b) {
        return b == id_E() ? a : b;
    }
};

struct rsq_and_raq {
    using T = std::pair<long long, int>;
    using E = long long;
    static T id_T() {
        return {0, 0};
    };
    static E id_E() {
        return 0;
    };
    static T op_TT(const T &a, const T &b) {
        return {a.first + b.first, a.second + b.second};
    }
    static E op_EE(const E &a, const E &b) {
        return a + b;
    }
    static T op_TE(const T &a, const E &b) {
        return {a.first + b * a.second, a.second};
    }
};

struct rminq_and_raq {
    using T = long long;
    using E = long long;
    static T id_T() {
        return std::numeric_limits<T>::max();
    };
    static E id_E() {
        return 0;
    };
    static T op_TT(const T &a, const T &b) {
        return std::min(a, b);
    }
    static E op_EE(const E &a, const E &b) {
        return a + b;
    }
    static T op_TE(const T &a, const E &b) {
        return a + b;
    }
};