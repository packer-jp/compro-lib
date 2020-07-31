#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=ja"
#include "../../../graph/low-link.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        adj[s].emplace_back(t);
        adj[t].emplace_back(s);
    }
    low_link ll(adj);
    sort(ll.bridges.begin(), ll.bridges.end());
    for (auto p:ll.bridges) { cout << p.first << " " << p.second << endl; }
}