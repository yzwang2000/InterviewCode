cmake_minimum_required(VERSION 3.10)
project(Examples LANGUAGES CXX)

# 寻找依赖包
find_package(OpenMP REQUIRED)

# 通过全局变量, 让之后所创建的所有对象都共享同样的属性
# setting compiler flags 在 Debug 和 Release 下都会执行
set(CMAKE_C_FLAGS    "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
# message("${CMAKE_CXX_FLAGS}")

# 在 Debug 模型下的编译器标志
set(CMAKE_C_FLAGS_DEBUG    "${CMAKE_C_FLAGS_DEBUG}    -Wall -O0")
# 调试 C++ 程序, 理应添加 '-g', 但是这里没有添加是因为 set(CMAKE_BUILD_TYPE Debug) 就会自动添加
set(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG}  -Wall -O0")

# 设置 Release 模式下编译器的标志
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# 检查是能够支持 C++20 标准, 支持不了就报错
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出的位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(ArrayCode)
add_subdirectory(ListCode)
add_subdirectory(HashCode)
add_subdirectory(SSCode)
add_subdirectory(Deque)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC arrayCode listCode hashCode OpenMP::OpenMP_CXX ssCode deque)