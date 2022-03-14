project (${MEMORY_PROG_NAME})

# Include directories
include_directories (${BASE_DIR}/${ERROR_API_NAME} ${BASE_DIR}/${API_LIB_NAME})

# Library directories for linking
link_directories (${PROJECT_BUILD_DIR}/lib)

# C++ flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -fopenmp")
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

# Make the executable
add_executable (${MEMORY_PROG_NAME} main.cpp)

target_link_libraries (${MEMORY_PROG_NAME} ${ERROR_API_NAME} ${API_LIB_NAME} ${FORTRAN_LIB_NAME})
set_target_properties(${MEMORY_PROG_NAME}
                      PROPERTIES OUTPUT_NAME ${MEMORY_PROG_NAME}
                      RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/bin)
