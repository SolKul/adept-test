#include <iostream>
#include "algorithm.h"

using adept::adouble;


adouble func_1(const adouble x[2]) {
#ifdef ADEPT_NO_AUTOMATIC_DIFFERENTIATION
  std::cout << "double型が呼び出された！" << std::endl;
#else
  std::cout << "adouble型が呼び出された！" << std::endl;
#endif
  adouble y = 4;
  adouble s = 2.0*x[0] + 3.0*x[1]*x[1];
  y *= sin(s);
  return y;
}