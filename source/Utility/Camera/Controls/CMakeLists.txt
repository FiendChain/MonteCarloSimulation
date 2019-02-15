cmake_minimum_required(VERSION 3.0)

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/CameraControlsConnector.cpp
    ${APP_DIR}/KeyboardCameraControls.cpp
    ${APP_DIR}/MouseCameraControls.cpp)

add_library(CameraControls ${APP_FILES})
target_compile_options(CameraControls PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(CameraControls ${SFML_LIB})
target_include_directories(CameraControls PUBLIC ${APP_DIR})