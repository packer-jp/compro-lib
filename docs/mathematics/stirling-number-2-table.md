---
title: 第 2 種スターリング数テーブル
documentation_of: mathematics/stirling-number-2-table.hpp
---

- `<T> std::vector<std::vector<T>> stirling_number_2_table(int n)`  
  `T`は整数型もしくは`mod_int`。サイズ`n`の第 2 種スターリング数テーブルを時間計算量`O(n^2)`で作る。
  ここで、第 2 種スターリング数`S(n, k)`は、`n`個の区別できるボールを`k`個の区別できない箱に入れる場合の数である。