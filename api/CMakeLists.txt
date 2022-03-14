project (${API_LIB_NAME})
enable_language (Fortran)

set(API_IMPLEMENTATION
    apiinput_m.f90)

set_source_files_properties(${API_IMPLEMENTATION} PROPERTIES COMPILE_FLAGS "${F90_FLAGS}")

include_directories (${PROJECT_BUILD_DIR}/include)

link_directories (${PROJECT_BUILD_DIR}/lib)

add_library(${API_LIB_NAME} ${API_IMPLEMENTATION})

target_link_libraries (${API_LIB_NAME} ${FORTRAN_LIB_NAME})
set_target_properties(${API_LIB_NAME}
                        PROPERTIES OUTPUT_NAME ${API_LIB_NAME}
                        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib
                        ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib
                        Fortran_MODULE_DIRECTORY ${PROJECT_MODULE_DIR})
