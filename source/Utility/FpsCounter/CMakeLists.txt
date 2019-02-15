cmake_minimum_required(VERSION 3.0)

project("Fps Counter")

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/FpsCounter.cpp)

add_library(FpsCounter ${APP_FILES})
target_compile_options(FpsCounter PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(FpsCounter ${SFML_LIB})
target_include_directories(FpsCounter PUBLIC ${APP_DIR})