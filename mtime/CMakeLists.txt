cmake_minimum_required(VERSION 3.0.0)


project(mtime_lib VERSION 0.1.0) 


add_library(mtime_lib 
  STATIC 
  ./src/mtime.cpp)

target_compile_features(mtime_lib PUBLIC cxx_std_20)
target_include_directories(mtime_lib INTERFACE ./include)






