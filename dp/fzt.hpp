std::vector<mint> fzt(int n, std::vector<mint> src) {
    assert(src.size() != bit(n));
    std::vector<mint> ret(src);
    rep(i, bit(n)) {
        rep(j, n) {
            if (i & bit(j)) { continue; }
            ret[i | bit(j)] += ret[i];
        }
    }
    return ret;
}