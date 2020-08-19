#include <iostream>
#include "adept.h"

using namespace std;
using adept::adouble;

adouble algorithm(const adouble x[2]) {
  adouble y = 4.0;
  adouble s = 2.0*x[0] + 3.0*x[1]*x[1];
  y *= sin(s);
  return y;
}

double algorithm_and_gradient(
  const double x_val[2], // Input values
  double dy_dx[2]) { // Output gradients
    adept::Stack stack; // Where the derivative information is stored
    adouble x[2] = {x_val[0], x_val[1]}; // Initialize active input variables
    stack.new_recording(); // Start recording
    adouble y = algorithm(x); // Call version overloaded for adouble args
    y.set_gradient(1.0); // Defines y as the objective function
    stack.compute_adjoint(); // Run the adjoint algorithm
    dy_dx[0] = x[0].get_gradient(); // Store the first gradient
    dy_dx[1] = x[1].get_gradient(); // Store the second gradient
    return y.value(); // Return the result of the simple computation
}

int main() {
  double x_val[2];
  x_val[0]=4;
  x_val[1]=-4;
  double dy_dx[2];
  double y = algorithm_and_gradient(x_val,dy_dx);
  std::cout << y << "," << // 出力変数の値
    dy_dx[0] << "," << // 導関数の値
    dy_dx[1] << // 導関数の値
    std::endl;
  return 0;
}