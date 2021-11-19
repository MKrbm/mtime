cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)

project(test VERSION 0.1.0) # set project version
message("None = ${CMAKE_C_FLAGS}")
message("Debug = ${CMAKE_C_FLAGS_DEBUG}")
message("Release = ${CMAKE_C_FLAGS_RELEASE}")

# add_subdirectory(./mtime) #call /LoopAlgo/CMakeLists.txst

add_executable(test test.cpp)
add_executable(test2 test2.cpp) 








