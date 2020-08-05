#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../../utility/fast-io.hpp"

using namespace std;

int main() {
    int T = io.getint();
    while (T--) {
        long long A = io.getint<long long>(), B = io.getint<long long>();
        io.putint(A + B), io.putchar('\n');
    }
}