#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/xor-eliminate.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    bitset<5> a0("11000"), a1("01010"), a2("11011"), a3("00011");
    vector<bitset<5>> a = {a0, a1, a2, a3};
    vector<bitset<5>> b = xor_eliminate<5>(a);
    cout << "Hello World" << endl;
}