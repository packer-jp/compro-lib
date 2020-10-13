#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp"
#include "../../../graph/re-rooting.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    re_rooting<diameter_rr> rr(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        rr.add_edge(s, t, w, w);
    }
    vector<int> cands = rr.get();
    int ans = 0;
    for (int i = 0; i < n; i++) { ans = max(ans, cands[i]); }
    cout << ans << endl;
}