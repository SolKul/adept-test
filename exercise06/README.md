
# c++の宣言と定義についてのテスト


## c++の宣言と定義

**宣言**

宣言はある関数やクラスがあることを示す
ヘッダファイルで行う

**定義**

定義は関数やクラスの実際の実装
ソースファイル(.cpp)で行う(テンプレートはヘッダファイルで行う)

## 注意

- 宣言しておいて、定義がない場合はその関数やクラスは無視される。その関数を使わない限りビルドエラーにはならない。
- 実はコンパイラによってはヘッダファイルで同名、引数返り値全部型も同じで定義してもコンパイルエラーにならずエラーなしで実行できる。たぶんコンパイラがよしなに処理してくれていると思われる。
- 静的ライブラリ、動的ライブラリで同じ名前があった場合、リンクした順番でどっちかが使われる。

samplesフォルダ内のサンプルライブラリは上記全部やってみてる。エラーは起こらない。