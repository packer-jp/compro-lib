## 概要
二数列の畳み込み演算を列長$N, M$に対し$O((N+M) \log (N+M))$で処理する。

## 関数
- `std::vector<double> convolute(std::vector<double> a, std::vector<double> b)`  
`a`と`b`を畳み込む。

- `<int MOD, int ROOT> std::vector<int> friendly_mod_convolute(std::vector<int> a, std::vector<int> b)`  
`a`と`b`を`MOD`を法として畳み込む。  
`MOD`が素数であり、`MOD-1`が`2`で割れる回数が多いときに用いる。  
また、原始根`ROOT`が必要。

- `<int K = 3> std::vector<int> arbitrary_mod_convolute(std::vector<int> a, std::vector<int> b, int mod)`  
`a`と`b`を`mod`を法として畳み込む。  
`K`個の法について`friendly_mod_convolution`を計算した結果を用いている。