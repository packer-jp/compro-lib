---
title: ベル数テーブル
documentation_of: mathematics/bell-number-table.hpp
---

- `<T> std::vector<std::vector<T>> bell_number_table(int n, int k)`  
  `T`は整数型もしくは`mod_int`。サイズ`n * k`のベル数テーブルを時間計算量`O(nk)`で作る。
  ここで、ベル数`B(n, k)`は、`n`個の区別できるボールを`k`個の区別できない箱に入れる場合の数である。