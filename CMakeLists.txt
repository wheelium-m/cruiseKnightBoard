cmake_minimum_required(VERSION 2.8)

project(cruise)
enable_testing()

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("include")
add_subdirectory(include)

add_subdirectory(src)

# Handle testing
add_subdirectory(test)

# Build and link main executable
set(SOURCE_FILES main.cpp ${ALL_HEADERS})
add_executable(cruise ${SOURCE_FILES})
target_link_libraries(cruise KnightBoard Square)
