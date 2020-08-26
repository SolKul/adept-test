#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "adept.h"

namespace algorithm{
using adept::adouble;

adouble michaelis(
    const double conce,
    const adouble v_max,
    const adouble k_m);

void func_res(
    const adouble v_max,
    const adouble k_m,
    int n,
    const double* matrix_con,
    const double* conc_rate,
    adouble* residual);

void func_res_jac(
    const double* x_val,
    int n,
    const double* matrix_con,
    const double* conc_rate,
    double* res_val,
    double* jac);

} //namespace algorithm
 
#endif //_ALGORITHM_H_