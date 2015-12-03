# MESSAGE( "----- > " ../${TESTS_DIR} "###" ${TEST_PROG} ${NAME} )

execute_process(
  COMMAND ${TEST_PROG}
  OUTPUT_VARIABLE OUTFILE
  RESULT_VARIABLE HAD_ERROR
)

FILE ( WRITE output ${OUTFILE} )

if(HAD_ERROR)
  message(FATAL_ERROR " [ Test failed - no run ] ")
else()
  message( " -> Test compiled" )
endif()

################################################################################
# -> DIFF CHECK
################################################################################
execute_process(
  COMMAND ${TESTS_DIR}/script_diff.sh ${TEST_NAME}.output /Users/esenonfossiio/git/project/sequence-comparison/cxx/build/tests/output
  RESULT_VARIABLE DIFFERENT
)

if(DIFFERENT)
    message(FATAL_ERROR " [ Test failed - files differ ] ")
endif()
