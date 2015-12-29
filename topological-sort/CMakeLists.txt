cmake_minimum_required(VERSION 3.3)
project(topsort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
#set(HEADER_FILES Stack.h)
add_executable(topsort ${SOURCE_FILES} stack.c graph.c stack.h graph.h)