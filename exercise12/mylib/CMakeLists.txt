cmake_minimum_required(VERSION 3.12)
project(my_library 
  VERSION 1.0.0
  DESCRIPTION "my library"
  LANGUAGES CXX)

add_library(mylib STATIC ./mylib.cpp)
target_include_directories(mylib INTERFACE ./)