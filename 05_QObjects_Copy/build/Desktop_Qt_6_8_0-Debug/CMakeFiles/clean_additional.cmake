# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "05_QObjects_Copy_autogen"
  "CMakeFiles/05_QObjects_Copy_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/05_QObjects_Copy_autogen.dir/ParseCache.txt"
  )
endif()
