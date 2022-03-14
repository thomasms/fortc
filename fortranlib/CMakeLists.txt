project (${FORTRAN_LIB_NAME})

set (F90_SOURCES
     fork_m.F90
     error_m.f90
     input_m.f90)

set_source_files_properties(${F90_SOURCES} PROPERTIES COMPILE_FLAGS "${F90_FLAGS}")

link_directories (${PROJECT_BUILD_DIR}/lib)

add_library(${FORTRAN_LIB_NAME} ${F90_SOURCES})

target_link_libraries (${FORTRAN_LIB_NAME} ${ERROR_API_NAME})
set_target_properties(${FORTRAN_LIB_NAME}
                      PROPERTIES OUTPUT_NAME ${FORTRAN_LIB_NAME}
                      LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib
                      ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib
                      Fortran_MODULE_DIRECTORY ${PROJECT_MODULE_DIR})
