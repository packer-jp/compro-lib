#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"
#include"../../../mathematics/get-prime-table.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> pt = get_prime_table(100000000);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans += pt[a];
    }
    cout << ans << endl;
}