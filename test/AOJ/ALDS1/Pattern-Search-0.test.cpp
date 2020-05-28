#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C&lang=ja"
#include"../../../string/rolling-hash-2d.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W, R, C;
    cin >> H >> W;
    vector<string> F(H);
    vector<vector<char>> Fv(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        cin >> F[i];
        copy(F[i].begin(), F[i].end(), Fv[i].begin());
    }
    cin >> R >> C;
    vector<string> P(R);
    vector<vector<char>> Pv(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        cin >> P[i];
        copy(P[i].begin(), P[i].end(), Pv[i].begin());
    }
    rolling_hash_2d Fh(Fv), Ph(Pv);
    for (int i = 0; i < H - R + 1; i++) {
        for (int j = 0; j < W - C + 1; j++) {
            if (Fh.get_hash(i, j, i + R, j + C) == Ph.get_hash(0, 0, R, C)) {
                cout << i << " " << j << endl;
            }
        }
    }
}