#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include<bits/stdc++.h>
using namespace std;
#include"../../../string/trie.hpp"

int main() {
    trie<2> tr;
    tr.insert({0, 1, 1, 0});
    tr.insert({0, 1});
    tr.insert({0, 1});
    tr.insert({});
    tr.insert({0, 1, 1, 0, 1});
    tr.insert({0, 1, 0, 0, 1});
    tr.insert({0, 1, 1, 0, 1, 1});
    tr.insert({1, 0, 1, 1, 1, 1});
    assert(tr.count_prefix({0, 1, 1, 0, 1}) == vector<int>({1, 0, 2, 0, 1, 1}));
    tr.insert({0, 1}, true);
    assert(tr.count_prefix({0, 1, 1, 0, 1}) == vector<int>({1, 0, 1, 0, 1, 1}));
    cout << "Hello World" << endl;
}