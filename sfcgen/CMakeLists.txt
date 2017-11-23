cmake_minimum_required (VERSION 2.6)
 
add_executable(
  sfcgen
  sfcgen.cpp
)

target_link_libraries(sfcgen tbb)

include_directories(../SFCLib/)

install(TARGETS sfcgen DESTINATION bin)
