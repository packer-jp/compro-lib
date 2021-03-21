#include <cassert>
#include <functional>
#include <limits>
#include <vector>

template <typename S> struct bellman_ford {
    using T = typename S::T;
    using E = typename S::E;
    struct edge {
        int from, to;
        E cost;
        edge(int from, int to, E cost) : from(from), to(to), cost(cost) {
        }
    };
    int n;
    std::vector<edge> edges;
    bellman_ford(int n) : n(n) {
    }
    void add_edge(int from, int to, E cost) {
        edges.emplace_back(from, to, cost);
    }
    std::vector<T> get(int s) {
        std::vector<T> ret(n, S::inf());
        ret[s] = S::zero();
        for (int i = 0; i < n; i++) {
            bool upd = false;
            for (int j = 0; j < edges.size(); j++) {
                edge e = edges[j];
                T dist = S::plus(ret[e.from], e.cost);
                if (S::less(dist, ret[e.to])) {
                    ret[e.to] = dist, upd = true;
                }
            }
            if (!upd) {
                return ret;
            }
        }
        return std::vector<T>();
    }
};

struct int_bf {
    using T = int;
    using E = int;
    static T zero() {
        return 0;
    }
    static T inf() {
        return std::numeric_limits<T>::max();
    }
    static T plus(const T &a, const E &b) {
        return a == inf() ? inf() : a + b;
    }
    static bool less(const T &a, const T &b) {
        return a < b;
    }
};