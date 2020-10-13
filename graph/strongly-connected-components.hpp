#include <vector>

struct strongly_connected_components {
    std::vector<std::vector<int>> adj;
    strongly_connected_components(int n) : adj(n) {}
    void add_edge(int from, int to) { adj[from].emplace_back(to); }
    std::vector<int> get() {
        int n = adj.size();
        std::vector<int> vs;
        std::vector<bool> visited0(n);
        auto dfs0 = [&](auto &&dfs0, int cur) -> void {
            if (visited0[cur]) { return; }
            visited0[cur] = true;
            for (int i = 0; i < adj[cur].size(); i++) { dfs0(dfs0, adj[cur][i]); }
            vs.push_back(cur);
        };
        for (int i = 0; i < n; i++) { dfs0(dfs0, i); }
        std::vector<std::vector<int>> radj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) { radj[adj[i][j]].push_back(i); }
        }
        int k = 0;
        std::vector<bool> visited1(n);
        std::vector<int> ret(n);
        auto dfs1 = [&](auto &&dfs1, int cur) -> void {
            visited1[cur] = true;
            ret[cur] = k;
            for (int i = 0; i < radj[cur].size(); i++) {
                if (!visited1[radj[cur][i]]) { dfs1(dfs1, radj[cur][i]); }
            }
        };
        for (int i = n - 1; i >= 0; i--) { if (!visited1[vs[i]]) { dfs1(dfs1, vs[i]), k++; }}
        return ret;
    }
};