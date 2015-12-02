
SET(TEST_DIR ${CMAKE_SOURCE_DIR}/tests/)
# http://stackoverflow.com/questions/3305545/how-to-adapt-my-unit-tests-to-cmake-and-ctest
# https://cmake.org/pipermail/cmake/2011-September/046218.html

# MESSAGE( " ===> Prepare tests " )
# INCLUDE_DIRECTORIES(.)
# # include( CTest )
# enable_testing()
#
# file(GLOB tests_sources *.cc)
# # add_executable(${tests_sources} ${tests_sources})
#
# add_executable(void_ tests_sources)
# add_test(NAME Test COMMAND void_)
# # add_test(GLOB *.cc)
MESSAGE( "Current dir = " ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} )
find_program(CTEST_GIT_COMMAND NAMES git)
MESSAGE( "Current dir = " ${CTEST_GIT_COMMAND}  )
#
#
# find_program (BASH_PROGRAM bash)
#
# if (BASH_PROGRAM)
#   add_test (mytest ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/script_test.sh )
# endif (BASH_PROGRAM)
MESSAGE( "->" ${CMAKE_PROJECT_NAME} "<-" )
MESSAGE( "->" ${CMAKE_SOURCE_DIR} "<-" )
file(GLOB sources "*.cc")
foreach( prova ${sources})
  MESSAGE( "->" ${prova} "<-" )
endforeach()
MESSAGE( "->" ${sources} "<-" )

set(CTEST_OUTPUT_ON_FAILURE "1")
enable_testing()

add_executable(runtestprog void.cc)
# add_test(NAME runtestprog_tmp COMMAND $<TARGET_FILE:runtestprog>)
add_test(NAME runtestprog
    # WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/
    # WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    # WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runtestprog/
    COMMAND ${CMAKE_COMMAND}
    -DTESTS_DIR=${TEST_DIR}
    -DTEST_PROG=$<TARGET_FILE:runtestprog>
    # -DSOURCEDIR=${CMAKE_CURRENT_SOURCE_DIR}
  -P ${TEST_DIR}/../cmake/tests/runtest.cmake)

add_executable(runtestprog_2 ${TEST_DIR}/void_2.cc)
add_test(NAME runtestprog_2
    # WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/build/
    # WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/runtestprog_2/
    COMMAND ${CMAKE_COMMAND}
    -DTESTS_DIR=${TEST_DIR}
    -DTEST_PROG=$<TARGET_FILE:runtestprog_2>
    # -DSOURCEDIR=${CMAKE_CURRENT_SOURCE_DIR}
  -P ${TEST_DIR}/../cmake/tests/runtest.cmake)

# MESSAGE( ${CMAKE_CURRENT_SOURCE_DIR} "--" ${CMAKE_COMMAND} )
# enable_testing()
# add_executable(testprog void.cc)
# add_test(NAME runtestprog
#     COMMAND ${CMAKE_CURRENT_SOURCE_DIR}
#     -DTEST_PROG=$<TARGET_FILE:testprog>
#     -DSOURCEDIR=${CMAKE_CURRENT_SOURCE_DIR}/
#     -P${CMAKE_CURRENT_SOURCE_DIR}/runtest.cmake)
#
# add_test( testprog
#     ${CMAKE_COMMAND}
#     # -D TEST_PROGRAM=${CMAKE_BINARY_DIR}/hello${CMAKE_EXECUTABLE_SUFFIX}
#     # -D TEST_ARGS=1
#     -D TEST_OUTPUT=tmpfile.txt
#     -D TEST_REFERENCE=${CMAKE_SOURCE_DIR}/testref.txt
#     -P ${CMAKE_CURRENT_SOURCE_DIR}/runtest.cmake ) # To compare output to reference file
#     # add_test( hello 1) # To perform memcheck tests

#
# #-------------------------------------------------
# # some argument checking:
# # test_cmd is the command to run with all its arguments
# if( NOT test_cmd )
#    message( FATAL_ERROR "Variable test_cmd not defined" )
# endif( NOT test_cmd )
#
# # output_blessed contains the name of the "blessed" output file
# if( NOT output_blessed )
#    message( FATAL_ERROR "Variable output_blessed not defined" )
# endif( NOT output_blessed )
#
# # output_test contains the name of the output file the test_cmd will
# # produce
# if( NOT output_test )
#    message( FATAL_ERROR "Variable output_test not defined" )
# endif( NOT output_test )
#
# # convert the space-separated string to a list
# separate_arguments( test_args )
# message( ${test_args} )
#
# execute_process(
#    COMMAND ${test_cmd} ${test_args}
#    COMMAND ${CMAKE_COMMAND} -E compare_files ${output_blessed} $
# {output_test}
#    RESULT_VARIABLE test_not_successful
# )
#
# if( test_not_successful )
#    message( SEND_ERROR "${output_test} does not match $
# {output_blessed}!" )
# endif( test_not_successful )
# #-------------------------------------------------
