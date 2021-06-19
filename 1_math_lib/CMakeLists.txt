cmake_minimum_required(VERSION 3.1)  # 指定 cmake 的最低版本

project(ADD_LIB) # 指定项目名称，编程语言(可忽略)

add_subdirectory(src) # 指定子目录

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib) # 设置库的查找目录

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) # 设置可执行文件的生成路径

set(SRCS  main.cpp)  # 当前目录下的所有文件都设置为源文件

add_executable(main ${SRCS}) # 增加可执行文件
target_link_libraries(main math)  # 指定链接库