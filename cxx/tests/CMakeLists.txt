
MESSAGE( " ===> Prepare tests " )
INCLUDE_DIRECTORIES(.)
# include( CTest )
enable_testing()

file(GLOB tests_sources *.cc)
# add_executable(${tests_sources} ${tests_sources})

add_executable(void_ void.cc)
add_test(NAME Test COMMAND void_)
# add_test(GLOB *.cc)

MESSAGE( "Current dir = " ${CMAKE_CURRENT_SOURCE_DIR} )


find_program (BASH_PROGRAM bash)

if (BASH_PROGRAM)
  add_test (mytest ${BASH_PROGRAM} ${CMAKE_CURRENT_SOURCE_DIR}/script_test.sh)
endif (BASH_PROGRAM)

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
