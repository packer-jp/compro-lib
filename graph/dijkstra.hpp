#include <limits>
#include <queue>
#include <vector>
#include <cassert>

/*
 * @title Dijkstra法
 * @docs docs/graph/dijkstra.md
 */

template<typename M>
struct dijkstra {
    using T = typename M::T;
    using E = typename M::E;
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<E>> cost;
    dijkstra(int n) : n(n), adj(n), cost(n) {}
    void add_edge(int from, int to, E cost_) { adj[from].emplace_back(to), cost[from].emplace_back(cost_); }
    std::vector<typename M::T> get_dist(int s) {
        std::vector<T> ret(n, M::inf());
        using P = std::pair<T, int>;
        auto c = [&](P a, P b) -> bool { return M::less(b.first, a.first); };
        std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
        ret[s] = M::id();
        pq.push({ret[s], s});
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            int v = p.second;
            if (M::less(ret[v], p.first)) { continue; }
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                T dist = M::op(ret[v], cost[v][i]);
                if (M::less(dist, ret[u])) { ret[u] = dist, pq.push({ret[u], u}); }
            }
        }
        return ret;
    }
};

struct int_dij {
    using T = int;
    using E = int;
    static T id() { return 0; }
    static T inf() { return std::numeric_limits<T>::max(); }
    static T op(const T &a, const E &b) { return a == inf() ? inf() : a + b; }
    static bool less(const T &a, const T &b) { return a < b; }
};