cmake_minimum_required (VERSION 2.6)
 
add_executable(
  sfcdecode
  sfcdecode.cpp
)

target_link_libraries(sfcdecode tbb)

include_directories(../SFCLib/)

install(TARGETS sfcdecode DESTINATION bin)
