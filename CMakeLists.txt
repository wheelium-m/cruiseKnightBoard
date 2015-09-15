cmake_minimum_required(VERSION 3.3)

project(cruise)
enable_testing()

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

include_directories("include")
add_subdirectory(include)

add_subdirectory(src)

set(SOURCE_FILES main.cpp ${ALL_HEADERS})
add_executable(cruise ${SOURCE_FILES})
target_link_libraries(cruise KnightBoard Square)