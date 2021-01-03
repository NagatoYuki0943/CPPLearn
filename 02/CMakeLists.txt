cmake_minimum_required(VERSION 3.17)
project(02)

set(CMAKE_CXX_STANDARD 20)
#让exe文件可以单独执行
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
#加入header目录
include_directories(header)
add_executable(02 main.cpp)

add_executable(tong_xun_lu files/tong_xun_lu.cpp)