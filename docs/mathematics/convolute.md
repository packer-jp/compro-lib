## 概要
二数列の畳み込み演算を列長$N, M$に対し$O((N+M) \log (N+M))$で処理する。

## 関数
- `<I, J> std::vector<my_complex> convolute(I begin_a, I end_b, J begin_b, J end_b)`  
`[begin_a, end_a)`と`[begin_b, end_b)`を畳み込む。

- `<int MOD, int ROOT, I, J> std::vector<int> friendly_mod_convolute(I begin_a, I end_b, J begin_b, J end_b)`  
`[begin_a, end_a)`と`[begin_b, end_b)`を`MOD`を法として畳み込む。  
`MOD`が素数であり、`MOD-1`が$2$で割れる回数が多いときに用いる。  
また、原始根`ROOT`が必要。

- `<int K = 3, I, J> std::vector<int> arbitrary_mod_convolute(I begin_a, I end_b, J begin_b, J end_b, int mod)`  
`[begin_a, end_a)`と`[begin_b, end_b)`を`mod`を法として畳み込む。  
`K`個の法について`friendly_mod_convolution`を計算した結果を用いている。