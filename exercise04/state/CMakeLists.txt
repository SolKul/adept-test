cmake_minimum_required(VERSION 3.12)
project(algorithm_lib 
  VERSION 1.0.0
  DESCRIPTION "state"
  LANGUAGES CXX)

# Target : adept
add_library(adept STATIC IMPORTED)
set_property(TARGET adept
            PROPERTY IMPORTED_LOCATION /usr/local/lib/libadept.a)

# Targe : OpenMP
find_package(OpenMP REQUIRED)

if(NOT OpenMP_FOUND)
    message(FATAL_ERROR "OpenMP NOT FOUND")
endif()

# Target : GSL
find_package(GSL REQUIRED)

target_link_libraries(adept INTERFACE OpenMP::OpenMP_CXX)

# Targe : banana_ad
add_library(banana_ad STATIC rosenbrock_banana_function.cpp) 

target_include_directories(banana_ad INTERFACE .)
target_link_libraries(banana_ad INTERFACE adept)

# Targe : banana_noad
add_library(banana_noad STATIC rosenbrock_banana_function.cpp) 

target_compile_options(banana_noad PRIVATE -DADEPT_NO_AUTOMATIC_DIFFERENTIATION)
target_include_directories(banana_noad INTERFACE .)
target_link_libraries(banana_noad INTERFACE adept)

# Target : state
add_library(state STATIC state.cpp)

target_include_directories(state INTERFACE .)
target_link_libraries(state INTERFACE banana_ad banana_noad ${GSL_LIBRARIES})