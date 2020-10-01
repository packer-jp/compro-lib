#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=ja"
#include "../../../mathematics/bell-number-table.hpp"
#include "../../../mathematics/mod-int.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << bell_number_table<mod_int<>>(n, k)[n][k] << endl;
}