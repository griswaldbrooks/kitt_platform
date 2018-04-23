cmake_minimum_required(VERSION 3.5)
 
project(balor)

# Put the executables and libraries in the right folders.
message("PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
set (CMAKE_CXX_STANDARD 11)

# Setup testing.
enable_testing()

# Add directories to be complied.
add_subdirectory(src)
add_subdirectory(test)
