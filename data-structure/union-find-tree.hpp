#include <vector>

template<typename S>
struct union_find_tree {
    using T = typename S::T;
    std::vector<int> parent, size_;
    std::vector<T> val;
    union_find_tree(const std::vector<T> &val) : parent(val.size(), -1), size_(val.size(), 1), val(val) {}
    union_find_tree(int n) : union_find_tree(std::vector<T>(n, S::initial())) {}
    int root(int i) {
        if (parent[i] == -1) { return i; }
        else { return parent[i] = root(parent[i]); }
    }
    void unite(int i, int j) {
        if ((i = root(i)) == (j = root(j))) { return; }
        if (size_[i] < size_[j]) { std::swap(i, j); }
        size_[i] += size_[j];
        val[i] = S::op(val[i], val[j]);
        parent[j] = i;
    }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return size_[root(i)]; }
    void set(int i, const T &x) { val[root(i)] = x; }
    T operator[](int i) { return val[root(i)]; }
};

struct normal_uf {
    struct T {};
    static T initial() { return {}; }
    static T op(const T &a, const T &b) { return {}; }
};