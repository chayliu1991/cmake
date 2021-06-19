
set(LIBSRCS hello.cpp)  # 设置库的源文件

add_library(hello_static STATIC ${LIBSRCS}) # 添加静态库
add_library(hello_dynamic SHARED ${LIBSRCS}) # 添加静态库

set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello") # 指定动态库最终生成的名称
set_target_properties(hello_dynamic PROPERTIES OUTPUT_NAME "hello")# 指定动态库最终生成的名称
set_target_properties(hello_dynamic PROPERTIES VERSION 1.2 SOVERSION 1) # 指定动态库的版本号,API 版本号

link_directories(${PROJECT_SOURCE_DIR}/build/lib)
add_executable(hello main.cpp) # 添加可执行文件
target_link_libraries(hello libhello.a) # 链接库

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

# 指定库的安装路径
install(TARGETS hello_static hello_dynamic
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

# 指定头文件的暗转路径
install(FILES hello.h DESTINATION include)

# 指定可执行文件的安装路径
install(TARGETS hello RUNTIME DESTINATION bin)
