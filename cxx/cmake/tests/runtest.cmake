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
  COMMAND ${TESTS_DIR}/../cmake/scripts/script_diff.sh ${TEST_NAME}.output ${TEST_DIR}/output
  RESULT_VARIABLE DIFFERENT
)

if(DIFFERENT)
    message(FATAL_ERROR " [ Test failed - files differ ] ")
endif()
