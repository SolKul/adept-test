cmake_minimum_required(VERSION 3.9)
project(adept-test)

add_executable(exercise03 main.cpp)

add_subdirectory(./algorithm)
add_subdirectory(./helper)

target_link_libraries(exercise03 algorithm helper)