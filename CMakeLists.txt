# CMake project file for project
cmake_minimum_required (VERSION 3.16)

# project name and details
project (TestAPI)
enable_language (Fortran)

set (ERROR_API_NAME errorapi)
set (FORTRAN_LIB_NAME fortranlib)
set (API_LIB_NAME api)
set (TEST_PROG_NAME testcpp)
set (MEMORY_PROG_NAME memorycpp)

set (BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
set (PROJECT_BUILD_DIR ${CMAKE_BINARY_DIR})

# set the general fortran Debug/Release compiler flags
set(CMAKE_Fortran_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_Fortran_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Fortran OS specific compiler flags
if (CMAKE_Fortran_COMPILER_ID MATCHES MSVC)
    set ( F90_FLAGS_DEBUG "${CMAKE_Fortran_FLAGS_DEBUG} -fp-model")
    set ( F90_FLAGS_RELEASE  "${CMAKE_Fortran_FLAGS_RELEASE} -fp-model" )
elseif (CMAKE_Fortran_COMPILER_ID MATCHES Intel)
    set ( F90_FLAGS_DEBUG "${CMAKE_Fortran_FLAGS_DEBUG} -debug  -CB -CA -CU -std08  -fp-model source")
    set ( F90_FLAGS_RELEASE  "${CMAKE_Fortran_FLAGS_RELEASE} -std08 -unroll -fp-model source -diag-disable 8291,8577" )
elseif (CMAKE_Fortran_COMPILER_ID MATCHES GNU)
    set ( F90_FLAGS_DEBUG "${CMAKE_Fortran_FLAGS_DEBUG} -cpp -ffree-form  -ffloat-store -fno-sign-zero -std=f2008ts -ffree-line-length-none")
    set ( F90_FLAGS_RELEASE  "${CMAKE_Fortran_FLAGS_RELEASE} -cpp -ffree-form -ffloat-store -fno-sign-zero -std=f2008ts -ffree-line-length-none" )
#    set ( CMAKE_EXE_LINKER_FLAGS "-static-libgfortran" )
endif ()


# Set release build by default
set (CMAKE_BUILD_TYPE Release CACHE STRING "Select which configuration to build.")
set (PROJECT_BUILD_TYPE "Release")
if(CMAKE_BUILD_TYPE)
    set(PROJECT_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
    set(CMAKE_BUILD_TYPE ${PROJECT_BUILD_TYPE})
endif()

# Release or Debug build
if(PROJECT_BUILD_TYPE MATCHES Release)
    message(STATUS "Release build")
    set(F90_FLAGS ${F90_FLAGS_RELEASE})
elseif(PROJECT_BUILD_TYPE MATCHES Debug)
    message(STATUS "Debug build")
    set(F90_FLAGS ${F90_FLAGS_DEBUG})
else()
    message(STATUS "Default build (Release)")
    set(F90_FLAGS ${F90_FLAGS_RELEASE})
endif()

# set the output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# Collect all the mod files into their own include directory
set(PROJECT_MODULE_DIR ${CMAKE_BINARY_DIR}/include)

# add projects
add_subdirectory(${BASE_DIR}/${ERROR_API_NAME})
add_subdirectory(${BASE_DIR}/${FORTRAN_LIB_NAME})
add_subdirectory(${BASE_DIR}/${API_LIB_NAME})
add_subdirectory(${BASE_DIR}/testprogram)
add_subdirectory(${BASE_DIR}/memoryprogram)
