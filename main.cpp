#include <matplotlibcpp.h>
#include <vector>

namespace plt = matplotlibcpp;

double func(double x){
  double y = sin(x);
  return y;
}


int main(){

  
  int sec_num = 100;
  double end_x=10;
  double delta_x=end_x/sec_num;

  std::vector<double> x(sec_num),y(sec_num);

  for(int i=0;i<100;i++){
    x[i]=delta_x * i;
    y[i]=func(x[i]);
  }

  plt::plot(x,y);

  plt::save("./sample1.png");

  return 0;
}
