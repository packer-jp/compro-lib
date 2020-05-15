#include <vector>
#include <cassert>
#include <limits>

/*
 * @title セグメント木
 * @docs docs/data-structure/segment-tree.md
 */

template<typename M>
struct segment_tree {
    using T = typename M::T;
    int n;
    std::vector<T> data;
    segment_tree(int n) : n(n), data(n << 1, M::id()) {}
    segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = M::op(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void set(int i, const T &x) {
        assert(0 <= i && i < n);
        data[i += n] = x;
        while (i >>= 1) { data[i] = M::op(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    const T &operator[](int i) const { return data[i + n]; }
    T get_sum(int l, int r) const {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        T a = M::id(), b = M::id();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { a = M::op(a, data[l++]); }
            if (r & 1) { b = M::op(data[--r], b); }
        }
        return M::op(a, b);
    }
};

struct rsq {
    using T = int;
    static T op(T a, T b) { return a + b; }
    static T id() { return 0; }
};

struct rminq {
    using T = int;
    static T op(T a, T b) { return std::min(a, b); }
    static T id() { return std::numeric_limits<T>::max(); }
};