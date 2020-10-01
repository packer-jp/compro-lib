---
title: 分割数テーブル
documentation_of: mathematics/partition-table.hpp
---

- `<T> std::vector<std::vector<T>> partiton_table(int n, int k)`  
  `T`は整数型もしくは`mod_int`。サイズ`n * k`の分割数テーブルを時間計算量`O(nk)`で作る。
  ここで、分割数`P(n, k)`は、`n`個の区別できないボールを`k`個の区別できない箱に入れる場合の数である。