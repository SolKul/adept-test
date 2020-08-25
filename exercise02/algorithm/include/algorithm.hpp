#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "adept.h"

namespace algorithm{
using adept::adouble;

void func_2(int n, const adouble* x, int m, adouble* y);

void func_2_jacobian(
    int n, // Number of input values
    const double* x_val, // Input values
    int m, // Number of output values
    double* y_val, // Output values
    double* jac);

} //namespace algorithm
 
#endif //_ALGORITHM_H_