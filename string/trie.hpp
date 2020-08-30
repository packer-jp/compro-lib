#include <vector>

template<int char_size>
struct trie {
    std::vector<std::vector<int>> adj;
    std::vector<int> cnt;
    trie() : adj(1, std::vector<int>(char_size, -1)), cnt(1) {}
    void insert(const std::vector<int> &s) {
        int cur = 0;
        for (int c:s) {
            if (adj[cur][c] == -1) {
                adj[cur][c] = adj.size();
                adj.emplace_back(char_size, -1);
                cnt.emplace_back(0);
            }
            cur = adj[cur][c];
        }
        cnt[cur]++;
    }
    std::vector<int> count_prefix(const std::vector<int> &s) {
        std::vector<int> ret(s.size());
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (adj[cur][s[i]] == -1) { break; }
            cur = adj[cur][s[i]];
            ret[i] = cnt[cur];
        }
        return ret;
    }
};