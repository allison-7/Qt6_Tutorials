# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "13_QMap_autogen"
  "CMakeFiles/13_QMap_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/13_QMap_autogen.dir/ParseCache.txt"
  )
endif()
