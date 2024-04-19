message("开始构建 ListCode")

cmake_minimum_required(VERSION 3.10)
project(ListCode LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(listCode OBJECT ${srcs})
target_include_directories(listCode PUBLIC
                            include)