cmake_minimum_required(VERSION 3.12)
project(algorithm_lib 
  VERSION 1.0.0
  DESCRIPTION "test-minimization"
  LANGUAGES CXX)

add_executable(main_app test_gsl_interface.cpp)

add_subdirectory(state)
target_link_libraries(main_app state)