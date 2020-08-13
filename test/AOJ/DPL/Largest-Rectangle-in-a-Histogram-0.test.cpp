#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C&lang=jp"
#include "../../../utility/histogram-largest-rectangle.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; i++) { cin >> h[i]; }
    cout << histogram_largest_rectangle(h) << endl;
}