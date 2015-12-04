
################################################################################
# -> RUN CHECK
################################################################################
EXECUTE_PROCESS(
  COMMAND ${TEST_PROG}
  OUTPUT_VARIABLE OUTFILE
  RESULT_VARIABLE HAD_ERROR
)

FILE ( WRITE output ${OUTFILE} )

IF(HAD_ERROR)
  MESSAGE(FATAL_ERROR " [ Test failed - no run ] ")
ELSE()
  MESSAGE( " -> Test compiled" )
ENDIF()

################################################################################
# -> DIFF CHECK
################################################################################
EXECUTE_PROCESS(
  COMMAND ${TESTS_DIR}/../cmake/scripts/script_dIFf.sh ${TEST_NAME}.output ${TEST_DIR}/output
  RESULT_VARIABLE DIFFERENT
)

IF(DIFFERENT)
  MESSAGE(FATAL_ERROR " [ Test failed - files differ ] ")
ENDIF()
