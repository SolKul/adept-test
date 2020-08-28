#include <iostream>
#include "helper.hpp"
#include <adept_arrays.h>
#include <random>

using adept::Vector;
using adept::aVector;
using adept::Real;
using adept::aReal;
using adept::Matrix;
using adept::Stack;

int main() {
  int n=100;
  std::random_device rnd;     // 非決定的な乱数生成器
  std::mt19937 mt(rnd());            // メルセンヌ・ツイスタの32ビット版、引数は初期シード
  std::uniform_int_distribution<> rand_uni(-9, 9);        // [-10, 10] 範囲の一様乱数

  Stack stack;

  aVector x(n);
  Matrix m_1(n,n);
  for (int i = 0; i < n; ++i) {
    x(i)=rand_uni(mt);
    for (int j = 0; j < n; ++j) {
      m_1(i,j)= rand_uni(mt);
    }
  }

  aVector y(n);
  stack.new_recording();
  y = adept::matmul(m_1,x);

  stack.independent(x);
  stack.dependent(y);
  Real* jac;
  jac = new Real[n*n];
  stack.jacobian_reverse(jac);
  int size[2] = {n,n};
  helper::display_2d_array("dy_dx",&size[0],&jac[0]);
  return 0;
}