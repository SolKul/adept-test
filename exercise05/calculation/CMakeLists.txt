cmake_minimum_required(VERSION 3.12)
project(adept-test CXX)

# target : adept
add_library(adept STATIC IMPORTED)
set_property(TARGET adept
            PROPERTY IMPORTED_LOCATION /usr/local/lib/libadept.a)

# target : OpenMP
find_package(OpenMP REQUIRED)

if(NOT OpenMP_FOUND)
    message(FATAL_ERROR "OpenMP NOT FOUND")
endif()

target_link_libraries(adept INTERFACE OpenMP::OpenMP_CXX)

# Targe : algorithm_ad
add_library(algorithm_ad STATIC algorithm.cpp) 

target_include_directories(algorithm_ad INTERFACE .)
target_link_libraries(algorithm_ad INTERFACE adept)

# Targe : algorithm_noad
add_library(algorithm_noad STATIC algorithm.cpp) 

target_compile_options(algorithm_noad PRIVATE -DADEPT_NO_AUTOMATIC_DIFFERENTIATION)
target_include_directories(algorithm_noad INTERFACE .)
target_link_libraries(algorithm_noad INTERFACE adept)

# target : calculation
add_library(calculation STATIC gradient.cpp)

target_link_libraries(calculation INTERFACE algorithm_ad algorithm_noad)
