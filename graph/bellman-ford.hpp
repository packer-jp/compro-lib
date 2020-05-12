#include <limits>
#include <vector>
#include <functional>

template<typename T, typename E, typename F, typename G, typename ID, typename AB>
std::vector<T> bellman_ford(const std::vector<std::vector<int>> &adj,
                            const std::vector<std::vector<E>> &cost,
                            int s,
                            F f,
                            G g,
                            ID id,
                            AB ab) {
    struct edge {
        int from, to;
        T cost;
    };
    int n = adj.size();
    std::vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) { edges.push_back({i, adj[i][j], cost[i][j]}); }
    }
    std::vector<T> ret(n, ab());
    ret[s] = id();
    for (int i = 0; i < n; i++) {
        bool update = false;
        for (int j = 0; j < edges.size(); j++) {
            edge e = edges[j];
            T dist = f(ret[e.from], e.cost);
            if (g(ret[e.to], dist)) { ret[e.to] = dist, update = true; }
        }
        if (!update) { return ret; }
    }
    return std::vector<T>();
}

template<typename T>
std::vector<T> basic_bellman_ford(const std::vector<std::vector<int>> &adj,
                                  const std::vector<std::vector<T>> &cost,
                                  int s) {
    auto id = []() -> T { return 0; };
    auto ab = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](const T &a, const T &b) -> T { return a == ab() ? ab() : a + b; };
    return bellman_ford<T>(adj, cost, s, f, std::greater<T>(), id, ab);
}