#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "../../../data-structure/red-black-tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    red_black_tree<int_rbt> rbt;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        rbt.insert(i, a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            red_black_tree<int_rbt> mid0 = rbt.split(y);
            red_black_tree<int_rbt> mid1 = mid0.split(z - y);
            red_black_tree<int_rbt> right = mid1.split(1);
            rbt.merge(mid1), rbt.merge(mid0), rbt.merge(right);
        }
        if (x == 1) {
            cout << rbt.get_sum(y, z + 1) << endl;
        }
        if (x == 2) {
            rbt.erase(y);
            rbt.insert(y, z);
        }
    }
}