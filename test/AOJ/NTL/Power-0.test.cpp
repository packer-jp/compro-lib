#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp"
#include"../../../mathematics/mod-int.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    mod_int<> m;
    int n;
    cin >> m >> n;
    cout << m.pow(n) << endl;
}
