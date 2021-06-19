
set(SRCS main.cpp)

add_executable(curl_module ${SRCS})


find_package(CURL)

if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
    target_link_libraries(curl_module ${CURL_LIBRARY})
else(CURL_FOUND)
    message(FATAL_ERROR "CURL library not found!!!")
endif(CURL_FOUND)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)