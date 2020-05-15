#include <limits>
#include <queue>
#include <vector>
#include <cassert>

/*
 * @title ダイクストラ法
 * @docs docs/graph/dijkstra.md
 */

template<typename M>
std::vector<typename M::T> dijkstra(const std::vector<std::vector<int>> &adj,
                                    const std::vector<std::vector<typename M::E>> &cost,
                                    int s) {
    using T = typename M::T;
    int n = adj.size();
    assert(0 <= s && s < n);
    std::vector<T> ret(n, M::ab());
    using P = std::pair<T, int>;
    auto c = [&](P a, P b) -> bool { return M::gr(a.first, b.first); };
    std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
    ret[s] = M::id();
    pq.push({ret[s], s});
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (M::gr(p.first, ret[v])) { continue; }
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            T dist = M::op(ret[v], cost[v][i]);
            if (M::gr(ret[u], dist)) { ret[u] = dist, pq.push({ret[u], u}); }
        }
    }
    return ret;
}

struct int_dij {
    using T = int;
    using E = int;
    static T id() { return 0; }
    static T ab() { return std::numeric_limits<T>::max(); }
    static T op(const T &a, const E &b) { return a == ab() ? ab() : a + b; }
    static bool gr(const T &a, const T &b) { return a > b; }
};