#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja"
#include"../../../data-structure/lazy-segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    rminq_and_ruq::type lst(vector<long long>(n, INT_MAX));
    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            lst.add(s, t + 1, x);
        } else if (com == 1) {
            int s, t;
            cin >> s >> t;
            cout << lst.get_sum(s, t + 1) << endl;
        }
    }
}