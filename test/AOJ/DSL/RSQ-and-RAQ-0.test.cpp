#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#include"../../../data-structure/lazy-segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, q;
    using ll = long long;
    cin >> n >> q;
    struct rsq_and_raq {
        using T = ll;
        using E = ll;
        static T id_T() { return 0; };
        static E id_E() { return 0; };
        static T op_TT(const T &a, const T &b) { return a + b; }
        static E op_EE(const T &a, const T &b) { return a + b; }
        static T op_TE(const T &a, const T &b, int c) { return a + b * c; }
    };
    lazy_segment_tree<rsq_and_raq> lst(n + 1);
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