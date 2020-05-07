#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/mod-int.hpp"

#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 998244353;
using mint=mod_int<MOD>;

mint fact(int n) {
    mint ret = 1;
    for (int i = 2; i <= n; i++) { ret *= i; }
    return ret;
}

int main() {
    constexpr long long A = 1145141919810LL;

    assert(mint() == mint(0));
    assert(mint(A) == mint(A % MOD));
    assert(mint(-A) == mint(MOD - A % MOD));
    assert(mint(-MOD) == mint(0));
    assert(+mint(A) == mint(A));
    assert(-mint(A) == mint(-A));

    mint m = MOD;
    assert(++m == mint(MOD + 1));
    assert(--m == mint(MOD));
    assert(m++ == mint(MOD));
    assert(m-- == mint(MOD + 1));
    assert(m == mint(MOD));

    assert(mint(A)
               +mint(A) == mint(A + A));
    assert(mint(A + A) - mint(A) == mint(A));
    assert(mint(A) / mint(A) == mint(1));
    assert(mint(A).pow(A) * mint(A).pow(-A) == mint(1));

    constexpr int n = 1000, r = 100;
    mint::combination comb;

    assert(comb.P(n, r) == fact(n) / fact(n - r));
    assert(comb.C(n, r) == fact(n) / fact(r) / fact(n - r));
    assert(comb.H(n, r) == fact(n + r - 1) / fact(r) / fact(n - 1));

    cout << "Hello World" << endl;
}