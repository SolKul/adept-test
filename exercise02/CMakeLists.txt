cmake_minimum_required(VERSION 3.9)


add_executable(exercise02 main.cpp)

# ターゲットadept
# add_library(adept STATIC IMPORTED)
# set_property(TARGET adept
#             PROPERTY IMPORTED_LOCATION /usr/local/lib/libadept.a)

# # find OpenMP
# find_package(OpenMP REQUIRED)

# if(NOT OpenMP_FOUND)
#     message(FATAL_ERROR "OpenMP NOT FOUND")
# endif()


add_subdirectory(./algorithm)
add_subdirectory(./helper)

# target_link_libraries(adept INTERFACE OpenMP::OpenMP_CXX)
# target_link_libraries(main_app adept algorithm)
target_link_libraries(exercise02 algorithm helper)