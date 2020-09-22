#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"
#include"../../../graph/bellman-ford.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int V, E, r;
    cin >> V >> E >> r;
    bellman_ford<int_bf> bf(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        bf.add_edge(s, t, d);
    }
    vector<int> dist = bf.get_dist(r);
    if (dist.empty()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; i++) { cout << (dist[i] < INT_MAX ? to_string(dist[i]) : "INF") << endl; }
}