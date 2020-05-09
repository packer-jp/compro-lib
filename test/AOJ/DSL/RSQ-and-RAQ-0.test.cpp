#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#include"../../../data-structure/lazy-segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    using ll = long long;
    auto id_t = []() { return 0LL; };
    auto id_e = []() { return 0LL; };
    auto f = [](ll a, ll b) { return a + b; };
    auto g = [](ll a, ll b) { return a + b; };
    auto h = [](ll a, ll b, int c) { return a + b * c; };
    lazysegtree_decl(ll, ll, lst, n + 1, f, g, h, id_t, id_e);
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