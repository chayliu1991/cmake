cmake_minimum_required(VERSION 3.1)

project(CURLMODULE)

add_subdirectory(src)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} doesn’t support C++11. Please upgrade or use a different C++ compiler.")
endif()
