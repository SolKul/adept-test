#include <iostream>
#include "algorithm.h"

int main() {
  double x_val[2];
  x_val[0]=4;
  x_val[1]=-4;
  double dy_dx[2];

  double y = func_1_and_gradient(x_val,dy_dx);

  std::cout << "double型呼び出し" << std::endl;
  double y_noad = func_1(x_val);

  std::cout << "自動微分結果:\n" <<
    "y = " << y << "\n" << // 出力変数の値
    "dy_dx = ("<<dy_dx[0] << "," << // 導関数の値
    dy_dx[1] << ")\n" << // 導関数の値
    std::endl;

  return 0;
}