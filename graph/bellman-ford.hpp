#include <limits>
#include <vector>
#include <functional>
#include <cassert>

/*
 * @title ベルマン-フォード法
 * @docs docs/graph/bellman-ford.md
 */

template<typename M>
std::vector<typename M::T> bellman_ford(const std::vector<std::vector<int>> &adj,
                                        const std::vector<std::vector<typename M::E>> &cost,
                                        int s) {
    using T = typename M::T;
    struct edge {
        int from, to;
        T cost;
    };
    int n = adj.size();
    assert(0 <= s && s < n);
    std::vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) { edges.push_back({i, adj[i][j], cost[i][j]}); }
    }
    std::vector<T> ret(n, M::ab());
    ret[s] = M::id();
    for (int i = 0; i < n; i++) {
        bool upd = false;
        for (int j = 0; j < edges.size(); j++) {
            edge e = edges[j];
            T dist = M::op(ret[e.from], e.cost);
            if (M::gr(ret[e.to], dist)) { ret[e.to] = dist, upd = true; }
        }
        if (!upd) { return ret; }
    }
    return std::vector<T>();
}

struct basic_bf {
    using T = int;
    using E = int;
    static T id() { return 0; }
    static T ab() { return std::numeric_limits<T>::max(); }
    static T op(const T &a, const E &b) { return a == ab() ? ab() : a + b; }
    static bool gr(const T &a, const T &b) { return a > b; }
};