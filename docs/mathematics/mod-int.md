---
title: 剰余環 / 体
documentation_of: mathematics/mod-int.hpp
---

- `<int MOD=1'000'000'0007> struct mod_int`  
`MOD`を法とした剰余環 / 体。

  - `(constructor)(long long v_)`  
  値`v_`で初期化。

  - `static int mod()`  
  `MOD`を返す。

  - 各種`operator`  
  演算をする。特に、割り算の可能性・計算量は関数`inv`に準拠する。
  
  - `mod_int inv()`  
  逆元を返す。値と`MOD`が互いに素である場合のみ使える。時間計算量`O(log MOD)`。
  
  - `mod_int pow(int n)`  
  `n`乗を返す。時間計算量`O(log n)`。

- `<T> struct combination`  
  組み合わせの計算を行う。`T`は`mod_int`。
  
  - `(constructor)(int n)`  
  `n`までの階乗、逆元、階乗逆元をテーブルに保存して初期化。
  
  - 各種関数  
  順列、組み合わせ数、重複組み合わせ数を計算する。