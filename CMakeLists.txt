cmake_minimum_required(VERSION 3.9)
project(matplot-test CXX)

# targe : python
find_package(Python3 COMPONENTS Development NumPy)
message("Python3_INCLUDE_DIRS : ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES : ${Python3_LIBRARIES}")

add_library(matplot INTERFACE)
target_include_directories(matplot INTERFACE /data/matplotlib-cpp/ ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(matplot INTERFACE ${Python3_LIBRARIES})

# targe : main
add_executable(main_app main.cpp)
target_link_libraries(main_app matplot)
