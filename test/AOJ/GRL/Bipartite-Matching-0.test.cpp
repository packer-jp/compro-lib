#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=ja"
#include"../../../graph/bipartite-matching.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, E;
    cin >> X >> Y >> E;
    vector<vector<int>> adj(X + Y);
    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(X + y), adj[X + y].push_back(x);
    }
    cout << get_max_bipartite_matching(adj).size() << endl;
}