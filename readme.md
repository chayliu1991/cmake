# 语法特性

- 变量使用 `${}` 方式取值，但是在 `IF`  控制语句中是直接使用变量名。
- 指令(参数 1 参数 2...)  ，参数使用括弧括起，参数之间使用空格或分号分开。
- 指令是大小写无关的，参数和变量是大小写相关的。 
- 无行结束符，注释使用 `#`。

# 编译工程
## 设置编译规则
- 包含源文件的子文件夹包含 CMakeLists.txt 文件，主目录的 CMakeLists.txt 通过 `add_subdirectory` 添加子目录即可。
- 包含源文件的子文件夹未包含 CMakeLists.txt 文件，子目录编译规则体现在主目录的 CMakeLists.txt 中。

## 构建方式
- 内部构建(in-source build)会在同级目录下产生一大堆中间文件，这些中间文件并不是我们最终所需要的，和工程源文件放在一起会显得杂乱无章，不推荐使用。
- 外部构建(out-of-source build)会将编译输出文件与源文件放到不同目录中，推荐使用。

# 常用变量

## 路径

- `PROJECT_NAME ` ： 返回通过 PROJECT 指令定义的项目名称
- `CMAKE_BINARY_DIR`，`PROJECT_BINARY_DIR`，`<projectname>_BINARY_DIR` ： 如果是 in-source build，指的就是工程顶层目录，如果是 out-of-source  build编译，指的是工程编译发生的目录
- `CMAKE_SOURCE_DIR`，`PROJECT_SOURCE_DIR`，`<projectname>_SOURCE_DIR` ： 不论采用何种编译方式，都是工程顶层目录
- `CMAKE_CURRENT_SOURCE_DIR  ` ： 指的是当前处理的 CMakeLists.txt 所在的路径
- `CMAKE_CURRRENT_BINARY_DIR ` ： 如果是 in-source build，与 `CMAKE_CURRENT_SOURCE_DIR` 一致，如果是 out-of-source build，指的是 target 编译目录，`add_subdirectory` 可以修改这个变量的值，设置 `EXECUTABLE_OUTPUT_PATH` 并不会对这个变量造成影响
- `CMAKE_CURRENT_LIST_FILE  ` ：输出调用这个变量的 CMakeLists.txt 的完整路径
- `CMAKE_CURRENT_LIST_LINE` ： 输出这个变量所在的行
- `EXECUTABLE_OUTPUT_PATH` ： 可执行文件输出的存放路径
- `LIBRARY_OUTPUT_PATH` ： 库文件输出的存放路径
- `CMAKE_INSTALL_PREFIX` ： 目标文件的安装目录，默认值为 `/usr/local/bin`
- `CMAKE_MODULE_PATH`  ：自定义的 CMake 模块的路径
- `CMAKE_INCLUDE_CURRENT_DIR`  ： 自动添加 `CMAKE_CURRENT_SOURCE_DIR  ` 和 `CMAKE_CURRRENT_BINARY_DIR ` 到当前的 CMakeLists.txt 中处理
- `CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE`  ： 将工程提供的头文件目录始终置于系统文件目录之前

## 系統信息

- `CMAKE_MAJOR_VERSION` ： CMake 的主版本号，例如 2.3.6 中的 2
- `CMAKE_MINOR_VERSION` ：CMake 的次版本号，例如 2.3.6 中的 3
- `CMAKE_PATCH_VERSION` ：CMake 的补丁等级，例如 2.3.6 中的 6
- `CMAKE_SYSTEM_NAME` ： 系统名称，包含版本号，例如 Linux-2.6.28
- `CMAKE_SYSTEM_NAME` ： 系统名称，不包含版本号，例如 Linux 
- `CMAKE_SYSTEM_VERSION` ： 系统版本号，例如 2.6.28
- `CMAKE_SYSTEM_PROCESSOR` ： 处理器名称，例如 I386
- `UNIX` ： 在所有的类 UNIX 平台为 TRUE，包括 MacOS 和 Cygwin
- `WIN32` ： 在所有的 win32 平台为 TRUE，包括 Cygwin  

## 开关选项

- `CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS` ： 开关选项，用来控制 if else 的书写方式
- `BUILD_SHARED_LIBS` ： 开关选项，默认为静态库

## 编译选项

