#ifndef _helper_H_
#define _helper_H_

#include <iostream>
#include <iomanip>
#include <sstream>

namespace helper{
void display_1d_array(std::string name,int n, const double* x);
void display_2d_array(std::string name,int* size, const double* x);
}//namespace helper

#endif //_helper_H_