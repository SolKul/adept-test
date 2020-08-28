cmake_minimum_required(VERSION 3.12)
project(helper_lib 
  VERSION 1.0.0
  DESCRIPTION "helper"
  LANGUAGES CXX)

find_package(Python3 COMPONENTS Development)
find_package(Boost COMPONENTS python38 numpy38 REQUIRED)

add_library(helper SHARED helper.cpp)
target_include_directories(helper INTERFACE .)

target_include_directories(helper PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(helper PRIVATE ${Boost_LIBRARIES} ${Python3_LIBRARIES})