#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja"
#include "../../../utility/binary-search.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> S(n + 1);
    for (int i = 0; i < n; i++) { cin >> S[i]; }
    S[n] = INT_MAX;
    int q;
    cin >> q;
    vector<int> T(n);
    for (int i = 0; i < q; i++) { cin >> T[i]; }
    int ans = 0;
    for (int i = 0; i < q; i++) {
        int idx = discrete_binary_search(n, -1, [&](int x) { return S[x] >= T[i]; });
        if (S[idx] == T[i]) { ans++; }
    }
    cout << ans << endl;
}