#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../../mathematics/convolution.hpp"

using namespace std;

int N, M;
int A[550000], B[550000];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) { cin >> A[i]; }
    for (int i = 0; i < M; i++) { cin >> B[i]; }
    vector<int> C = arbitrary_mod_convolute<3>(A, A + N, B, B + M, 1e9 + 7);
    for (int i = 0; i < N + M - 1; i++) { cout << C[i] << endl; }
}