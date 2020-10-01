#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"
#include"../../../mathematics/multi-prime-factorize.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << ":";
    multi_prime_factorize mpf(n);
    auto v = mpf.prime_factorize(n);
    for (int i = 0; i < v.size(); i++) { cout << " " << v[i]; }
    cout << endl;
}
