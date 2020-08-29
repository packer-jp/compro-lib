#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/moebius.hpp"
#include"../../../mathematics/prime-factorize.hpp"
#include"../../../string/run-length-encoding.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 1260;
    map<int, int> mb = moebius(n);
    for (int i = 1; i <= n; i++) {
        auto pf = run_length_encoding(prime_factorize(i));
        int m = (pf.size() & 1) ? -1 : 1;
        if (n % i) { m = 0; }
        for (int i = 0; i < pf.size(); i++) {
            if (pf[i].second > 1) { m = 0; }
        }
        assert(mb[i] == m);
    }

    cout << "Hello World" << endl;
}