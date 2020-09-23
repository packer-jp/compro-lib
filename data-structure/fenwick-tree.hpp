#include <vector>
#include <cassert>

template<typename S>
struct fenwick_tree {
    using T = typename S::T;
    int n;
    std::vector<T> data;
    fenwick_tree(int n) : n(n), data(n + 1, S::zero()) {}
    void add(int i, const T &x) {
        for (i++; i <= n; i += i & -i) { data[i] = S::plus(data[i], x); }
    }
    T sum(int i) const {
        T ret = S::zero();
        for (; i > 0; i -= i & -i) { ret = S::plus(ret, data[i]); }
        return ret;
    }
    T sum(int l, int r) const { return S::plus(S::minus(sum(l)), sum(r)); }
};

template<typename S>
struct fenwick_tree_range : public fenwick_tree<S> {
    using F = fenwick_tree<S>;
    using T = typename S::T;
    fenwick_tree_range(int n) : F(n) {}
    void add(int l, int r, const T &x) { F::add(l, x), F::add(r, S::minus(x)); }
    T operator[](int i) const { return F::sum(i + 1); }
};

struct rsq {
    using T = int;
    static T zero() { return 0; }
    static T plus(const T &a, const T &b) { return a + b; }
    static T minus(const T &a) { return -a; }
};
