#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"
#include"../../../graph/dijkstra.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    dijkstra<int_dij> dij(V);
    vector<vector<int>> adj(V, vector<int>()), cost(V, vector<int>());
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dij.add_edge(s, t, d);
    }
    vector<int> dist = dij.get(r);
    for (int i = 0; i < V; i++) { cout << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl; }
}