project(exercises)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g ${CMAKE_CXX_FLAGS}")

add_executable(01 01.cc)
add_executable(02 02.cc)
add_executable(03 03.cc dma.cc)
add_executable(04 04.cc)
