#include <vector>

/*
 * @title to Rooted Tree
 * @docs docs/graph/to-rooted-tree.md
 */

std::vector<int> to_rooted_tree(const std::vector<std::vector<int>> &adj, int s) {
    std::vector<int> ret;
    static auto dfs = [&](auto &&self, int cur, int par) -> void {
        ret[cur] = par;
        for (int i = 0; i < adj[cur].size(); i++) {
            if (adj[cur][i] == par) { continue; }
            self(self, adj[cur][i], cur);
        }
    };
    dfs(dfs, s, -1);
    return ret;
}