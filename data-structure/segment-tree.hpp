#include <cassert>
#include <limits>
#include <vector>

/**
 * @brief Segment 木
 * @tparam S 代数的構造。
 */
template <typename S> struct segment_tree {
    using T = typename S::T;
    int n;
    std::vector<T> data;
    segment_tree(int n) : n(n), data(n << 1, S::id()) {
    }
    segment_tree(const std::vector<T> &src) : n(src.size()), data(n << 1) {
        std::copy(src.begin(), src.end(), data.begin() + n);
        for (int i = n - 1; i > 0; i--) {
            data[i] = S::op(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    /**
     * @brief 一点変更
     * @arg i インデックス。
     * @arg x 置き換え先。
     **/
    void set(int i, const T &x) {
        data[i += n] = x;
        while (i >>= 1) {
            data[i] = S::op(data[i << 1 | 0], data[i << 1 | 1]);
        }
    }
    /**
     * @brief 一点取得
     * @arg i インデックス。
     **/
    const T &operator[](int i) const {
        return data[i + n];
    }
    T fold(int l, int r) const {
        T a = S::id(), b = S::id();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                a = S::op(a, data[l++]);
            }
            if (r & 1) {
                b = S::op(data[--r], b);
            }
        }
        return S::op(a, b);
    }
};

struct rsq {
    using T = int;
    static T op(const T &a, const T &b) {
        return a + b;
    }
    static T id() {
        return 0;
    }
};

struct rminq {
    using T = int;
    static T op(const T &a, const T &b) {
        return std::min(a, b);
    }
    static T id() {
        return std::numeric_limits<T>::max();
    }
};
