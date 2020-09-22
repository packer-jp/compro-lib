#include <limits>
#include <queue>
#include <vector>
#include <cassert>

/*
 * @title Dijkstra法
 * @docs docs/graph/dijkstra.md
 */

template<typename S>
struct dijkstra {
    using T = typename S::T;
    using E = typename S::E;
    std::vector<std::vector<int>> adj;
    std::vector<std::vector<E>> cost;
    dijkstra(int n) : adj(n), cost(n) {}
    void add_edge(int from, int to, E cost) { adj[from].emplace_back(to), this->cost[from].emplace_back(cost); }
    std::vector<T> get_dist(int s) {
        std::vector<T> ret(adj.size(), S::inf());
        using P = std::pair<T, int>;
        auto c = [&](P a, P b) -> bool { return S::less(b.first, a.first); };
        std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
        ret[s] = S::zero();
        pq.emplace(ret[s], s);
        while (!pq.empty()) {
            P p = pq.top();
            pq.pop();
            int v = p.second;
            if (S::less(ret[v], p.first)) { continue; }
            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                T dist = S::plus(ret[v], cost[v][i]);
                if (S::less(dist, ret[u])) { ret[u] = dist, pq.emplace(ret[u], u); }
            }
        }
        return ret;
    }
};

struct int_dij {
    using T = int;
    using E = int;
    static T zero() { return 0; }
    static T inf() { return std::numeric_limits<T>::max(); }
    static T plus(const T &a, const E &b) { return a == inf() ? inf() : a + b; }
    static bool less(const T &a, const T &b) { return a < b; }
};