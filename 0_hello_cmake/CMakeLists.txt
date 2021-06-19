cmake_minimum_required(VERSION 3.1)  # 指定 cmake 的最低版本

project(HELLO_CMAKE) # 指定项目名称，编程语言(可忽略)

set(SRCS hello_cmake.cpp) # set 显示设置变量，在这里是指定源文件

message(STATUS "CMAKE_SOURCE_DIR =" ${CMAKE_SOURCE_DIR})  # message 输出信息，STATUS 能够指定前缀  `-`
message(STATUS "PROJECT_SOURCE_DIR=" ${PROJECT_SOURCE_DIR})
message(STATUS "HELLO_CMAKE_SOURCE_DIR=" ${HELLO_CMAKE_SOURCE_DIR})


add_executable(hello_cmake ${SRCS}) # 指定编译生成可执行文件，${} 引用变量  