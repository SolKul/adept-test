#include <vector>
#include <iostream>
#include "mylib.hpp"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(){
  // systemインスタンスを生成
  mylib::LVSystem lv_system(2.0, 3.0, 4.0, 5.0);
  mylib::LVSystem::state_type state = {0.5,1};

  std::cout << "time=0 " << "x=" << state[0] << " " << "y=" << state[1] << std::endl;

  // 単純なオイラー法のStepper
  mylib::euler <mylib::LVSystem::state_type>euler_stepper;

  // Observerオブジェクト生成
  std::vector< mylib::LVSystem::state_type > x_vec;
  std::vector< double > times;
  mylib::Observer<mylib::LVSystem::state_type> observer(x_vec,times);

  // 数値積分し、初期値問題を解く
  std::size_t steps = mylib::integrate_const<
  mylib::euler<mylib::LVSystem::state_type> ,
  mylib::LVSystem ,
  mylib::LVSystem::state_type ,
  double ,
  mylib::Observer<mylib::LVSystem::state_type> >(
    euler_stepper,
    lv_system,
    state,
    0.0,
    5.0,
    0.05,
    observer);

  std::cout << "time=5 " << "x=" << state[0] << " " << "y=" << state[1] << std::endl;

  // グラフ表示するために転置する。
  int variable_num = lv_system.variable_num;
  std::vector<std::vector<double>> x_vec_t(variable_num,std::vector<double>(steps+1));
  for(std::size_t i=0; i<=steps; i++){
    for(std::size_t j=0; j<variable_num; j++){
      x_vec_t[j][i]=x_vec[i][j];
    }
  }

  std::map<std::string, std::string> args1{
    {"ls","--"},
    {"marker","o"},
    {"label", "x"}
  };
  std::map<std::string, std::string> args2{
    {"ls","-."},
    {"marker","v"},
    {"label", "y"}
  };
  plt::plot(times,x_vec_t[0],args1);
  plt::plot(times,x_vec_t[1],args2);
  plt::legend();

  plt::save("./TimeTransition.png");

  return 0;
}
