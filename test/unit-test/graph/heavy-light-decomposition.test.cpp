#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A&lang=ja"
#include"../../../graph/heavy-light-decomposition.hpp"
#include"../../../data-structure/segment-tree.hpp"

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 10;
    struct str {
        using T = string;
        static T op(T a, T b) { return a + b; }
        static T id() { return ""; }
    };
    segment_tree<str> st_fwd(N), st_rev(N);
    vector<string> weight = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
    heavy_light_decomposition hld(N);
    hld.add_edge(7, 2);
    hld.add_edge(2, 6);
    hld.add_edge(4, 2);
    hld.add_edge(4, 3);
    hld.add_edge(5, 4);
    hld.add_edge(5, 1);
    hld.add_edge(1, 0);
    hld.add_edge(0, 9);
    hld.add_edge(5, 8);
    vector<int> in = hld.build(5);
    for (int i = 0; i < N; i++) {
        st_fwd.set(in[i], weight[i]);
        st_rev.set(N - in[i] - 1, weight[i]);
    }
    auto path = [&](int u, int v) {
        string ret = "";
        vector<pair<int, int>> path = hld.get_path(u, v, false);
        for (int i = 0; i < path.size(); i++) {
            int l = path[i].first, r = path[i].second;
            if (l < r) { ret += st_fwd.fold(l, r + 1); }
            else { ret += st_rev.fold(N - l - 1, N - r); }
        }
        return ret;
    };
    auto subtree = [&](int v) {
        pair<int, int> subtree = hld.get_subtree(v, false);
        return st_fwd.fold(subtree.first, subtree.second + 1);
    };
    assert(path(2, 1) == "cefb");
    assert(path(5, 3) == "fed");
    assert(path(7, 4) == "hce");
    assert(path(4, 4) == "e");
    assert(subtree(2) == "chg");
    assert(subtree(5) == "fechgdbaji");
    assert(hld.get_dist(2, 0) == 4);
    assert(hld.get_dist(4, 1) == 2);

    cout << "Hello World" << endl;
}