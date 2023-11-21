cmake_minimum_required(VERSION 3.20)

project(BabbleChat LANGUAGES CXX)

# Activates CTest.
enable_testing()

# Sets C++ as the standart for the project.
set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

# Sets default options of different compilers.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
   add_compile_options(-Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVS")
endif()

# Output directories for build artifacts.
set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/output)

set(OUTPUT_DEBUG_DIR ${OUTPUT_DIR}/debug)
set(OUTPUT_RELEASE_DIR ${OUTPUT_DIR}/release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/lib)
set(CMAKE_KIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEBUG_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_RELEASE_DIR}/bin)

# Sets the default build type.
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Debug")
endif()

# Determines the os type.
if(WIN32)
   set(OS_NAME "Windows")
elseif(UNIX AND NOT APPLE)
   set(OS_NAME "Linux")
elseif(APPLE)
   set(OS_NAME "macOs")
else()
   set(OS_NAME "Unknown OS")
endif()

# Build configuration information.
message(STATUS "*==================================*")
message(STATUS "| Generator    : ${CMAKE_GENERATOR}")
message(STATUS "| CXX Compiler : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "| OS           : ${OS_NAME}")
message(STATUS "| Build type   : ${CMAKE_BUILD_TYPE}")
message(STATUS "*==================================*")

add_subdirectory(src)
