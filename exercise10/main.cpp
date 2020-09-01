#include <vector>
#include <array>
#include "boost/numeric/odeint.hpp"
#include "matplotlibcpp.h"

namespace odeint = boost::numeric::odeint;
namespace plt = matplotlibcpp;

using state_type = std::array<double,2>;

// メモ：vector等による二次元配列
// vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))
// https://atcoder.jp/contests/APG4b/tasks/APG4b_t

struct LVSystem {
public:
   double alpha;
   double beta;
   double gamma;
   double delta;
public:
   LVSystem(double alpha_,double beta_,double gamma_,double delta_)
      :alpha(alpha_),beta(beta_),gamma(gamma_),delta(delta_){}

   void operator()(const state_type& x, state_type& dx, double t){
      dx[0] = x[0] * (alpha - beta* x[1]);
      dx[1] = - x[1] * (gamma - delta * x[0]);
   }
};

struct Observer
{
    std::vector< state_type >& m_states;
    std::vector< double >& m_times;

    Observer( std::vector< state_type > &states , std::vector< double > &times )
    : m_states( states ) , m_times( times ) { }

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }
};

int main(){
  LVSystem lv_system(2.0, 3.0, 4.0, 5.0);
  state_type state = {1.0,0.5};

  std::cout << "time=0 " << "x=" << state[0] << " " << "y=" << state[1] << std::endl;

  odeint::euler<state_type> stepper;

  std::vector< state_type > x_vec;
  std::vector< double > times;
  Observer observer(x_vec,times);

  //time = 0 -> 5まで、時間発展を計算してみる
  std::size_t steps = odeint::integrate_const(
          stepper, lv_system, state, 0.0, 5.0, 0.05,observer
      );

  std::cout << "time=5 " << "x=" << state[0] << " " << "y=" << state[1] << std::endl;

  // グラフ表示するために転置する。
  std::vector<std::vector<double>> x_vec_t(2,std::vector<double>(steps+1));
  for(std::size_t i=0; i<=steps; i++){
    x_vec_t[0][i]=x_vec[i][0];
    x_vec_t[1][i]=x_vec[i][1];
  }

  plt::plot(times,x_vec_t[0]);
  plt::plot(times,x_vec_t[1]);

  plt::save("./sample1.png");

  return 0;
}
