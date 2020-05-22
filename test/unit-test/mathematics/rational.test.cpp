#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/rational.hpp"

#include<bits/stdc++.h>
using namespace std;

/*
 * @title 順列
 * @docs docs/mathematics/rational.md
 */

int main() {
    assert(rational() == rational(0));
    assert(rational(3340, 810) == rational(334, 81));
    assert(rational(-1, 2) == rational(1, -2));
    assert(rational(1, 3) + rational(1, 6) == rational(1, 2));
    assert(rational(1, 2) - rational(1, 3) == rational(1, 6));
    assert(rational(1, 2) - rational(1, 3) == rational(1, 6));
    assert(rational(100, 200) * rational(400, 300) == rational(2, 3));
    assert(rational(100, 200) / rational(300, 400) == rational(2, 3));
    assert(rational(3, 4) > rational(200, 300));
    assert(rational(200, 300) < rational(3, 4));
    assert(rational(2, 3).pow(4) == rational(16, 81));
    assert(rational(-1, 1).pow(3) == rational(-1, 1));
    assert(rational(2, 1).pow(30) < rational(3, 1).pow(20));
    assert(rational(1, 4).to_double() == 0.25);

    cout << "Hello World" << endl;
}