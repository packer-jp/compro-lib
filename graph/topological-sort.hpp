#include <vector>
#include <stack>

struct topological_sort {
    std::vector<std::vector<int>> adj;
    topological_sort(int n) : adj(n) {}
    void add_edge(int from, int to) { adj[from].emplace_back(to); }
    std::vector<int> get() {
        int n = adj.size();
        std::vector<int> in_deg(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) { in_deg[adj[i][j]]++; }
        }
        std::vector<int> ret;
        std::stack<int> stk;
        for (int i = 0; i < n; i++) { if (in_deg[i] == 0) { stk.push(i); }}
        while (!stk.empty()) {
            int i = stk.top();
            stk.pop();
            ret.push_back(i);
            for (int j = 0; j < adj[i].size(); j++) {
                if (--in_deg[adj[i][j]] == 0) { stk.push(adj[i][j]); }
            }
        }
        return ret;
    }
};