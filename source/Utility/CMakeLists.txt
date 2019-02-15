
cmake_minimum_required(VERSION 3.0)

project("Utility")

set(APP_DIR .)

set(UTILITY_LIBS
    Camera
    FpsCounter
    Overlay)

add_subdirectory(${APP_DIR}/Camera)
add_subdirectory(${APP_DIR}/FpsCounter)
add_subdirectory(${APP_DIR}/Overlay)

add_library(utility dummy.cpp)
target_compile_options(utility PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(utility ${UTILITY_LIBS})
target_include_directories(utility PUBLIC ${APP_DIR})