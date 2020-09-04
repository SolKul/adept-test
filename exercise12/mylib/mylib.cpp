#include "mylib.hpp"

namespace mylib{
LVSystem::LVSystem(
  double alpha_,
  double beta_,
  double gamma_,
  double delta_):
    alpha(alpha_),
    beta(beta_),
    gamma(gamma_),
    delta(delta_){}

void LVSystem::operator()(
  const state_type& x,
  state_type& dx,
  double t){
    dx[0] = x[0] * (alpha - beta* x[1]);
    dx[1] = - x[1] * (gamma - delta * x[0]);
  }
}// mylib