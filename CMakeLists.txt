cmake_minimum_required(VERSION 3.9)
project(adept-test CXX)

add_executable(main_app main.cpp)

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
target_link_libraries(main_app adept)