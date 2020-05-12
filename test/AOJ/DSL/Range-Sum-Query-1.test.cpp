#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=ja"
#include"../../../data-structure/fenwick-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    fenwick_tree<int> ft(n + 1);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) { ft.add(x, y); }
        else if (com == 1) { cout << ft.get_sum(x, y + 1) << endl; }
    }
}