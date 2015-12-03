
# Set variables:
#   - TEST_DIR = Directory where tests are
SET(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)
SET(CMAKE_TEST_DIR ${CMAKE_SOURCE_DIR}/cmake/tests)

ENABLE_TESTING()

FILE(GLOB sources "*.cc")
FOREACH( prova ${sources})
  GET_FILENAME_COMPONENT( NAME ${prova} NAME_WE )
  ADD_EXECUTABLE(${NAME} ${NAME}.cc)
  ADD_TEST(NAME ${NAME}
    # WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${NAME}
    COMMAND ${CMAKE_COMMAND}
    -DTESTS_DIR=${TEST_DIR}
    -DTEST_PROG=$<TARGET_FILE:${NAME}>
    -P ${CMAKE_TEST_DIR}/runtest.cmake)
ENDFOREACH()

# TODO:
#   - use macro
#   - change working Directory
#   - set diff script
