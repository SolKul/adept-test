cmake_minimum_required(VERSION 3.9)
project(helper_lib 
  VERSION 1.0.0
  DESCRIPTION "helper"
  LANGUAGES CXX)

add_library(helper STATIC ./src/display.cpp)
target_include_directories(helper INTERFACE ./include)