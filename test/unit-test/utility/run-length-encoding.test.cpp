#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../utility/run-length-encoding.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {5, 5, 6, 3, 1, 1, 4, 5, 1, 4};
    vector<pair<int, int>> b = {{5, 2}, {6, 1}, {3, 1}, {1, 2}, {4, 1}, {5, 1}, {1, 1}, {4, 1}};
    assert(run_length_encoding(a) == b);
    cout << "Hello World" << endl;
}