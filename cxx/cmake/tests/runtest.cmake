MESSAGE( "----- > " ../${TESTS_DIR} "###" ${TEST_PROG} ${NAME} )

execute_process(
  COMMAND ${TEST_PROG}
  OUTPUT_VARIABLE OUTFILE
  RESULT_VARIABLE HAD_ERROR
)

FILE ( WRITE output ${OUTFILE} )
MESSAGE ( "---->" ${TEST_PROG} "--" ${OUTFILE} )

if(HAD_ERROR)
  message(FATAL_ERROR " [ Test failed - no run ] ")
else()
  message( " -> Test compiled" )
endif()

################################################################################
# -> DIFF CHECK
################################################################################
execute_process(
  COMMAND ${TESTS_DIR}/script_test.sh ${OUTFILE}
  RESULT_VARIABLE DIFFERENT
)

if(DIFFERENT)
    message(FATAL_ERROR " [ Test failed - files differ ] ")
endif()
