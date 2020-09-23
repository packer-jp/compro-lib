#include <limits>
#include <vector>
#include <functional>

/*
 * @title Warshall-Floyd法
 * @docs docs/graph/warshall-floyd.md
 */

template<typename S>
struct warshall_floyd {
    using T = typename S::T;
    std::vector<std::vector<T>> cost;
    warshall_floyd(int n) : cost(n, std::vector<T>(n, S::inf())) {
        for (int i = 0; i < n; i++) { cost[i][i] = S::zero(); }
    }
    void add_edge(int from, int to, T cost) { this->cost[from][to] = cost; }
    std::vector<std::vector<T>> get_dist() {
        int n = cost.size();
        std::vector<std::vector<T>> ret(cost);
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    T dist = S::plus(ret[i][k], ret[k][j]);
                    if (S::less(dist, ret[i][j])) { ret[i][j] = dist; }
                }
            }
        }
        return ret;
    }
};

struct int_wf {
    using T = int;
    static T zero() { return 0; }
    static T inf() { return std::numeric_limits<T>::max(); }
    static T plus(const T &a, const T &b) { return a == inf() || b == inf() ? inf() : a + b; }
    static bool less(const T &a, const T &b) { return a < b; }
};