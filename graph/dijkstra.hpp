#include <limits>
#include <queue>
#include <vector>

/*
 * @title ダイクストラ法
 * @docs docs/graph/dijkstra.md
 */

template<typename T, typename I, typename J, typename F, typename G, typename ID, typename AB>
std::vector<T> dijkstra(I begin_cnct,
                        I end_cnct,
                        J begin_cost,
                        int s,
                        const F &f,
                        const G &g,
                        const ID &id,
                        const AB &ab) {
    int n = end_cnct - begin_cnct;
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
        for (int i = 0; i < (begin_cnct + v)->size(); i++) {
            int u = (*(begin_cnct + v))[i];
            T dist_u = f(ret[v], (*(begin_cost + v))[i]);
            if (g(ret[u], dist_u)) { ret[u] = dist_u, pq.push({dist_u, u}); }
        }
    }
    return ret;
}

template<typename T, typename I, typename J>
std::vector<T> basic_dijkstra(I begin_cnct, I end_cnct, J begin_cost, int s) {
    auto id = []() -> T { return 0; };
    auto ab = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](T a, T b) -> T { return a == ab() ? ab() : a + b; };
    auto g = [](T a, T b) -> bool { return a > b; };
    return dijkstra<T>(begin_cnct, end_cnct, begin_cost, s, f, g, id, ab);
}