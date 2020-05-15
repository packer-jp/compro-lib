#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#include"../../../data-structure/lazy-segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    using ll = long long;
    cin >> n >> q;
    rsq_and_raq::type lst(n + 1);
    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t;
            ll x;
            cin >> s >> t >> x;
            lst.add(s, t + 1, x);
        } else if (com == 1) {
            int s, t;
            cin >> s >> t;
            cout << lst.get_sum(s, t + 1) << endl;
        }
    }
}