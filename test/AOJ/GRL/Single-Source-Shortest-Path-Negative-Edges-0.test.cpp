#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"
#include"../../../graph/bellman-ford.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<int>> adj(V, vector<int>()), cost(V, vector<int>());
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        adj[s].push_back(t), cost[s].push_back(d);
    }
    vector<int> dist = bellman_ford<int_bf>(adj, cost, r);
    if (dist.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; i++) { cout << (dist[i] < INT_MAX ? to_string(dist[i]) : "INF") << endl; }
}