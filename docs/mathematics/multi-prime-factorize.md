---
title: 素因数分解 (複数クエリ)
documentation_of: mathematics/multi-prime-factorize.hpp
---

- `struct multi_prime_factorize`
  複数の素因数分解クエリを処理する。

  - `(constructor)(int n)`
  最大で`n`まで素因数分解できるように初期化。時間計算量`O(n log n)`。

  - `std::vector<int> prime_factorize(int a)`
  `a`を素因数分解した結果を返す。時間計算量`O(log a)`。
