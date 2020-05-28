#include <limits>
#include <map>
#include <queue>
#include <vector>

/*
 * @title Ford-Fulkerson
 * @docs docs/graph/ford-fulkerson.md
 */

template<typename M>
struct ford_fulkerson {
    using T = typename M::T;
    struct edge {
        int to, rev;
        T cap;
        bool is_rev;
    };
    int n;
    std::vector<std::vector<edge>> graph;
    std::vector<int> used;
    int timestamp;
    ford_fulkerson(const std::vector<std::vector<int>> &adj, const std::vector<std::vector<typename M::T>> &cost)
        : n(adj.size()), graph(n), used(n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                graph[i].push_back({adj[i][j], (int) graph[adj[i][j]].size(), cost[i][j], false});
                graph[adj[i][j]].push_back({i, (int) graph[i].size() - 1, M::id(), true});
            }
        }
    }
    T dfs(int v, int t, T f) {
        if (v == t) { return f; }
        used[v] = timestamp;
        for (int i = 0; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if (used[e.to] != timestamp && M::gr(e.cap, M::id())) {
                T d = dfs(e.to, t, M::gr(f, e.cap) ? e.cap : f);
                if (M::is_id(d)) { continue; }
                e.cap = M::op(e.cap, M::inv(d));
                graph[e.to][e.rev].cap = M::op(graph[e.to][e.rev].cap, d);
                return d;
            }
        }
        return M::id();
    }
    T calc_max_flow(int s, int t, T lim) {
        T ret = M::id();
        fill(used.begin(), used.end(), 0);
        timestamp = 0;
        while (true) {
            timestamp++;
            T f = dfs(s, t, lim);
            if (M::is_id(f)) { return ret; }
            ret = M::op(ret, f);
            lim = M::op(lim, M::inv(f));
        }
    }
    T calc_max_flow(int s, int t) { return calc_max_flow(s, t, M::ab()); }
    std::map<std::pair<int, int>, T> get_max_flow() {
        std::map<std::pair<int, int>, T> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                edge &e = graph[i][j];
                if (e.is_rev) { ret[{e.to, i}] = e.cap; }
            }
        }
        return ret;
    }
    std::map<std::pair<int, int>, T> get_min_cut(int s) {
        std::map<std::pair<int, int>, T> ret;
        std::vector<int> visited(n);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (visited[v]) { continue; }
            visited[v] = true;
            for (int i = 0; i < graph[v].size(); i++) {
                edge &e = graph[v][i];
                if (!M::is_id(e.cap)) { que.push(e.to); }
            }
        }
        for (int i = 0; i < n; i++) {
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
    static T id() { return 0; }
    static T ab() { return std::numeric_limits<T>::max(); }
    static T inv(const T &a) { return -a; }
    static T op(const T &a, const T &b) { return a + b; }
    static bool gr(const T &a, const T &b) { return a > b; }
    static bool is_id(const T &a) { return a == id(); };
};