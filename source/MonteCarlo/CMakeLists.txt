cmake_minimum_required(VERSION 3.0)

project("Monte Carlo Pi")

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/Canvas.cpp
    ${APP_DIR}/MonteCarloPi.cpp)

add_library(MonteCarlo ${APP_FILES})
target_compile_options(MonteCarlo PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(MonteCarlo ${SFML_LIB})
target_include_directories(MonteCarlo PUBLIC ${APP_DIR})