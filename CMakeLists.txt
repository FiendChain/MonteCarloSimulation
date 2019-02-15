cmake_minimum_required(VERSION 3.0)

project("SFML 2D App")

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)
set(APP_DIR ${SRC_DIR}/MonteCarlo)
set(UTILITY_DIR ${SRC_DIR}/Utility)

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)

include_directories(${SRC_DIR})

add_subdirectory(${APP_DIR})
add_subdirectory(${UTILITY_DIR})

add_executable(main ${SRC_DIR}/main.cpp)
target_compile_options(main PUBLIC -std=c++17 -O3)
target_link_libraries(main MonteCarlo utility ${SFML_LIB})