- `CMAKE_BUILD_TYPE` ： 编译类型，Debug， Release
- `CMAKE_C_COMPILER` ： 指定 C 编译器
- `CMAKE_CXX_COMPILER` ： 指定 C++ 编译器
- `CMAKE_C_FLAGS`  ： 设置 C 编译选项，也可以通过 `add_definitions()` 添加
- `CMAKE_CXX_FLAGS` ： 设置 C++ 编译选项，也可以通过 `add_definitions()` 添加

## 环境变量

- `$ENV{NAME}`：调用系统的环境变量。
- `SET(ENV{VAR} VALUE)`：设置环境变量。

# 重要指令

## cmake_minimum_required 

指定 CMake 的最小版本要求。

语法：

```
cmake_minimum_required(VERSION versionNumber [FATAL_ERROR])
```

示例：

```
cmake_minimum_required(VERSION 2.8.3) # 如果 cmake 版本小与 2.8.3，则出现严重错误，整个过程中止
```

## project 

定义工程名称，并可指定工程支持的语言。支持的语言列表是可以忽略的，默认情况表示支持所有语言。  

语法：

```
project(projectname [CXX] [C] [Java])
```

隐含定义了两个变量 `<projectname>_BINARY_DIR` 和 `<projectname>_SOURCE_DIR`

示例：

```
project(test)
```

## set

显式的定义变量。

语法：

```
SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
```

示例：

```
set(SRC hello.cpp)
```

## message

向终端输出用户定义的信息。

语法：

```
MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] "message to display" ...)
```

- `SEND_ERROR`：产生错误，生成过程被跳过
- `SATUS`：输出前缀为 `-` 的信息
- `FATAL_ERROR`：立即终止所有 cmake 过程  

示例：

```
message("PROJECT_NAME=",${PROJECT_NAME})
```

## add_compile_options

添加编译参数。

语法：

```
add_compile_options()
```

示例：

```
add_compile_options(-Wall -std=c++11 -O2)
```

## include_directories

向工程添加多个特定的头文件搜索路径。

语法：

```
include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 …)
```

示例：

```
include_directories(/usr/include/ ./include)
```

## add_library

生成库文件。

语法：

```
add_library(libname [SHARED|STATIC|MODULE] [EXCLUDE_FROM_ALL] source1 source2 … sourceN)
```

- `SHARED`：动态库
- `STATIC`：静态库
- `MODULE`：在使用 dyld 的系统有效，如果不支持 dyld，则被当作 SHARED 对待
- `EXCLUDE_FROM_ALL`：这个库不会被默认构建，除非有其他的组件依赖或者手工构建

示例：

```
add_library(hello SHARED ${SRC})
```

## set_target_properties

设置输出的名称，对于动态库，可以用于指定动态库的版本和 API 版本。

语法：

```
set_target_properties(target1 target2 ... PROPERTIES pro1 value1 pro2 value2 ...)
```

获取属性可以使用：

```
get_target_property(VAR target property)
```

示例：

```
set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1) # VERSION 指代动态库版本，SOVERSION 指代 API 版本
```

## link_directories

向工程添加多个特定的库文件搜索路径。

语法：

```
link_directories(dir1 dir2 …)  
```

示例：

```
link_directories(/usr/lib ./lib)
```

## target_link_libraries

为 target 添加需要链接的共享库。

语法：

```
target_link_libraries(target library1 <debug | optimized> library2…)
```

示例：

```
target_link_libraries(main hello)
# 也可以写成
target_link_libraries(main libhello.so)
# 链接静态库
target_link_libraries(main libhello.a)
```

## install

安装文件

语法：

### 安装目标文件

```
install(TARGETS targets [[ARCHIVE | LIBRARY | RUNTIME]
	[DESTIONATION <dir>]
	[PERMISSIONS permissions..]
	[CONFIGURATIONS [Debug | Release | ...]]
	[COMPONENT <component>]
	[OPTIONAL]
	[...])
```

- `ARCHIVE` ： 静态库文件
- `LIBRARY` ： 动态库文件
- `RUNTIME` ： 可执行文件
- `DESTINATION` ： 定义安装路径，如果是绝对路径则覆盖 `CMAKE_INSTALL_PERFIX`，否则是指相对 `CMAKE_INSTALL_PERFIX` 的相对路径

示例：

```
install(TARGETS myrun mylib mystaticlib
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION libstatic
	)
```

上面的例子将：

