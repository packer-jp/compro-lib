#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../../mathematics/convolute.hpp"

using namespace std;

int N, M;
int main() {
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    for (int i = 0; i < M; i++) { cin >> B[i]; }
    vector<int> C = arbitrary_mod_convolute<3>(A, B, 1e9 + 7);
    for (int i = 0; i < N + M - 1; i++) { cout << C[i] << endl; }
}