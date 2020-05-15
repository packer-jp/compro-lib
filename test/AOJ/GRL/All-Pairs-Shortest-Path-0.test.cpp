#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja"
#include "../../../graph/warshall-floyd.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) { graph[i][i] = 0; }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }
    vector<vector<int>> dist = warshall_floyd<basic_wf>(graph);
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