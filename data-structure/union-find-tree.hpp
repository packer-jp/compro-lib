#include <vector>

template<typename S>
struct union_find_tree {
    using T = typename S::T;
    std::vector<int> par, sz;
    std::vector<T> val;
    union_find_tree(const std::vector<T> &val) : par(val.size(), -1), sz(val.size(), 1), val(val) {}
    union_find_tree(int n, const T &x = {}) : union_find_tree(std::vector<T>(n, x)) {}
    int root(int i) {
        if (par[i] == -1) { return i; }
        else { return par[i] = root(par[i]); }
    }
    void unite(int i, int j) {
        if ((i = root(i)) == (j = root(j))) { return; }
        if (sz[i] < sz[j]) { std::swap(i, j); }
        sz[i] += sz[j];
        S::merge(val[i], val[j]);
        par[j] = i;
    }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return sz[root(i)]; }
    T &operator[](int i) { return val[root(i)]; }
};

struct normal_uf {
    struct T {};
    static void merge(T &a, const T &b) {}
};