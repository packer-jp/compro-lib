#include <limits>
#include <vector>
#include <functional>

/*
 * @title ワーシャル-フロイド法
 * @docs docs/graph/warshall-floyd.md
 */

template<typename M>
std::vector<std::vector<typename M::T>> warshall_floyd(const std::vector<std::vector<typename M::T>> &graph) {
    using T = typename M::T;
    int n = graph.size();
    std::vector<std::vector<T>> ret(graph);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T dist = M::op(ret[i][k], ret[k][j]);
                if (M::gr(ret[i][j], dist)) { ret[i][j] = dist; }
            }
        }
    }
    return ret;
}

struct basic_wf {
    using T = int;
    static T ab() { return std::numeric_limits<T>::max(); }
    static T op(const T &a, const T &b) { return a == ab() || b == ab() ? ab() : a + b; }
    static bool gr(const T &a, const T &b) { return a > b; }
};