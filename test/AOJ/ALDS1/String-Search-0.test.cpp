#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=ja"
#include"../../../string/rolling-hash.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    string T, P;
    cin >> T >> P;
    int Tn = T.length(), Pn = P.length();
    vector<char> Tv(Tn), Pv(Pn);
    copy(T.begin(), T.end(), Tv.begin()), copy(P.begin(), P.end(), Pv.begin());
    rolling_hash Th(Tv), Ph(Pv);
    for (int i = 0; i < Tn - Pn + 1; i++) {
        if (Th.get_hash(i, i + P.length()) == Ph.get_hash(0, P.length())) { cout << i << endl; }
    }
}