#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../graph/to-rooted-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 10;
    vector<vector<int>> adj(N, vector<int>());
    auto add_edge = [&](int u, int v) { adj[u].push_back(v), adj[v].push_back(u); };
    add_edge(7, 2);
    add_edge(2, 6);
    add_edge(4, 2);
    add_edge(4, 3);
    add_edge(5, 4);
    add_edge(5, 1);
    add_edge(1, 0);
    add_edge(0, 9);
    add_edge(5, 8);
    vector<int> r5 = {1, 5, 4, 4, 5, -1, 2, 2, 5, 0};
    assert(to_rooted_tree(adj, 5) == r5);
    cout << "Hello World" << endl;
}