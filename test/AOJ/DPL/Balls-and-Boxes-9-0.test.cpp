#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I&lang=ja"
#include "../../../mathematics/stirling-number-2-table.hpp"
#include "../../../mathematics/mod-int.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << stirling_number_2_table<mod_int<>>(n)[n][k] << endl;
}