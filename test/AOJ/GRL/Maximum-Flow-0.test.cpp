#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=ja"
#include"../../../graph/ford-fulkerson.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V), cap(V);
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v), cap[u].push_back(c);
    }
    ford_fulkerson<int_ff> ff(adj, cap);
    int ans0 = ff.calc_max_flow(0, V - 1);
    map<pair<int, int>, int> flow = ff.get_max_flow();
    int ans1 = 0;
    for (auto p:flow) {
        if (p.first.first == 0) { ans1 += p.second; }
    }
    int ans2 = 0;
    for (auto p:flow) {
        if (p.first.second == V - 1) { ans2 += p.second; }
    }
    map<pair<int, int>, int> cut = ff.get_min_cut(0);
    int ans3 = 0;
    for (auto p:cut) { ans3 += p.second; }
    assert(ans0 == ans1);
    assert(ans0 == ans2);
    assert(ans0 == ans3);
    cout << ans0 << endl;

}