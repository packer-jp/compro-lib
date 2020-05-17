#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"
#include"../../../mathematics/get-prime-factors.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << ":";
    auto v = get_prime_factors(n);
    for (int i = 0; i < v.size(); i++) {
        auto p = v[i];
        for (int j = 0; j < p.second; j++) { cout << " " << p.first; }
    }
    cout << endl;
}
