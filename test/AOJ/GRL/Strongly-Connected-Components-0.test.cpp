#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp"
#include"../../../graph/strongly-connected-components.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
    }
    vector<int> cmp = strongly_connected_components(adj);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (cmp[u] == cmp[v]) << endl;
    }
}