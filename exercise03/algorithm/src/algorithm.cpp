#include <vector>
#include "../include/algorithm.hpp"

namespace algorithm{
adouble michaelis(
    const double conce,
    const adouble v_max,
    const adouble k_m){
  adouble rate = v_max * conce /(k_m + conce);
  return rate;
}

void func_res(
    const adouble v_max,
    const adouble k_m,
    int n,
    const double* matrix_con,
    const double* conc_rate,
    adouble* residual){
  for (int i =0; i<n;i++){
    residual[i]=michaelis(matrix_con[i],v_max,k_m)-conc_rate[i];
  }
}

void func_res_jac(
    const double* x_val,
    int n,
    const double* matrix_con,
    const double* conc_rate,
    double* res_val,
    double* jac){

  adept::Stack stack; // Where the derivative information is stored
  adouble x[2];
  // adouble matrix_con[n];
  // adouble conc_rate[n];
  adept::set_values(&x[0], 2, &x_val[0]); // Initialize adouble inputs
  // adept::set_values(&matrix_con[0], n, &matrix_con_val[0]); // Initialize adouble inputs
  // adept::set_values(&conc_rate[0], n, &conc_rate_val[0]); // Initialize adouble inputs  
  stack.new_recording(); // Start recording
  adouble res[n];
  func_res(x[0],x[1],n,matrix_con,conc_rate,res);
  adept::get_values(&res[0], n ,&res_val[0]);
  
  stack.independent(&x[0], 2); // Identify independent variables
  stack.dependent(&res[0], n); // Identify dependent variables

  stack.jacobian(jac); // Compute & store Jacobian in jac
}
}//namespace algorithms