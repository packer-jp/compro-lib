#include <limits>
#include <vector>
#include <functional>

/*
 * @title ワーシャル-フロイド法
 * @docs docs/graph/warshall-floyd.md
 */

template<typename T, typename F, typename G>
std::vector<std::vector<T>> warshall_floyd(const std::vector<std::vector<T>> &graph, F f, G g) {
    int n = graph.size();
    std::vector<std::vector<T>> ret(graph);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                T dist = f(ret[i][k], ret[k][j]);
                if (g(ret[i][j], dist)) { ret[i][j] = dist; }
            }
        }
    }
    return ret;
}

template<typename T>
std::vector<std::vector<T>> basic_warshall_floyd(const std::vector<std::vector<T>> &graph) {
    auto ab = []() -> T { return std::numeric_limits<T>::max(); };
    auto f = [&](const T &a, const T &b) { return a == ab() || b == ab() ? ab() : a + b; };
    return warshall_floyd(graph, f, std::greater<T>());
}