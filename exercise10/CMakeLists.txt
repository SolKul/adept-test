cmake_minimum_required(VERSION 3.9)
project(matplot-test CXX)

# target : Boost
# boost::numeric::odeintはヘッダオンリーライブラリなので、
# find_boostした後、ターゲット、Boost::headersをリンクすればいい。
find_package(Boost REQUIRED)

# target : python
find_package(Python3 COMPONENTS Development NumPy REQUIRED)
message("Python3_INCLUDE_DIRS : ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES : ${Python3_LIBRARIES}")

# target : matplot
add_library(matplot INTERFACE)
target_include_directories(matplot INTERFACE /data/matplotlib-cpp/ ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(matplot INTERFACE ${Python3_LIBRARIES})

# targe : main
add_executable(main_app main.cpp)
target_link_libraries(main_app matplot Boost::headers)
