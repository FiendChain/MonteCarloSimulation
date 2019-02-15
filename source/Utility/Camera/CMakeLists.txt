cmake_minimum_required(VERSION 3.0)

project("2D Camera")

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/ControllableCamera.cpp
    ${APP_DIR}/StandardCamera.cpp)

add_subdirectory(${APP_DIR}/Controls)

add_library(Camera ${APP_FILES})
target_compile_options(Camera PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(Camera CameraControls ${SFML_LIB})
target_include_directories(Camera PUBLIC ${APP_DIR})