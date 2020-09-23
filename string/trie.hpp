#include <vector>

template<int K>
struct trie {
    std::vector<std::vector<int>> adj;
    std::vector<int> cnt;
    trie() : adj(1, std::vector<int>(K, -1)), cnt(1) {}
    void insert(const std::vector<int> &s, int m = 1) {
        int cur = 0;
        for (int c:s) {
            if (adj[cur][c] == -1) {
                adj[cur][c] = adj.size();
                adj.emplace_back(K, -1);
                cnt.emplace_back(0);
            }
            cur = adj[cur][c];
        }
        cnt[cur] += m;
    }
    std::vector<int> count_prefix(const std::vector<int> &s) {
        std::vector<int> ret(s.size() + 1);
        ret[0] = cnt[0];
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (adj[cur][s[i]] == -1) { break; }
            cur = adj[cur][s[i]];
            ret[i + 1] = cnt[cur];
        }
        return ret;
    }
};