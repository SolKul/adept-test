cmake_minimum_required(VERSION 3.9)
project(adept-test CXX)

# --- adept require ---
# target : adept
add_library(adept STATIC IMPORTED)
set_property(TARGET adept
            PROPERTY IMPORTED_LOCATION /usr/local/lib/libadept.a)

# target : OpenMP
find_package(OpenMP REQUIRED)

if(NOT OpenMP_FOUND)
    message(FATAL_ERROR "OpenMP NOT FOUND")
endif()

# target : LAPACK
find_package(LAPACK)

target_link_libraries(adept INTERFACE OpenMP::OpenMP_CXX ${LAPACK_LIBRARIES})
# --- adept require ---

add_subdirectory(helper)

add_executable(main_app main.cpp)
target_link_libraries(main_app adept helper)