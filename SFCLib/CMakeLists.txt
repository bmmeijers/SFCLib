cmake_minimum_required (VERSION 2.6)
 
# Maps to Visual Studio solution file (Tutorial.sln)
# The solution will have all targets (exe, lib, dll) 
# as Visual Studio projects (.vcproj)
 
# Command to output information to the console
# Useful for displaying errors, warnings, and debugging
message ("cxx Flags:" ${CMAKE_CXX_FLAGS})
 

add_library(
  libsfc
  OBJECT
  SFCLib.cpp
)
