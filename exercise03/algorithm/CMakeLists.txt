cmake_minimum_required(VERSION 3.9)
project(algorithm_lib 
  VERSION 1.0.0
  DESCRIPTION "test-algorithm"
  LANGUAGES CXX)

add_library(algorithm STATIC ./src/algorithm.cpp)
target_include_directories(algorithm INTERFACE ./include)

# ターゲットadept
add_library(adept STATIC IMPORTED)
set_property(TARGET adept
            PROPERTY IMPORTED_LOCATION /usr/local/lib/libadept.a)

# find OpenMP
find_package(OpenMP REQUIRED)

if(NOT OpenMP_FOUND)
    message(FATAL_ERROR "OpenMP NOT FOUND")
endif()

target_link_libraries(adept INTERFACE OpenMP::OpenMP_CXX)
target_link_libraries(algorithm INTERFACE adept)