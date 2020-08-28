#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "adept.h"



// 以下はADEPT_NO_AUTOMATIC_DIFFERENTIATIONが宣言されておらず、
// 自動微分が有効な場合有効になる。
#ifndef ADEPT_NO_AUTOMATIC_DIFFERENTIATION
adept::adouble func_1(const adept::adouble x[2]);
#endif //ADEPT_NO_AUTOMATIC_DIFFERENTIATION

double func_1(const double x[2]);
// 自動微分が有効な場合、↑の同名の関数も宣言されてしまうが、
// その関数を使わないのであれば、宣言しておいて、定義がなくてもいい

double func_1_and_gradient(
    const double x_val[2], // Input values
    double dy_dx[2]);

#endif //ALGORITHM_H