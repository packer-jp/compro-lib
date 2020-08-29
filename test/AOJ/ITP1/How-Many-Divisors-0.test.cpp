#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=jp"
#include"../../../mathematics/get-divisors.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> div = get_divisors(c);
    int ans = 0;
    for (int i = 0; i < (int) div.size(); i++) { ans += a <= div[i] && div[i] <= b; }
    cout << ans << endl;
}
