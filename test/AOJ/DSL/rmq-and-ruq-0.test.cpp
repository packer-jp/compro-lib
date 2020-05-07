#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja"
#include"../../../data-structure/lazy-segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    auto zero_t = []() { return INT_MAX; };
    auto zero_u = []() { return -1; };
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [&](int a, int b) { return b == zero_u() ? a : b; };
    auto h = [&](int a, int b, int c) { return b == zero_u() ? a : b; };
    lazysegtree_decl(int, int, lst, n, f, g, h, zero_t, zero_u);
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