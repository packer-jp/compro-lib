## 概要
モノイド列の一点変更クエリと区間和クエリを列長$N$に対し$O(\log N)$で処理する。

## テンプレートパラメータ
- `typename T`  
扱うモノイドのデータ型。

- `typename F`  
扱うモノイドの二項演算の型。

- `typename Z`  
扱うモノイドの単位元を返す関数の型。

## メンバ
- `(constructor)(int n, F f, Z z)`  
列長`n`、二項演算`f`、単位元`z`で初期化。

- `<typename I>(constructor)(I begin, I end, F f, Z z)`  
`[begin, end)`のデータを元に、列、二項演算`f`、単位元`z`で初期化。

- `int n`  
列長。

- `std::vector<T> data`  
データを格納しておく配列。

- `void set(int i, T x)`  
要素`i`を`x`に変更する。

- `T operator[](int i)`  
要素`i`を取得する。

- `T get_sum(int l, int r)`  
`[l, r)`の区間和を取得する。