- 二进制文件 myrun 安装到 `${CMAKE_INSTALL_PERFIX}/bin` 目录
- 二进制文件 libmylib 安装到 `${CMAKE_INSTALL_PERFIX}/lib` 目录
- 二进制文件 liblibstatic 安装到 `${CMAKE_INSTALL_PERFIX}/libstatic` 目录

### 安装普通文件

```
install(FILES files ... DESTINATION <dir>
		[PERMISSIONS permissions...]
		[CONFIGURATUONS [Debug | Release | ...]]
		[COMPONENT <component>]
		[RENAME <name>]
		[OPTIONAL])
```

可以指定权限，如果不指定，则默认是 644 权限。

### 目录安装

```
install(DIRECTORY dirs... DESTINATION <dir>
	[FILE_PERMISSIONS permissions...]
	[DIRECTORY_PERMISSIONS permissions...]
	[USE_SOURCE_PERMISSIONS]
	[CONFIGURATIONS [Debug | Release]...]
	[COMPONENT <component>]
	[[PATTERN <pattern> | REGEX <regex>] [EXCLUDE] [PERMISSIONS permissions...]]
	[...])
```

## add_executable

增加可执行文件。

语法：

```
add_library(exename source1 source2 … sourceN)
```

示例：

```
add_executable(main main.cpp)
```

## add_subdirectory

向当前工程添加存放源文件的子目录，并可以指定中间二进制和目标二进制存放的位置。

语法：
```
add_subdirectory(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
```

示例：
```
add_subdirectory(src)
```

## aux_source_directory

发现一个目录下所有的源代码文件并将列表存储在一个变量中，这个指令临时被用来自动构建源文件列表。

语法：
```
aux_source_directory(dir VARIABLE)
```

示例：
```
aux_source_directory(. SRC)
```

## add_definitions

向 C/C++ 编译器添加 `-D` 定义。

语法：
```
add_definitions(-DMACRO1 -DMACRO2)
```

示例：

```
add_definitions(-DENABLE_DEBUG)
```

使用 `cmake` 指定时也可以定义宏：

```
cmake -DENABLE_DEBUG=on
cmake -DENABLE_DEBUG=off
```

## add_dependencies

定义 target 依赖的其他 target，确保在编译本 target 之前，其他的 target 已经被构建。

语法：
```
add_dependencies(target -name depend -target1 depend -target2 ...)
```

示例：
```
add_dependencies(main a.so b.so)
```

## add_test 与 enable_testing

`enable_testing()` 用来控制 Makefile 是否构建 test 目标，一般放在工程的主 CMakeLists.txt 中。

语法：
```
add_test(testname Exename arg1 arg2 ...)
```

`testname` 是自定义的 test 名称，`Exename` 可以是构建的目标文件也可以是外部脚本等。如果没有在同一个 CMakeLists.txt 中打开  `enable_testing()` ，任何 `add_test` 都是无效的。

示例：

```
add_test(mytest ${PROJECT_BINARY_DIR}/bin/main)
enable_testing()
```

生成 Makefile 后，就可以运行 make test 来执行测试。

## file

文件操作指令。

语法：
```
file(WRITE filename "message to write...")
file(APPEND filename "message to append...")
file(READ filename variable)
file(REMOVE [directories]...)
file(REMOVE_RECURSE [directories]...)
file(MAKE_DIRECTORY [directories]...)
```

##  include 

载入 CMakeLists.txt 文件或者预定义的 cmake 模块。载入的内容在处理到 `include`  时直接执行。如果指定的是一个模块，将会在 `CMAKE_MODULE_PATH` 中搜索。

语法：
```
include(file1 [OPTIONAL])
include(module [OPTIONAL])
```

- `OPTIONAL` ：文件不存在时也不会产生错误。

## find

```
find_file(<VAR> name1 path1 path2 ...) # VAR 变量代表找到的文件全路径，包含文件名
find_library(<VAR> name1 path1 path2 ...) # VAR 变量代表找到的库全路径，包含文件名
find_path(<VAR> name1 path1 path2 ...) # VAR 变量代表包含这个文件的路径
find_program(<VAR> name1 path1 path2 ...) # VAR 变量代表包含这个程序的全路径
find_package(<name> [major.minor] [QUIET] [NO_MODULE] [[REQUIRED | COMPONENTS] [components...]]) # 调用预定义在 CMAKE_MODULE_PATH 下的 Find<name>.cmake 模块
```

