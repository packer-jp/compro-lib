#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"
#include "../../../graph/heavy-light-decomposition.hpp"
#include "../../../data-structure/lazy-segment-tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    heavy_light_decomposition hld(adj);
    hld.build(0);
    using ll = long long;
    struct rsq_and_raq_ll {
        using T = std::pair<ll, int>;
        using E = ll;
        static T id_T() { return {0, 0}; };
        static E id_E() { return 0; };
        static T op_TT(const T &a, const T &b) { return {a.first + b.first, a.second + b.second}; }
        static E op_EE(const E &a, const E &b) { return a + b; }
        static T op_TE(const T &a, const E &b) { return {a.first + b * a.second, a.second}; }
    };
    lazy_segment_tree<rsq_and_raq_ll> lst(vector<pair<ll, int>>(N, {0, 1}));
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int u, v;
            cin >> u >> v;
            ll ans = 0;
            vector<pair<int, int>> segs = hld.get_path(u, v, true);
            for (int j = 0; j < segs.size(); j++) {
                if (segs[j].first > segs[j].second) { swap(segs[j].first, segs[j].second); }
                ans += lst.get_sum(segs[j].first, segs[j].second + 1).first;
            }
            cout << ans << endl;
        } else {
            int v, x;
            cin >> v >> x;
            pair<int, int> seg = hld.get_subtree(v, true);
            lst.add(seg.first, seg.second + 1, x);
        }
    }
}