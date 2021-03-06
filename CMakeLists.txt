CMAKE_MINIMUM_REQUIRED(VERSION 2.8)



PROJECT(sequence-comparison)

# Require C++11:
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

FILE(GLOB cc_files source/*.cc)
FILE(GLOB exec main/*.cc)

INCLUDE_DIRECTORIES(include)
ADD_EXECUTABLE(sequence-comparison ${exec})

FIND_PACKAGE(MPI REQUIRED)
INCLUDE_DIRECTORIES(${MPI_INCLUDE_PATH})
TARGET_LINK_LIBRARIES(sequence-comparison ${MPI_LIBRARIES})

IF(MPI_COMPILE_FLAGS)
  SET_TARGET_PROPERTIES(  sequence-comparison
    PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}"
  )
ENDIF()

IF(MPI_LINK_FLAGS)
  SET_TARGET_PROPERTIES(  sequence-comparison
    PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}"
  )
ENDIF()

# FIND_PACKAGE(OpenMP)
# if (OPENMP_FOUND)
#   set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#   set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
# ENDIF()

SET(_lib "sequence-comparison-lib")
ADD_LIBRARY(${_lib} SHARED ${cc_files})
TARGET_LINK_LIBRARIES(sequence-comparison ${_lib})

ADD_CUSTOM_TARGET(run
  COMMAND sequence-comparison
  DEPENDS sequence-comparison
  WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

OPTION(ENABLE_TESTS "Enable testing" OFF)
IF (ENABLE_TESTS STREQUAL ON)
  ENABLE_TESTING()
  ADD_SUBDIRECTORY(tests)
ENDIF()

MESSAGE( " " )
MESSAGE(STATUS "========================== STATUS: ==========================")
MESSAGE(STATUS " ENABLE_TESTS : ....... " ${ENABLE_TESTS} )
MESSAGE(STATUS " CMAKE_CXX_FLAGS : .... " ${CMAKE_CXX_FLAGS})
MESSAGE(STATUS "=============================================================")
MESSAGE( " " )

ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Debug"
  )

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Switch CMAKE_BUILD_TYPE to Release"
  )

# add a target to generate API documentation with Doxygen
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
  CONFIGURE_FILE(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxygen/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  ADD_CUSTOM_TARGET(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
  )
ENDIF(DOXYGEN_FOUND)
