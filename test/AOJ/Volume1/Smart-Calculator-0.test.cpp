#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0109&lang=jp"
#include "../../../string/parse.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        state begin = s.begin();
        int ans = parser().expr(begin);
        consume(begin, '=');
        cout << ans << endl;
    }
    return 0;
}