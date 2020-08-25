#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
#include "../../../data-structure/splay-tree.hpp"

#include <bits/stdc++.h>
using namespace std;

using splay = splay_tree<int_st>;
splay::node node[220000];
int main() {
    int n, q;
    cin >> n >> q;
    int vecsize = 0;
    for (int i = 0; i < q; i++) {
        node[i].parent = &node[i + 1], node[i + 1].left = &node[i];
        node[i + 1].update();
    }
    splay::node *root = &node[0];
    while (q--) {
        int ord, x;
        cin >> ord;
        if (ord == 0) {
            cin >> x;
            root = splay::get(vecsize++, root);
            root->value = x;
        }
        if (ord == 1) {
            cin >> x;
            root = splay::get(x, root);
            cout << root->value << endl;
        }
        if (ord == 2) {
            vecsize--;
        }

    }
}