#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=jp"
#include "../../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<point> ps(n);
    for (int i = 0; i < n; i++) { cin >> ps[i].y >> ps[i].x; }
    vector<point> ch = convex_hull(ps);
    rotate(ch.begin(), ch.begin() + 1, ch.end()), reverse(ch.begin(), ch.end());
    cout << ch.size() << endl;
    for (int i = 0; i < ch.size(); i++) { cout << (int) ch[i].y << " " << (int) ch[i].x << endl; }
}