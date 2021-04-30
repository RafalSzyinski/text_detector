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

set(FACE_DETECTION_CONFIGURATION
        "${PROJECT_SOURCE_DIR}/assets/deploy.prototxt")

set(FACE_DETECTION_WEIGHTS
        "${PROJECT_SOURCE_DIR}/assets/res10_300x300_ssd_iter_140000_fp16.caffemodel")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        FACE_DETECTION_CONFIGURATION="${FACE_DETECTION_CONFIGURATION}")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        FACE_DETECTION_WEIGHTS="${FACE_DETECTION_WEIGHTS}")