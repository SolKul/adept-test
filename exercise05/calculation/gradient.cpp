#include "adept.h"
#include "algorithm.h"

using adept::adouble;

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