- find_package 的 `REQUIRED` 指定这个共享库是不是工程必须的。

# 控制指令

## if 

语法：

```
if(expression)
	command1(args...)
	...
else if(expression)
	command2(args...)
	...
else(expression)
	command3(args...)
	...
endif(expression)
```

- 凡是出现 `if` 的地方一定要有对应的 `endif`
- 出现 `elseif` 的地方，`endif` 是可选的
- 如果 `set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)` 则 `else()`  和 `endif()` 的  `expression` 可以省略

示例：

```
if(var) # 如果变量不是：空,N,NO,OFF,FALSE,NOTFOUND 或者 <var>_NOTFOUND 时，表达式为真
if(NOT var) # 与上述条件相反
if(var1 AND var2) 
if(var1 OR var2)
if(COMMAND cmd) # 给定的 cmd 确是是命令并且可以调用为真
if(EXISTS dir) 
if(EXISTS file)
if(file1 IS_NEWER_THAN file2) # 当 file1 比 file2 新为真
if(IS_DIRECTORY dirname) # 当 dirname 是目录时为真
if(variable MATCHES regex)
if(string MATCHES regex)

# 数字比较表达式
if(variable LESS number)
if(string LESS number)
if(variable GREATER number)
if(string GREATER number)
if(variable EQUAL number)
if(string EQUAL number)

# 按字母顺序排列进行比较
if(variable STRLESS string)
if(string STRLESS string)
if(variable STRGREATER string)
if(string STRGREATER string)
if(variable STREQUAL string)
if(string STREQUAL string)

if(DEFINED variable) # 如果变量被定义，为真

if(WIN32)
	...
elseif(UNIX)
	...
elseif(APPLE)
	...
endif(WIN32)
```

## while

语法：

```
while(condition)
	command1(args...)
	command2(args...)
endwhile(condition)
```

其真假判断条件可以参考 `if` 指令。

## for_each

`for_each`  有三种使用形式：

### 列表

语法：

```
foreach(loop_var arg1 arg2...)
	command1(args ...)
	command2(args ...)
endforeach(loop_var)
```

示例：

```
aux_source_directory(. SRC_LIST)
foreach(F ${SRC_LIST})
	message(${F})
endforeach(F)
```

### 范围

语法：

```
foreach(loop_var RANGE total)
endforeach(loop_var)
```

示例：

```
foreach(VAR RANGE 10)
	message(${VAR})
endforeach()
```

### 范围和步进

语法：

```
foreach(loop_var RANGE start stop [step])
endforeach(loop_var)
```

以 `start` 开始到 `stop` 结束，以 `step` 为步进。

示例：

```
foreach(A RANGE 5 15 3)
	message(${A})
endforeach(A)
```

# 模块的使用和自定义模块

## 使用 FindCURL 模块

方法一：

```
include_directories(/usr/inclue) # 头文件目录
target_link_libraries(curTest curl) # 指定链接库
```

方法二：

```
find_package(CURL)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	target_link_libraries(curTest ${CURL_LIBRARY})
else(CURL_FOUND)
	message(FATAL_ERROR "curl library not found")
endif(CURL_FOUND)
```

## 自定义模块

定义 `cmake/FindHELLO.cmake`  模块

```
find_path(HELLO_INCLUDE_DIR hello.h /usr/include/hello /usr/local/include/hello)
find_library(HELLO_LIBRARY NAMES hello PATH /usr/lib /usr/local/lib)
if(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
	set(HELLO_FOUND TRUE)
endif(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
if(HELLO_FOUND)
	if(NOT HELLO_FIND_QUIETLY)
		message(STATUS "Found Hello:${HELLO_LIBRARY}")
	endif(NOT HELLO_FIND_QUIETLY)
else(HELLO_FOUND)
	if(HELLO_FIND_REQUIRED)
		message(FATAL "Could not find hello library")
	endif(HELLO_FIND_REQUIRED)
endif(HELLO_FOUND)
```

使用：

```
find_package(HELLO)
if(HELLO_FOUND)
	add_executable(hello main.c)
	include_directories(${HELLO_INCLUDE})
	target_link_libraries(hello ${HELLO_LIBRARY})
endif(HELLO_FOUND)
```

主工程中应该加入：

```
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
```

