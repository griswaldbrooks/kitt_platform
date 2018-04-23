cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME balor)
 
add_library(${TARGET_NAME} SHARED
    balor.cpp)
target_include_directories(${TARGET_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/src)
