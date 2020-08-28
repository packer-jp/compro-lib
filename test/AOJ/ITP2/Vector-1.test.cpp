#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_1_A&lang=ja"
#include"../../../data-structure/red-black-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    red_black_tree<int_rbt> rbt;
    while (q--) {
        int ord, x;
        cin >> ord;
        if (ord == 0) {
            cin >> x;
            rbt.insert(rbt.size(), x);
        }
        if (ord == 1) {
            cin >> x;
            cout << rbt.get(x) << endl;
        }
        if (ord == 2) {
            rbt.erase(rbt.size() - 1);
        }
    }
}