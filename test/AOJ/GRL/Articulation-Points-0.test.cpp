#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A&lang=ja"
#include "../../../graph/low-link.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    low_link ll(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        ll.add_edge(s, t);
    }
    vector<int> ans = ll.get().first;
    sort(ans.begin(), ans.end());
    for (auto p:ans) { cout << p << endl; }
}