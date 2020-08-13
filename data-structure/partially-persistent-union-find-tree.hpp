#include <vector>
#include <climits>

/*
 * @title 部分永続Union-Find木
 * @docs docs/data-structure/partially-persistent-union-find-tree.md
 */

struct partially_persistent_union_find_tree {
    int now = 0;
    std::vector<int> parent, time;
    std::vector<std::vector<std::pair<int, int>>> size;
    partially_persistent_union_find_tree(int n)
        : parent(n), time(n), size(n, std::vector<std::pair<int, int>>(0)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i].push_back(std::make_pair(0, 1));
            time[i] = INT_MAX;
        }
    }
    int get_root(int i, int t) {
        if (t < time[i]) { return i; }
        else { return get_root(parent[i], t); }
    }
    void unite(int i, int j) {
        now++;
        if ((i = get_root(i, now)) == (j = get_root(j, now))) { return; }
        int si = get_size(i, now), sj = get_size(j, now);
        if (si < sj) { std::swap(i, j); }
        size[i].push_back(std::make_pair(now, si + sj));
        parent[j] = i;
        time[j] = now;
    }
    bool are_same(int i, int j, int t) { return get_root(i, t) == get_root(j, t); }
    int get_size(int i, int t) {
        i = get_root(i, t);
        int lb = 0, ub = size[i].size();
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (size[i][mid].first <= t) { lb = mid; }
            else { ub = mid; }
        }
        return size[i][lb].second;
    }
};