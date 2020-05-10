#include <limits>
#include <queue>
#include <vector>

/*
 * @title ダイクストラ法
 * @docs docs/graph/dijkstra.md
 */

template<typename T, typename E, typename F, typename G, typename ID, typename AB>
std::vector<T> dijkstra(const std::vector<std::vector<int>> &adj,
                        const std::vector<std::vector<E>> &cost,
                        int s,
                        F f,
                        G g,
                        ID id,
                        AB ab) {
    int n = adj.size();
    std::vector<T> ret(n, ab());
    using P = std::pair<T, int>;
    auto c = [&](P a, P b) -> bool { return g(a.first, b.first); };
    std::priority_queue<P, std::vector<P>, decltype(c)> pq(c);
    ret[s] = id();
    pq.push({ret[s], s});
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (g(p.first, ret[v])) { continue; }
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            T dist = f(ret[v], cost[v][i]);
            if (g(ret[u], dist)) { ret[u] = dist, pq.push({ret[u], u}); }
        }
    }
    return ret;
}

template<typename T, typename E>
std::vector<T> basic_dijkstra(const std::vector<std::vector<int>> &adj,
                              const std::vector<std::vector<E>> &cost,
                              int s) {
    auto id = []() -> T { return 0; };
    auto ab = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](const T &a, const T &b) -> T { return a == ab() ? ab() : a + b; };
    return dijkstra<T>(adj, cost, s, f, std::greater<T>(), id, ab);
}