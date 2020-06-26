#include <vector>

/*
 * @title 二部最大マッチング
 * @docs docs/graph/bipartite-matching.md
 */

std::vector<std::pair<int, int>> bipartite_matching(const std::vector<std::vector<int>> &adj) {
    int n = adj.size();
    std::vector<int> match(n, -1), used(n);
    int timestamp = 0;
    auto dfs = [&](auto &&self, int v) -> bool {
        used[v] = timestamp;
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i], w = match[u];
            if (w < 0 || (used[w] != timestamp && self(self, w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    };
    for (int i = 0; i < n; i++) {
        if (match[i] < 0) {
            timestamp++;
            dfs(dfs, i);
        }
    }
    std::vector<std::pair<int, int>> ret;
    for (int i = 0; i < n; i++) {
        if (i < match[i]) { ret.push_back({i, match[i]}); }
    }
    return ret;
}