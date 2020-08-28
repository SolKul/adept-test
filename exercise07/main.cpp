#include <iostream>
#include "helper.hpp"
#include <adept_arrays.h>

using adept::Vector;
using adept::aVector;
using adept::Real;
using adept::aReal;
using adept::Matrix;
using adept::Stack;

int main() {
  Stack stack;

  int n=2;
  aVector x(n);
  x << 1,2;
  Matrix m_1(n,n);
  m_1 <<
    1,2,
    3,4;
  aVector y(n);
  stack.new_recording();
  y = adept::matmul(m_1,x);

  stack.independent(x);
  stack.dependent(y);
  Real* jac;
  jac = new Real[n*n];
  stack.jacobian_reverse(jac);
  // double *p=jac.data();
  int size[2] = {n,n};
  helper::display_2d_array("dy_dx",&size[0],&jac[0]);
  return 0;
}