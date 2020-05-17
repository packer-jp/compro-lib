#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp"
#include "../../../graph/re-rooting.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>()), cost(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        adj[s].push_back(t), adj[t].push_back(s);
        cost[s].push_back(w), cost[t].push_back(w);
    }
    vector<int> cands = re_rooting<diameter_rr>(adj, cost);
    int ans = 0;
    for (int i = 0; i < n; i++) { ans = max(ans, cands[i]); }
    cout << ans << endl;
}