cmake_minimum_required(VERSION 3.12)
project(adept-test CXX)

# target : calculation is imported
add_subdirectory(calculation)

# targe : mainapp
add_executable(main_app main.cpp)

target_link_libraries(main_app calculation)