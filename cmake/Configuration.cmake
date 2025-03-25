include(cmake/Variables.cmake)

function(set_compile_flags debug_enabled)
  if (debug_enabled)
    set(HCPU_COMPILE_FLAGS ${DEBUG_COMPILE_FLAGS} PARENT_SCOPE)
    set(LD_FLAGS "" PARENT_SCOPE)
  else()
    set(HCPU_COMPILE_FLAGS ${FAST_COMPILE_FLAGS} PARENT_SCOPE)
    set(LD_FLAGS "${LTO_FLAG}" PARENT_SCOPE)
  endif()
endfunction()

function(detect_compilers)
  string(TOLOWER "${HCPU_COMPILER}" HCPU_COMPILER)
  string(SUBSTRING "${CMAKE_C_COMPILER}" 0 1 IS_ABS)
  if ("${HCPU_COMPILER}" STREQUAL "auto" OR "${HCPU_COMPILER}" STREQUAL "")
    message(STATUS "Using CMake compiler autodetection")
  elseif ("${HCPU_COMPILER}" STREQUAL "clang")
    if ("${CMAKE_C_COMPILER}" STREQUAL "" OR "${IS_ABS}" STREQUAL "/")
      message(STATUS "Searching for clang")
      execute_process(COMMAND which clang OUTPUT_VARIABLE CMAKE_C_COMPILER)
      execute_process(COMMAND which clang++ OUTPUT_VARIABLE CMAKE_CXX_COMPILER)
    elseif (NOT "${IS_ABS}" STREQUAL "/")
      message(STATUS "Searching for ${CMAKE_C_COMPILER}")
      execute_process(COMMAND which ${CMAKE_C_COMPILER} OUTPUT_VARIABLE CMAKE_C_COMPILER)
      execute_process(COMMAND which ${CMAKE_CXX_COMPILER} OUTPUT_VARIABLE CMAKE_CXX_COMPILER)
    endif()
  elseif ("${HCPU_COMPILER}" STREQUAL "gcc")
    if ("${CMAKE_C_COMPILER}" STREQUAL "" OR "${IS_ABS}" STREQUAL "/")
      message(STATUS "Searching for gcc")
      execute_process(COMMAND which gcc OUTPUT_VARIABLE CMAKE_C_COMPILER)
      execute_process(COMMAND which g++ OUTPUT_VARIABLE CMAKE_CXX_COMPILER)
    elseif (NOT "${IS_ABS}" STREQUAL "/")
      message(STATUS "Searching for ${CMAKE_C_COMPILER}")
      execute_process(COMMAND which ${CMAKE_C_COMPILER} OUTPUT_VAR
IABLE CMAKE_C_COMPILER)
      execute_process(COMMAND which ${CMAKE_CXX_COMPILER} OUTPUT_VARIABLE CMAKE_CXX_COMPILER)
    endif()
  elseif ("${HCPU_COMPILER}" STREQUAL "manual")
    message(STATUS "Using custom compiler paths")
  else()
    message(FATAL_ERROR "HCPU_COMPILER not specified: cannot proceed. Please specify one of: auto, clang, gcc, manual")
  endif()
endfunction()
