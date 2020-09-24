#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp"
#include"../../../data-structure/union-find-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    union_find_tree<normal_uf> uf(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) { uf.unite(x, y); }
        else if (com == 1) { cout << uf.same(x, y) << endl; }
    }
}