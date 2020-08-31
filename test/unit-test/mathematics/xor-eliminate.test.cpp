#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include "../../../mathematics/xor-eliminate.hpp"
#include "../../../utility/bit-reverse.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset<5> a0("11000"), a1("10110"), a2("11111"), a3("00111"), a4("01110");
    vector<bitset<5>> a = {a0, a1, a2, a3, a4};
    for (auto &x:a) { x = bit_reverse(x); }
    vector<bitset<5>> b = xor_eliminate(a);
    for (auto &x:b) { x = bit_reverse(x); }
    for (auto x:b) { cerr << x << endl; }
    cout << "Hello World" << endl;
}