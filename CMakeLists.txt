project(AnyHLS)
cmake_minimum_required(VERSION 3.4.3)

find_package(AnyDSL_runtime REQUIRED)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

#add_subdirectory(src)
add_subdirectory(test)
