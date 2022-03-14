project (${ERROR_API_NAME})


set (ERROR_LIB_HEADERS
     error.h)

set (ERROR_API_HEADERS
     apierror.h
     PARENT_SCOPE)

set (ERROR_API_SOURCE
     apierror.cpp)

# C++ flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

add_library(${ERROR_API_NAME} ${ERROR_API_SOURCE}
                              ${ERROR_API_HEADERS}
                              ${ERROR_LIB_HEADERS})

set_target_properties(${ERROR_API_NAME}
                      PROPERTIES OUTPUT_NAME ${ERROR_API_NAME}
                      LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib
                      ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib)
