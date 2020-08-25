#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_1_A&lang=ja"
#include"../../../data-structure/splay-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    splay_tree<int_st> st;
    while (q--) {
        int ord, x;
        cin >> ord;
        if (ord == 0) {
            cin >> x;
            st.insert(st.size(), x);
        }
        if (ord == 1) {
            cin >> x;
            cout << st.get(x) << endl;
        }
        if (ord == 2) {
            st.erase(st.size() - 1);
        }
    }
}