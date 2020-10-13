#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"
#include "../../../graph/warshall-floyd.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    warshall_floyd<int_wf> wf(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        wf.add_edge(s, t, d);
    }
    vector<vector<int>> dist = wf.get();
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << (dist[i][j] == INT_MAX ? "INF" : to_string(dist[i][j])) << (j < V - 1 ? " " : "");
        }
        cout << endl;
    }
}