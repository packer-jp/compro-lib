#include <vector>

template<typename T>
struct weighted_union_find_tree {
    T zero;
    std::vector<int> par, size;
    std::vector<T> weight;
    weighted_union_find_tree(int n, T zero = T()) : zero(zero), par(n), size(n, 1), weight(n, zero) {
        for (int i = 0; i < n; i++) { par[i] = i; }
    }
    int get_root(int i) {
        if (par[i] == i) { return i; }
        else {
            int r = get_root(par[i]);
            weight[i] += weight[par[i]];
            return par[i] = r;
        }
    }
    T get_weight(int i) {
        get_root(i);
        return weight[i];
    }
    T get_diff(int i, int j) { return get_weight(j) - get_weight(i); }
    void unite(int i, int j, T d) {
        d -= get_diff(i, j);
        i = get_root(i);
        j = get_root(j);
        if (i == j) { return; }
        if (size[i] < size[j]) { std::swap(i, j), d = -d; }
        par[j] = i;
        size[i] += size[j];
        weight[j] = d;
    }
    bool are_same(int i, int j) { return get_root(i) == get_root(j); }
    int get_size(int i) { return size[get_root(i)]; }
};