#include <limits>
#include <map>
#include <queue>
#include <vector>

/*
 * @title Ford-Fulkerson法
 * @docs docs/graph/ford-fulkerson.md
 */

template<typename S>
struct ford_fulkerson {
    using T = typename S::T;
    struct edge {
        int to, rev;
        T cap;
        bool is_rev;
    };
    std::vector<std::vector<edge>> graph;
    std::vector<int> used;
    int timestamp;
    void add_edge(int from, int to, T cap) {
        graph[from].push_back({to, (int) graph[to].size(), cap, false});
        graph[to].push_back({from, (int) graph[from].size() - 1, S::zero(), true});
    }
    ford_fulkerson(int n) : graph(n), used(n) {}
    T dfs(int v, int t, T f) {
        if (v == t) { return f; }
        used[v] = timestamp;
        for (int i = 0; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if (used[e.to] != timestamp && S::less(S::zero(), e.cap)) {
                T d = dfs(e.to, t, S::less(e.cap, f) ? e.cap : f);
                if (S::is_zero(d)) { continue; }
                e.cap = S::plus(e.cap, S::minus(d));
                graph[e.to][e.rev].cap = S::plus(graph[e.to][e.rev].cap, d);
                return d;
            }
        }
        return S::zero();
    }
    T calc_max_flow(int s, int t, T lim) {
        T ret = S::zero();
        fill(used.begin(), used.end(), 0);
        timestamp = 0;
        while (true) {
            timestamp++;
            T f = dfs(s, t, lim);
            if (S::is_zero(f)) { return ret; }
            ret = S::plus(ret, f);
            lim = S::plus(lim, S::minus(f));
        }
    }
    T calc_max_flow(int s, int t) { return calc_max_flow(s, t, S::inf()); }
    std::map<std::pair<int, int>, T> get_max_flow() {
        std::map<std::pair<int, int>, T> ret;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                edge &e = graph[i][j];
                if (e.is_rev) { ret[{e.to, i}] = e.cap; }
            }
        }
        return ret;
    }
    std::map<std::pair<int, int>, T> get_min_cut(int s) {
        std::map<std::pair<int, int>, T> ret;
        std::vector<int> visited(graph.size());
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (visited[v]) { continue; }
            visited[v] = true;
            for (int i = 0; i < graph[v].size(); i++) {
                edge &e = graph[v][i];
                if (!S::is_zero(e.cap)) { que.push(e.to); }
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i]) { continue; }
            for (int j = 0; j < graph[i].size(); j++) {
                edge &e = graph[i][j];
                if (e.is_rev && visited[e.to]) { ret[{e.to, i}] = e.cap; }
            }
        }
        return ret;
    }
};

struct int_ff {
    using T = int;
    static T zero() { return 0; }
    static T inf() { return std::numeric_limits<T>::max(); }
    static T minus(const T &a) { return -a; }
    static T plus(const T &a, const T &b) { return a + b; }
    static bool less(const T &a, const T &b) { return a < b; }
    static bool is_zero(const T &a) { return a == zero(); };
};