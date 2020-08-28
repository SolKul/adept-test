#include "helper.hpp"
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
//placeholdersの衝突を回避するため(要調査)
#include <boost/python/numpy.hpp>
namespace py = boost::python;
namespace np = boost::python::numpy;

namespace helper{
void display_1d_array(std::string name,int size, const double* x){
  Py_Initialize();
  np::initialize();

  py::tuple shape = py::make_tuple(size);
  py::tuple stride = py::make_tuple(sizeof(double));
  np::dtype dt = np::dtype::get_builtin<double>();
  np::ndarray py_array = np::from_data(&x[0], dt, shape, stride, py::object());

  std::cout << std::endl
            << name << ":" << std::endl
            << py::extract<char const *>(py::str(py_array)) << std::endl;
}

void display_2d_array(std::string name,int* size, const double* x){
  // xは2次元配列x[0][0]のポインタ(アドレス)
  // xはポインタでしかないのでx[0][0]とはアクセスできない
  // c/c++は配列は要素の長さを保持していないので
  Py_Initialize();
  np::initialize();

  py::tuple shape = py::make_tuple(size[0],size[1]);
  py::tuple stride = py::make_tuple(sizeof(double)*size[1],sizeof(double));
  np::dtype dt = np::dtype::get_builtin<double>();
  np::ndarray py_array = np::from_data(
    x, dt, 
    shape, 
    stride, 
    py::object());

  std::cout << std::endl
            << name << ":" << std::endl
            << py::extract<char const *>(py::str(py_array)) << std::endl;
}

}//namespace helper