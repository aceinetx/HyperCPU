include(ExternalProject)

set(GENERIC_INCLUDE_DIR 
  ${ROOT_DIR}/src
  ${ROOT_DIR}/dist/argparse/include
  ${ROOT_DIR}/dist/pog/include
  ${ROOT_DIR}/dist/eternal/include
  ${ROOT_DIR}/dist/HPool)

ExternalProject_Add(
  libbacktrace
  SOURCE_DIR
    ${ROOT_DIR}/dist/libbacktrace
  BUILD_IN_SOURCE
    0
  CONFIGURE_COMMAND
    cd ${ROOT_DIR}/dist/libbacktrace && ./configure
  BUILD_COMMAND
    cd ${ROOT_DIR}/dist/libbacktrace && make -j$(nproc)
  INSTALL_COMMAND
    ""
  BUILD_BYPRODUCTS 
    ${ROOT_DIR}/dist/libbacktrace/libbacktrace.la
)

get_property(HCPU_CXX_FLAGS GLOBAL PROPERTY HCPU_CXX_FLAGS)
get_property(HCPU_LINK_FLAGS GLOBAL PROPERTY HCPU_LINK_FLAGS)

add_library(emulator-core STATIC ${SOURCES_emulator-core})
target_compile_options(emulator-core PUBLIC "${HCPU_CXX_FLAGS}")
target_include_directories(emulator-core PUBLIC ${GENERIC_INCLUDE_DIR} ${ROOT_DIR}/src/Emulator)
target_link_libraries(emulator-core ${LD_FLAGS} fmt)
target_precompile_headers(emulator-core PRIVATE pch.hpp)

add_library(assembler-core STATIC ${SOURCES_assembler-core})
target_compile_options(assembler-core PUBLIC "${HCPU_CXX_FLAGS}")
target_include_directories(assembler-core PUBLIC ${GENERIC_INCLUDE_DIR} ${ROOT_DIR}/src/Assembler)
target_link_libraries(assembler-core pog)
target_precompile_headers(assembler-core PRIVATE pch.hpp)

add_library(backtrace-provider STATIC ${SOURCES_backtrace-provider})
target_compile_options(backtrace-provider PUBLIC "${HCPU_CXX_FLAGS}")
target_include_directories(backtrace-provider PUBLIC ${GENERIC_INCLUDE_DIR})
add_dependencies(backtrace-provider libbacktrace)
target_precompile_headers(backtrace-provider PRIVATE pch.hpp)

add_executable(hcasm ${SOURCES_assembler-main})
target_compile_options(hcasm PUBLIC "${HCPU_CXX_FLAGS}")
target_include_directories(hcasm PUBLIC ${GENERIC_INCLUDE_DIR} ${ROOT_DIR}/src/Assembler)
target_link_libraries(hcasm assembler-core pog)
target_precompile_headers(hcasm PRIVATE pch.hpp)

add_executable(hcemul ${SOURCES_emulator-main})
target_compile_options(hcemul PUBLIC "${HCPU_CXX_FLAGS}")
target_include_directories(hcemul PUBLIC ${GENERIC_INCLUDE_DIR} ${ROOT_DIR}/src/Emulator)
target_link_libraries(hcemul emulator-core assembler-core)
target_precompile_headers(hcemul PRIVATE pch.hpp)

if (LIBUNWIND)
  target_link_libraries(hcasm backtrace-provider -L${ROOT_DIR}/dist/libbacktrace backtrace)
  target_link_libraries(hcemul backtrace-provider -L${ROOT_DIR}/dist/libbacktrace backtrace)
endif()

add_custom_target(default
  DEPENDS
    hcasm
    hcemul
)
