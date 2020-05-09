#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"
#include"../../../graph/dijkstra.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    vector<int> cnct[110000], cost[110000];
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        cnct[s].push_back(t), cost[s].push_back(d);
    }
    vector<int> dist = basic_dijkstra<int>(cnct, cnct + V, cost, r);
    for (int i = 0; i < V; i++) { cout << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl; }
}