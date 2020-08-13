#include <vector>

/*
 * @title Union-Find木
 * @docs docs/data-structure/union-find-tree.md
 */

struct union_find_tree {
    std::vector<int> par, size;
    union_find_tree(int n) : par(n), size(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int get_root(int i) {
        if (par[i] == i) { return i; }
        else { return par[i] = get_root(par[i]); }
    }
    void unite(int i, int j) {
        if ((i = get_root(i)) == (j = get_root(j))) { return; }
        if (size[i] < size[j]) { std::swap(i, j); }
        par[j] = i;
        size[i] += size[j];
    }
    bool are_same(int i, int j) { return get_root(i) == get_root(j); }
    int get_size(int i) { return size[get_root(i)]; }
};