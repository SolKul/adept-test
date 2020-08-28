cmake_minimum_required(VERSION 3.12)
project(header-test CXX)

add_library(sample_1 STATIC sample_1.cpp)
target_include_directories(sample_1 INTERFACE .)

add_library(sample_2 STATIC sample_2.cpp)
target_include_directories(sample_2 INTERFACE .)