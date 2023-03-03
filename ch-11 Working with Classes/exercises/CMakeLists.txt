project(exercises)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g ${CMAKE_CXX_FLAGS}")

add_executable(01 01.cc vect.cc)
add_executable(03 03.cc vect.cc)
add_executable(07 07.cc complex0.cc)
