set(UNIT_TEST_LIST 
    diffdrive)

foreach(NAME IN LISTS UNIT_TEST_LIST)
    list(APPEND UNIT_TEST_SOURCE_LIST
        test_${NAME}.cpp)
endforeach()
         
set(TARGET_NAME tests)

add_executable(${TARGET_NAME}
    main.cpp
    ${UNIT_TEST_SOURCE_LIST})
             
target_link_libraries(${TARGET_NAME}
    PUBLIC diffdrive)

# Testing library needs to be cloned to the name directory as the project repo.
target_include_directories(${TARGET_NAME}
  PUBLIC $ENV{CATCH2_SINGLE_INCLUDE_DIR})
                 
add_test(
    NAME ${TARGET_NAME}
    COMMAND ${TARGET_NAME} -o report.xml -r junit)

add_custom_target(check COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET_NAME})
