message("开始构建 BinaryTree")

cmake_minimum_required(VERSION 3.10)
project(BinaryTree LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.hpp)

add_library(binaryTree OBJECT ${srcs})
target_include_directories(binaryTree PUBLIC
                            include)