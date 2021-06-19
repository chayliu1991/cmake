cmake_minimum_required(VERSION 3.1) #指定 cmake 的最低版本


include_directories(${PROJECT_SOURCE_DIR}/include) # 指定头文件的目录

aux_source_directory(. SRCS)  # 当前目录下的所有文件都设置为源文件

add_library(math_dynamic SHARED ${SRCS}) # 指定生成动态库
add_library(math_static STATIC ${SRCS}) # 指定生成静态库

set_target_properties(math_dynamic PROPERTIES OUTPUT_NAME "math") # 指定动态库最终生成的名称
set_target_properties(math_dynamic PROPERTIES VERSIONS 1.1 SOVERSION 1) # 指定动态库的版本号

set_target_properties(math_static PROPERTIES OUTPUT_NAME "math") # 指定静态库最终生成的名称

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) # 指定库最终的生成路径
