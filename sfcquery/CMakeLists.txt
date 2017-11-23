cmake_minimum_required (VERSION 2.6)
 
add_executable(
  sfcquery
  sfcquery.cpp
)

target_link_libraries(sfcquery tbb)

include_directories(../SFCLib/)

install(TARGETS sfcquery DESTINATION bin)
