#include "../include/display.hpp"

void display_array(std::string name,int n, const double* x){
    std::string disp = name + " =";
    std::string paren_start="(";
    std::string comma = ",";
    std::string paren_end=")";
    disp +=  paren_start;
    for (int i =0; i<n-1;i++){
      std::stringstream ss;
      ss << std::fixed << std::setprecision(2) << x[i];
      disp +=  ss.str() + comma;
    }
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << x[n-1];
    disp +=  ss.str();
    disp +=  paren_end;
    std::cout << disp << std::endl;
}