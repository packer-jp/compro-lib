#include <limits>
#include <map>
#include <queue>
#include <vector>

/*
 * @title Dinic法
 * @docs docs/graph/dinic.md
 */

template<typename M>
struct dinic {
    using T = typename M::T;
    struct edge {
        int to, rev;
        T cap;
        bool is_rev;
    };
    int n;
    std::vector<std::vector<edge>> graph;
    std::vector<int> level, iter;
    dinic(const std::vector<std::vector<int>> &adj, const std::vector<std::vector<typename M::T>> &cost)
        : n(adj.size()), graph(n), level(n), iter(n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                graph[i].push_back({adj[i][j], (int) graph[adj[i][j]].size(), cost[i][j], false});
                graph[adj[i][j]].push_back({i, (int) graph[i].size() - 1, M::id(), true});
            }
        }
    }
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        std::queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < graph[v].size(); i++) {
                edge &e = graph[v][i];
                if (M::is_id(e.cap) || level[e.to] >= 0) { continue; }
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
    T dfs(int v, int t, T f) {
        if (v == t) { return f; }
        for (int &i = iter[v]; i < graph[v].size(); i++) {
            edge &e = graph[v][i];
            if (level[v] >= level[e.to] || M::is_id(e.cap)) { continue; }
            T d = dfs(e.to, t, M::gr(f, e.cap) ? e.cap : f);
            if (M::is_id(d)) { continue; }
            e.cap = M::op(e.cap, M::inv(d));
            graph[e.to][e.rev].cap = M::op(graph[e.to][e.rev].cap, d);
            return d;
        }
        return M::id();
    }
    T calc_max_flow(int s, int t, T lim) {
        T ret = M::id();
        while (true) {
            bfs(s);
            if (level[t] < 0 || M::is_id(lim)) { return ret; }
            fill(iter.begin(), iter.end(), 0);
            T f;
            while (!M::is_id(f = dfs(s, t, lim))) {
                ret = M::op(ret, f);
                lim = M::op(lim, M::inv(f));
            }
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

struct int_dinic {
    using T = int;
    static T id() { return 0; }
    static T ab() { return std::numeric_limits<T>::max(); }
    static T inv(const T &a) { return -a; }
    static T op(const T &a, const T &b) { return a + b; }
    static bool gr(const T &a, const T &b) { return a > b; }
    static bool is_id(const T &a) { return a == id(); };
};