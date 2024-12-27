# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "03_Hello_autogen"
  "CMakeFiles/03_Hello_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/03_Hello_autogen.dir/ParseCache.txt"
  )
endif()
