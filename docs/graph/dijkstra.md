## 概要
辺のコストが非負なグラフの単一始点最短距離列を頂点数$N$、辺数$M$に対し$O((N+M)\log N)$で求める。

## テンプレートパラメータ
- `typename T`  
モノイドのデータ型。

## メンバ
- `(constructor)(int n, F f, Z zero)`  
列長`n`、二項演算`f`、単位元`zero`で初期化。

- `<I> (constructor)(I begin, I end, F f, Z zero)`  
`[begin, end)`のデータを元に、二項演算`f`、単位元`zero`で初期化。

- `int n`  
列長。

- `void set(int i, T x)`  
要素`i`を`x`に変更する。

- `T operator[](int i)`  
要素`i`を取得する。

- `T get_sum(int l, int r)`  
`[l, r)`の区間和を取得する。