#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667"
#include "../../../graph/heavy-light-decomposition.hpp"
#include "../../../data-structure/lazy-segment-tree.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    heavy_light_decomposition hld(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        hld.add_edge(a, b);
    }
    hld.build(0);
    lazy_segment_tree<rsq_and_raq> lst(vector<pair<long long, int>>(N, {0, 1}));
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int u, v;
            cin >> u >> v;
            long long ans = 0;
            vector<pair<int, int>> segs = hld.get_path(u, v, true);
            for (int j = 0; j < segs.size(); j++) {
                if (segs[j].first > segs[j].second) { swap(segs[j].first, segs[j].second); }
                ans += lst.fold(segs[j].first, segs[j].second + 1).first;
            }
            cout << ans << endl;
        } else {
            int v, x;
            cin >> v >> x;
            pair<int, int> seg = hld.get_subtree(v, true);
            if (seg.first <= seg.second) { lst.apply(seg.first, seg.second + 1, x); }
        }
    }
}