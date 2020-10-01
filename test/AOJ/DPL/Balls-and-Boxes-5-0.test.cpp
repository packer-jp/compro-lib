#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_E&lang=ja"
#include "../../../mathematics/partition-table.hpp"
#include "../../../mathematics/mod-int.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << partition_table<mod_int<>>(n, k)[n][k] << endl;
}