# boost:odeint

## セットアップ
https://qiita.com/SolKul/items/600d6cd306509240a37a
を参考に、boostのインストールで、

```bash
./bootstrap.sh --with-libraries=python,math --with-python=python3 --with-python-version=3.8
./b2 install -j8
```

とインストール

ただし、boostのodeintはヘッダオンリーライブラリなのでビルドはされず、単にヘッダファイル(と関連するファイル)がコピーされるだけ

## odeint使い方

[公式ドキュメント](https://www.boost.org/doc/libs/1_74_0/libs/numeric/odeint/doc/html/index.html)  
[C++で常微分方程式：boost::odeint入門 | Qiita](https://qiita.com/hmito/items/483445ac0d42fb4428a5)

ざっくりodeintで必要なのは

$$
dx/dt=f(t,x)
$$

について

- stepper:次のxをどう決めるか、
- state:xを保持する
- system:f(t,x)を計算
- observer:途中の結果を保存

の引数が必要