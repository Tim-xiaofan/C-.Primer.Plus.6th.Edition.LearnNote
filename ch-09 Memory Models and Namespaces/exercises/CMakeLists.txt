project(exercises)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ${CMAKE_CXX_FLAGS}")

add_executable(01 01.cc golf.cc)
add_executable(02 02.cc)
add_executable(03 03.cc)
add_executable(04 04.cc 04cc.cc)
