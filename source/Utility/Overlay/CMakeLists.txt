cmake_minimum_required(VERSION 3.0)

project("Overlay")

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/Overlay.cpp)

add_library(Overlay ${APP_FILES})
target_compile_options(Overlay PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(Overlay ${SFML_LIB})
target_include_directories(Overlay PUBLIC ${APP_DIR})