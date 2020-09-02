#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp"
#include"../../../data-structure/fenwick-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree_range<rsq> ft(n);
    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            s--, t--;
            ft.apply(s, t + 1, x);
        } else if (com == 1) {
            int i;
            cin >> i;
            i--;
            cout << ft[i] << endl;
        }
    }
}