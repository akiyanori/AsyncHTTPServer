cmake_minimum_required(VERSION 3.20)
project(AsyncHTTPServer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(AsyncHTTPServer 
	src/main.cpp
	src/Socket.cpp
)

if(WIN32)
    target_link_libraries(AsyncHTTPServer ws2_32)
endif()