cmake_minimum_required(VERSION 3.0.0)


project(mtime_test VERSION 0.1.0) # set project version
message("None = ${CMAKE_C_FLAGS}")
message("Debug = ${CMAKE_C_FLAGS_DEBUG}")
message("Release = ${CMAKE_C_FLAGS_RELEASE}")

add_subdirectory(./mtime) #call /LoopAlgo/CMakeLists.txst

add_executable(debug debug.cpp test_func.cpp) # add executable

target_link_libraries(debug mtime_lib) # link library

configure_file(MainConfig.h.in ${PROJECT_SOURCE_DIR}/MainConfig.h)






