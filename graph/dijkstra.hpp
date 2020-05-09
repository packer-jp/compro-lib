#include <limits>
#include <queue>
#include <vector>

/*
 * @title ダイクストラ法
 * @docs docs/graph/dijkstra.md
 */

template<typename T, typename I, typename J, typename F, typename G, typename ID, typename AB>
std::vector<T> dijkstra(I begin_adj, I end_adj, J begin_cost, int s, F f, G g, ID id, AB ab) {
    int n = end_adj - begin_adj;
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
        for (int i = 0; i < (begin_adj + v)->size(); i++) {
            int u = (*(begin_adj + v))[i];
            T dist_u = f(ret[v], (*(begin_cost + v))[i]);
            if (g(ret[u], dist_u)) { ret[u] = dist_u, pq.push({ret[u], u}); }
        }
    }
    return ret;
}

template<typename T, typename I, typename J>
std::vector<T> basic_dijkstra(I begin_adj, I end_adj, J begin_cost, int s) {
    auto id = []() -> T { return 0; };
    auto ab = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](const T &a, const T &b) -> T { return a == ab() ? ab() : a + b; };
    return dijkstra<T>(begin_adj, end_adj, begin_cost, s, f, std::greater<T>(), id, ab);
}