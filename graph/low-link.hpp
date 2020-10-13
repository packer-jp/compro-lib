#include <vector>
#include <algorithm>

struct low_link {
    struct edge {
        int to, idx;
        edge(int to, int idx) : to(to), idx(idx) {}
    };
    int m = 0;
    std::vector<std::vector<edge>> adj;
    low_link(int n) : adj(n) {}
    int add_edge(int u, int v) {
        adj[u].emplace_back(v, m), adj[v].emplace_back(u, m);
        return m++;
    }
    std::pair<std::vector<int>, std::vector<int>> get() {
        int n = adj.size();
        std::vector<int> ord(n), low(n), articulations, bridges;
        std::vector<bool> visited(n);
        int k = 0;
        auto dfs = [&](auto &&dfs, int cur, int par) -> void {
            visited[cur] = true;
            ord[cur] = k++;
            low[cur] = ord[cur];
            int cnt = 0;
            bool is_articulation = false;
            for (auto[to, idx] : adj[cur]) {
                if (!visited[to]) {
                    cnt++;
                    dfs(dfs, to, cur);
                    low[cur] = std::min(low[cur], low[to]);
                    is_articulation |= ord[cur] <= low[to];
                    if (ord[cur] < low[to]) { bridges.emplace_back(idx); }
                } else if (to != par) { low[cur] = std::min(low[cur], ord[to]); }
            }
            if (par == -1) { is_articulation = cnt >= 2; }
            if (is_articulation) { articulations.emplace_back(cur); }
        };
        dfs(dfs, 0, -1);
        return {articulations, bridges};
    }
};