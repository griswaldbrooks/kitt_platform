cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME diffdrive)
 
add_library(${TARGET_NAME} SHARED
    diffdrive.cpp)
message(${PROJECT_SOURCE_DIR})
target_include_directories(${TARGET_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/src)
