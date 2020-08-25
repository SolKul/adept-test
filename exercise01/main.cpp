#include <iostream>
#include "adept.h"

using adept::adouble;

void analy_grad(
    const double x[2],
    double dy_dx[2]){
  dy_dx[0] = 8*cos( 2.0*x[0] + 3.0*x[1]*x[1] );
  dy_dx[1] = 24*x[1] *cos(2.0*x[0] + 3.0*x[1]*x[1]);
}

adouble func_1(const adouble x[2]) {
  adouble y = 4;
  adouble s = 2.0*x[0] + 3.0*x[1]*x[1];
  y *= sin(s);
  return y;
}

double func_1_and_gradient(
    const double x_val[2], // Input values
    double dy_dx[2]) { // Output gradients

  adept::Stack stack; // Where the derivative information is stored

  adouble x[2];
  adept::set_values(x, 2, x_val); // Initialize active input variables
  
  stack.new_recording(); // Start recording
  
  adouble y = func_1(x); // Call version overloaded for adouble args

  y.set_gradient(1.0); // Defines y as the objective function

  stack.compute_adjoint(); // Run the adjoint algorithm

  // dy_dx[0] = x[0].get_gradient(); // Store the first gradient
  // dy_dx[1] = x[1].get_gradient(); // Store the second gradient
  adept::get_gradients(x, 2, dy_dx);

  return y.value(); // Return the result of the simple computation
}

int main() {
  double x_val[2];
  x_val[0]=4;
  x_val[1]=-4;
  double dy_dx[2];

  double y = func_1_and_gradient(x_val,dy_dx);

  double analy_dy_dx[2];
  analy_grad(x_val,analy_dy_dx);

  std::cout << "自動微分\n" <<
    "y = " << y << "\n" << // 出力変数の値
    "dy_dx = ("<<dy_dx[0] << "," << // 導関数の値
    dy_dx[1] << ")\n" << // 導関数の値
    std::endl;
  std::cout << "解析微分\n" <<
    "dy_dx = ("<<analy_dy_dx[0] << "," << // 導関数の値
    analy_dy_dx[1] << ")" << // 導関数の値
    std::endl;

  return 0;
}