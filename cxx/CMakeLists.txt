cmake_minimum_required(VERSION 2.8)

project (sequence-comparison)
file(GLOB cc_files source/*.cc)
include_directories(include)
add_executable(sequence-comparison ${cc_files})



find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

target_link_libraries(sequence-comparison ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
set_target_properties(sequence-comparison PROPERTIES
COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
set_target_properties(sequence-comparison PROPERTIES
LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()


find_package(OpenMP)
if (OPENMP_FOUND)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


add_custom_target(run
COMMAND sequence-comparison
DEPENDS sequence-comparison
WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
