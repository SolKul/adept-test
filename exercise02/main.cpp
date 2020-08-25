#include "algorithm.hpp"
#include "display.hpp"


int main() {
  double x_val[2];
  x_val[0]=2;
  x_val[1]=-4;
  double y_val[2];
  double jac[2][2];

  algorithm::func_2_jacobian(2, &x_val[0], 2, &y_val[0], &jac[0][0]);

  display_array("jac",2*2,&jac[0][0]);
  return 0;
}