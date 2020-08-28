cmake_minimum_required(VERSION 3.12)
project(header-test CXX)

# target : calculation is imported
add_subdirectory(samples)

# targe : mainapp
add_executable(main_app main.cpp)

target_link_libraries(main_app sample_1 sample_2)