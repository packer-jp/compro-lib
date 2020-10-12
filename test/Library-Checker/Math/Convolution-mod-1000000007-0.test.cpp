#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../../mathematics/convolute.hpp"

using namespace std;

int N, M;
int main() {
    using mint = mod_int<1000000007>;
    cin >> N >> M;
    vector<mint> A(N), B(M);
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    for (int i = 0; i < M; i++) { cin >> B[i]; }
    vector<mint> C = arbitrary_mod_convolute<mint, 3>(A, B);
    for (int i = 0; i < N + M - 1; i++) { cout << C[i] << endl; }
}