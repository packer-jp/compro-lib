#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "../../../data-structure/splay-tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    splay_tree<int_st> st;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        st.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            splay_tree<int_st> mid0 = st.split(y);
            splay_tree<int_st> mid1 = mid0.split(z - y);
            splay_tree<int_st> right = mid1.split(1);
            st.merge(mid1), st.merge(mid0), st.merge(right);
        }
        if (x == 1) {
            cout << st.get_sum(y, z + 1) << endl;
        }
        if (x == 2) {
            st.erase(y);
            st.insert(y, z);
        }
    }
}