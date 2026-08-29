# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\SerialProgramsCommandLine_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SerialProgramsCommandLine_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\SerialProgramsLib_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SerialProgramsLib_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\SerialPrograms_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SerialPrograms_autogen.dir\\ParseCache.txt"
  "SerialProgramsCommandLine_autogen"
  "SerialProgramsLib_autogen"
  "SerialPrograms_autogen"
  )
endif()
