#include <vector>

template<typename S>
struct re_rooting {
    using T = typename S::T;
    using E = typename S::E;
    struct edge {
        int to;
        E cost;
        edge(int to, E cost) : to(to), cost(cost) {}
    };
    int m = 0;
    std::vector<std::vector<edge>> adj;
    re_rooting(int n) : adj(n) {}
    int add_edge(int u, int v, E u2v, E v2u) {
        adj[u].emplace_back(v, u2v), adj[v].emplace_back(u, v2u);
        return m++;
    }
    std::vector<T> get() {
        std::vector<std::vector<T>> dp(adj.size());
        auto dfs0 = [&](auto &&dfs0, int cur, int par) -> T {
            dp[cur].resize(adj[cur].size());
            T cum = S::id();
            for (int i = 0; i < adj[cur].size(); i++) {
                if (adj[cur][i].to == par) { continue; }
                dp[cur][i] = S::op_TE(dfs0(dfs0, adj[cur][i].to, cur), adj[cur][i].cost);
                cum = S::op_TT(cum, dp[cur][i]);
            }
            return cum;
        };
        dfs0(dfs0, 0, -1);
        std::vector<T> ret(adj.size());
        auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop) -> void {
            int k = adj[cur].size();
            std::vector<T> l_cum(k + 1), r_cum(k + 1);
            l_cum[0] = r_cum[k] = S::id();
            for (int i = 0; i < k; i++) {
                if (adj[cur][i].to == par) { dp[cur][i] = S::op_TE(drop, adj[cur][i].cost); }
                l_cum[i + 1] = S::op_TT(l_cum[i], dp[cur][i]);
            }
            for (int i = k - 1; i >= 0; i--) { r_cum[i] = S::op_TT(dp[cur][i], r_cum[i + 1]); }
            for (int i = 0; i < k; i++) {
                if (adj[cur][i].to == par) { continue; }
                dfs1(dfs1, adj[cur][i].to, cur, S::op_TT(l_cum[i], r_cum[i + 1]));
            }
            ret[cur] = l_cum[k];
        };
        dfs1(dfs1, 0, -1, S::id());
        return ret;
    }
};

struct diameter_rr {
    using T = int;
    using E = int;
    static T id() { return 0; }
    static T op_TT(const T &a, const T &b) { return std::max(a, b); }
    static T op_TE(const T &a, const E &b) { return a + b; }
};