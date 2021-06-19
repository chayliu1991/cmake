# 此处用到 2_install 项目安装的库

find_path(HELLO_INCLUDE_DIR hello.h /tmp/usr/include)
find_library(HELLO_LIBRARY hello /tmp/usr/lib)

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