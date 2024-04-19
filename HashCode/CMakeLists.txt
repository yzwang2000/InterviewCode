message("开始构建 HashCode")

cmake_minimum_required(VERSION 3.10)
project(HashCode LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(hashCode OBJECT ${srcs})
target_include_directories(hashCode PUBLIC
                            include)