# Set variables:
#   - TEST_DIR = Directory where tests are
#   - CMAKE_TEST_DIR = Directory where is the script used to find differences
SET(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
SET(CMAKE_TEST_DIR ${CMAKE_SOURCE_DIR}/cmake/tests)

MACRO(NEW_TEST TEST_SRC)
  GET_FILENAME_COMPONENT( FILE_NAME ${TEST_SRC} NAME_WE)
  FILE(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${FILE_NAME})
  ADD_EXECUTABLE(${FILE_NAME} ${FILE_NAME}.cc)
  TARGET_LINK_LIBRARIES(${FILE_NAME} ${_lib})
  SET_TARGET_PROPERTIES(${FILE_NAME}
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${FILE_NAME})
  ADD_TEST(NAME ${FILE_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests/${FILE_NAME}
    COMMAND ${CMAKE_COMMAND}
    -DTEST_DIR=${CMAKE_BINARY_DIR}/tests/${FILE_NAME}
    -DTEST_NAME=${TEST_DIR}/${FILE_NAME}
    -DTESTS_DIR=${TEST_DIR}
    -DTEST_PROG=$<TARGET_FILE:${FILE_NAME}>
    -P ${CMAKE_TEST_DIR}/runtest.cmake)

  ADD_CUSTOM_TARGET(run_${FILE_NAME}
    COMMAND ${CMAKE_BINARY_DIR}/tests/${FILE_NAME}/${FILE_NAME}
    DEPENDS ${CMAKE_BINARY_DIR}/tests/${FILE_NAME}/${FILE_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
  )
ENDMACRO()