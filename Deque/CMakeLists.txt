message("开始构建 Deque")

cmake_minimum_required(VERSION 3.10)
project(Deque LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(deque OBJECT ${srcs})
target_include_directories(deque PUBLIC
                            include)