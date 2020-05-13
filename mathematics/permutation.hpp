#include <algorithm>
#include <iostream>
#include <vector>

/*
 * @title 順列
 * @docs docs/mathematics/permutation.md
 */

struct permutation {
    int n;
    std::vector<int> data;
    permutation(int n) : n(n), data(n) { for (int i = 0; i < n; i++) { data[i] = i; }}
    permutation(std::vector<int> &src) : n(src.size()), data(src) {}
    bool next() { return std::next_permutation(data.begin(), data.end()); }
    bool prev() { return std::prev_permutation(data.begin(), data.end()); }
    bool operator==(const permutation &rhs) const { return data == rhs.data; }
    bool operator!=(const permutation &rhs) const { return std::rel_ops::operator!=(*this, rhs); }
    int operator[](int i) const { return data[i]; }
    permutation &operator*=(const permutation &rhs) {
        std::vector<int> tmp(data);
        for (int i = 0; i < n; i++) { data[i] = tmp[rhs[i]]; }
        return *this;
    }
    permutation &operator/=(const permutation &rhs) { return *this *= rhs.inv(); }
    permutation operator*(const permutation &rhs) const { return permutation(*this) *= rhs; }
    permutation operator/(const permutation &rhs) const { return permutation(*this) /= rhs; }
    permutation inv() const {
        std::vector<int> ret(n);
        for (int i = 0; i < n; i++) { ret[data[i]] = i; }
        return ret;
    }
    permutation pow(long long m) const {
        std::vector<int> ret(n);
        std::vector<bool> used(n);
        for (int i = 0; i < n; i++) {
            if (used[i]) { continue; }
            std::vector<int> cyc;
            int cur = i;
            do {
                used[cur] = true;
                cyc.push_back(cur);
                cur = data[cur];
            } while (cur != i);
            for (int j = 0; j < cyc.size(); j++) { ret[cyc[j]] = cyc[(j + m) % cyc.size()]; }
        }
        return ret;
    }
    friend std::ostream &operator<<(std::ostream &os, const permutation &rhs) {
        os << "{";
        for (int i = 0; i < rhs.n; i++) { os << rhs[i] << (i + 1 != rhs.n ? ", " : ""); }
        os << "}";
        return os;
    }
};