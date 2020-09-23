#include <vector>

template<typename M>
std::vector<typename M::T> re_rooting(const std::vector<std::vector<int>> &adj,
                                      const std::vector<std::vector<typename M::E>> &cost) {
    using T = typename M::T;
    int n = adj.size();
    std::vector<std::vector<T>> dp(n);
    auto dfs0 = [&](auto &&dfs0, int cur, int par) -> T {
        dp[cur].resize(adj[cur].size());
        T cum = M::id();
        for (int i = 0; i < adj[cur].size(); i++) {
            if (adj[cur][i] == par) { continue; }
            dp[cur][i] = M::op_TE(dfs0(dfs0, adj[cur][i], cur), cost[cur][i]);
            cum = M::op_TT(cum, dp[cur][i]);
        }
        return cum;
    };
    dfs0(dfs0, 0, -1);
    std::vector<T> ret(n);
    auto dfs1 = [&](auto &&dfs1, int cur, int par, T drop) -> void {
        int m = adj[cur].size();
        std::vector<T> l_cum(m + 1), r_cum(m + 1);
        l_cum[0] = r_cum[m] = M::id();
        for (int i = 0; i < m; i++) {
            if (adj[cur][i] == par) { dp[cur][i] = M::op_TE(drop, cost[cur][i]); }
            l_cum[i + 1] = M::op_TT(l_cum[i], dp[cur][i]);
        }
        for (int i = m - 1; i >= 0; i--) { r_cum[i] = M::op_TT(dp[cur][i], r_cum[i + 1]); }
        for (int i = 0; i < m; i++) {
            if (adj[cur][i] == par) { continue; }
            dfs1(dfs1, adj[cur][i], cur, M::op_TT(l_cum[i], r_cum[i + 1]));
        }
        ret[cur] = l_cum[m];
    };
    dfs1(dfs1, 0, -1, M::id());
    return ret;
}

struct diameter_rr {
    using T = int;
    using E = int;
    static T id() { return 0; }
    static T op_TT(const T &a, const T &b) { return std::max(a, b); }
    static T op_TE(const T &a, const E &b) { return a + b; }
};