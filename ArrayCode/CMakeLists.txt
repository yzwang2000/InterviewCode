message("开始构建 ArrayCode")

cmake_minimum_required(VERSION 3.10)
project(ArrayCode LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(arrayCode OBJECT ${srcs})
target_include_directories(arrayCode PUBLIC
                            include)