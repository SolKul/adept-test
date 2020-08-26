#include "algorithm.hpp"
#include "helper.hpp"


int main() {
  double x_val[2];
  x_val[0]=0.5;
  x_val[1]=0.5;

  double matrix_con[]={0.038,0.194,0.425,0.626,1.253,2.500,3.740};
  double conc_rate[]={0.050,0.127,0.094,0.2122,0.2729,0.2665,0.3317};
  int n=7;

  double res_val[n];
  double jac[2][n];

  algorithm::func_res_jac(
    &x_val[0],
    n ,
    &matrix_con[0],
    &conc_rate[0],
    &res_val[0],
    &jac[0][0]);

  int size[]={2,n};
  helper::display_2d_array("jac",size,&jac[0][0]);
  return 0;
}