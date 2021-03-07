cmake_minimum_required(VERSION 3.19)
project(text_detector)

set(CMAKE_CXX_STANDARD 14)
include(${PROJECT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})