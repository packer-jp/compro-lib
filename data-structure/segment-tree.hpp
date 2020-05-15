#include <vector>
#include <cassert>
#include <limits>

/*
 * @title セグメント木
 * @docs docs/data-structure/segment-tree.md
 */

template<class T, T(*OP)(T, T), T (*ID)()>
struct segment_tree {
    int n;
    std::vector<T> data;
    segment_tree(int n) : n(n), data(n << 1, ID()) {}
    segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) { data[i] = OP(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    void set(int i, const T &x) {
        assert(0 <= i && i < n);
        data[i += n] = x;
        while (i >>= 1) { data[i] = OP(data[i << 1 | 0], data[i << 1 | 1]); }
    }
    T operator[](int i) const { return data[i + n]; }
    T get_sum(int l, int r) const {
        assert(0 <= l && l < n);
        assert(0 < r && r <= n);
        T a = ID(), b = ID();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) { a = OP(a, data[l++]); }
            if (r & 1) { b = OP(data[--r], b); }
        }
        return OP(a, b);
    }
};

struct rminq {
    using T = long long;
    static T OP(T a, T b) { return a + b; }
    static T ID() { return 0; }
    using type = segment_tree<T, OP, ID>;
};

struct rsq {
    using T = long long;
    static T OP(T a, T b) { return std::min(a, b); }
    static T ID() { return std::numeric_limits<T>::max(); }
    using type = segment_tree<T, OP, ID>;
};