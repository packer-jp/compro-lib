#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

struct permutation {
    std::vector<int> data;
    permutation(int n) : data(n) { std::iota(data.begin(), data.end(), 0); }
    permutation(const std::vector<int> &src) : data(src) {}
    int size() const { return data.size(); }
    static permutation id(int n) {
        std::vector<int> ret(n);
        std::iota(ret.begin(), ret.end(), 0);
        return ret;
    }
    bool next() { return std::next_permutation(data.begin(), data.end()); }
    bool prev() { return std::prev_permutation(data.begin(), data.end()); }
    int operator[](int i) const { return data[i]; }
    permutation &operator*=(const permutation &a) {
        std::vector<int> tmp(data);
        for (int i = 0; i < size(); i++) { data[i] = tmp[a[i]]; }
        return *this;
    }
    permutation &operator/=(const permutation &a) { return *this *= a.inv(); }
    friend bool operator==(const permutation &a, const permutation &b) { return a.data == b.data; }
    friend bool operator!=(const permutation &a, const permutation &b) { return std::rel_ops::operator!=(a, b); }
    friend permutation operator*(permutation a, const permutation &b) { return a *= b; }
    friend permutation operator/(permutation a, const permutation &b) { return a /= b; }
    permutation inv() const {
        std::vector<int> ret(size());
        for (int i = 0; i < size(); i++) { ret[data[i]] = i; }
        return ret;
    }
    permutation pow(long long m) const {
        std::vector<int> ret(size());
        std::vector<bool> used(size());
        for (int i = 0; i < size(); i++) {
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
    friend std::ostream &operator<<(std::ostream &os, const permutation &a) {
        os << "(";
        for (int i = 0; i < a.size(); i++) { os << a[i] << (i + 1 != a.size() ? ", " : ""); }
        os << ")";
        return os;
    }
};