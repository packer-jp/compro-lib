#include <vector>
#include <algorithm>

/*
 * @title LowLink
 * @docs docs/graph/low-link.md
 */

struct low_link {
    int n;
    std::vector<int> ord, low, articulations;
    std::vector<std::vector<int>> adj;
    std::vector<std::pair<int, int>> bridges;
    low_link(const std::vector<std::vector<int>> &adj) : n(adj.size()), adj(adj), ord(n), low(n) {
        std::vector<bool> visited(n);
        int k = 0;
        auto dfs = [&](auto &&self, int cur, int par) -> void {
            visited[cur] = true;
            ord[cur] = k++;
            low[cur] = ord[cur];
            int cnt = 0;
            bool is_articulation = false;
            for (int to : adj[cur]) {
                if (!visited[to]) {
                    cnt++;
                    self(self, to, cur);
                    low[cur] = std::min(low[cur], low[to]);
                    is_articulation |= ord[cur] <= low[to];
                    if (ord[cur] < low[to]) { bridges.emplace_back(std::minmax(cur, to)); }
                } else if (to != par) { low[cur] = std::min(low[cur], ord[to]); }
            }
            if (par == -1) { is_articulation = cnt >= 2; }
            if (is_articulation) { articulations.emplace_back(cur); }
        };
        dfs(dfs, 0, -1);
    }
};