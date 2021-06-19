cmake_minimum_required(VERSION 3.1) # 指定 cmake 的最低版本

project(install) # 指定项目名称，编程语言(可忽略)

add_subdirectory(src) # 指定子目录

# 指定文件的安装路径
install(FILES COPYRIGHT readme.md DESTINATION share/doc)
# 指定脚本安装路径
install(PROGRAMS run_hello.sh DESTINATION bin)
# 指定目录的安装路径
install(DIRECTORY doc/ DESTINATION share/doc)
