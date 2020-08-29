#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"
#include"../../../mathematics/multi-prime-factorize.hpp"
#include"../../../string/run-length-encoding.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << ":";
    auto spf = smallest_prime_factors(n);
    auto v = run_length_encoding(prime_factorize(n, spf));
    for (int i = 0; i < v.size(); i++) {
        auto p = v[i];
        for (int j = 0; j < p.second; j++) { cout << " " << p.first; }
    }
    cout << endl;
}
