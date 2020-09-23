#include <vector>

std::vector<int> strongly_connected_components(const std::vector<std::vector<int>> &adj) {
    int n = adj.size();
    std::vector<int> vs;
    {
        std::vector<bool> visited(n);
        auto dfs = [&](auto &&self, int cur) -> void {
            if (visited[cur]) { return; }
            visited[cur] = true;
            for (int i = 0; i < adj[cur].size(); i++) { self(self, adj[cur][i]); }
            vs.push_back(cur);
        };
        for (int i = 0; i < n; i++) { dfs(dfs, i); }
    }
    std::vector<int> ret(n);
    {
        std::vector<bool> visited(n);
        std::vector<std::vector<int>> radj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) { radj[adj[i][j]].push_back(i); }
        }
        int k = 0;
        auto dfs = [&](auto &&self, int cur) -> void {
            visited[cur] = true;
            ret[cur] = k;
            for (int i = 0; i < radj[cur].size(); i++) {
                if (!visited[radj[cur][i]]) { self(self, radj[cur][i]); }
            }
        };
        for (int i = n - 1; i >= 0; i--) { if (!visited[vs[i]]) { dfs(dfs, vs[i]), k++; }}
    }
    return ret;
}