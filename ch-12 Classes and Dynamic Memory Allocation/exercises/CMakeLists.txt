project(exercises)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g ${CMAKE_CXX_FLAGS}")

add_executable(01 01.cc)
add_executable(02 02.cc string1.cc)
add_executable(04 04.cc stack.cc)
add_executable(05 05.cc queue.cc)
add_executable(06 06.cc queue.cc)
