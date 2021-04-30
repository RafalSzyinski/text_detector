cmake_minimum_required(VERSION 3.16)
project(FaceDetector)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ${PROJECT_SOURCE_DIR}/*.cpp
        ${PROJECT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${SOURCES})

# OpenCV setup
find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})