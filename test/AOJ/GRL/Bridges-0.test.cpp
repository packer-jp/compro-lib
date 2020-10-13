#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B&lang=ja"
#include "../../../graph/low-link.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    low_link ll(V);
    vector<int> s(E), t(E);
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i];
        if (s[i] > t[i]) { swap(s[i], t[i]); }
        ll.add_edge(s[i], t[i]);
    }
    vector<pair<int, int>> ans;
    for (int i:ll.get().second) { ans.emplace_back(s[i], t[i]); }
    sort(ans.begin(), ans.end());
    for (auto p:ans) { cout << p.first << " " << p.second << endl; }
}