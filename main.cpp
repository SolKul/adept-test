#include <iostream>
#include "adept.h"
int main() {
  adept::Stack stack;    // 導関数の情報を格納するオブジェクト
  adept::adouble x = 2;  // 入力変数
  stack.new_recording(); // アルゴリズムの記録を開始
  adept::adouble y =
    ( x + 3 ) * ( 4 * x ); // アルゴリズムを実行
  y.set_gradient( 1.0 );   // 出力変数の勾配を設定
  stack.reverse();         // トップダウン型自動微分を実行
  std::cout << y.value() << "," << // 出力変数の値
               x.get_gradient() << // 導関数の値
               std::endl;
}
// --> 40,28