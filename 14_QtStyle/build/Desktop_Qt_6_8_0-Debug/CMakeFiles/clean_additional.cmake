# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "14_QtStyle_autogen"
  "CMakeFiles/14_QtStyle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/14_QtStyle_autogen.dir/ParseCache.txt"
  )
endif()
