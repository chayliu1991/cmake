cmake_minimum_required(VERSION 3.1)

project(MYMODULE)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake) # 指定 module 的路径


add_subdirectory(src)
