#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../graph/topological-sort.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    constexpr int N = 20, V = 100, E = 1000;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> uid(0, V - 1);
    for (int i = 0; i < N; i++) {
        vector<vector<int>> adj(V);
        bool used[V][V] = {};
        int src[V];
        for (int i = 0; i < V; i++) { src[i] = i; }
        shuffle(src, src + N, mt);
        for (int j = 0; j < E; j++) {
            int u = uid(mt), v = uid(mt);
            if (used[u][v]) { continue; }
            if (src[u] < src[v]) {
                adj[u].push_back(v);
                used[u][v] = true;
            }
        }
        vector<int> sorted = topological_sort(adj);
        // shuffle(sorted.begin(), sorted.end(), mt);
        for (int j = 0; j < V; j++) {
            for (int k = j + 1; k < V; k++) {
                assert(!used[sorted[k]][sorted[j]]);
            }
        }

    }

    cout << "Hello World" << endl;
}