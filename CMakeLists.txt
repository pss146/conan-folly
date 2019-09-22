cmake_minimum_required(VERSION 2.8)
project(cmake_wrapper)

message(STATUS "Conan CMake Wrapper")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

IF(NOT BUILD_SHARED_LIBS AND MSVC)
    add_definitions(-DGOOGLE_GLOG_DLL_DECL=)
ENDIF()

add_subdirectory("source_subfolder")
