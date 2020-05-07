#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=ja"
#include"../../data-structure/segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    auto f = [](int a, int b) { return min(a, b); };
    auto zero = []() { return INT_MAX; };
    segtree_decl(int, rmq, n, f, zero);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) { rmq.set(x, y); }
        else if (com == 1) { cout << rmq.get_sum(x, y + 1) << endl; }
    }
}