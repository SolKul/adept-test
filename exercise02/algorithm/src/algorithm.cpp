#include <vector>
#include "../include/algorithm.hpp"

namespace algorithm{

void func_2(int n, const adouble* x, int m, adouble* y){
  for(int i =0; i<n; i++){
    y[i]=x[i]*x[i];
  }
}

void func_2_jacobian(
    int n, // Number of input values
    const double* x_val, // Input values
    int m, // Number of output values
    double* y_val, // Output values
    double* jac) { // Output Jacobian matrix

  using adept::adouble; // Import Stack and adouble from adept
  adept::Stack stack; // Where the derivative information is stored

  std::vector<adouble> x(n); // Vector of active input variables
  adept::set_values(&x[0], n, &x_val[0]); // Initialize adouble inputs

  stack.new_recording(); // Start recording
  std::vector<adouble> y(m); // Create vector of active output variables
  func_2(n, &x[0], m, &y[0]); // Run algorithm
  adept::get_values(&y[0], m ,&y_val[0]);
  
  stack.independent(&x[0], n); // Identify independent variables
  stack.dependent(&y[0], m); // Identify dependent variables

  stack.jacobian(jac); // Compute & store Jacobian in jac
}
}//namespace algorithms