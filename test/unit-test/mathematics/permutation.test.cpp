#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../mathematics/permutation.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> e = {0, 1, 2, 3, 4};
    vector<int> a = {3, 2, 1, 4, 0};
    vector<int> b = {1, 2, 0, 3, 4};
    vector<int> ab = {2, 1, 3, 4, 0};
    vector<int> a9 = {0, 2, 1, 3, 4};
    vector<int> b6 = {0, 1, 2, 3, 4};

    assert(permutation(5) == permutation(e));
    assert(permutation(a) * permutation(b) == permutation(ab));
    assert(permutation(ab) / permutation(b) == permutation(a));
    assert(permutation(a).pow(0) == permutation(e));
    assert(permutation(a).pow(9) == permutation(a9));
    assert(permutation(b).pow(6) == permutation(b6));

    cout << "Hello World" << endl;
}