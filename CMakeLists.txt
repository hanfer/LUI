cmake_minimum_required(VERSION 2.6)
project(LUI)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

include(options)
include(printoptions)

# The Lib!
macro(add_lib_type TYPE)
    string(TOUPPER ${TYPE} TYPE_UPPER)

    add_library(lui_${TYPE} ${TYPE_UPPER} ${HEADER} ${SOURCE})
    set(LUI_LIBTYPE ${TYPE})

    if(UNIX) # unix plattforms shared and static can have the same name
        set_target_properties(lui_${TYPE} PROPERTIES OUTPUT_NAME lui)
    endif()
endmacro()

include (GenerateExportHeader)
include (CreateVSDir)

file(GLOB_RECURSE SOURCE src/*.cpp)
file(GLOB_RECURSE HEADER include/*.hpp)

include_directories(include)

if(BUILD_SHARED OR BUILD_BOTH)
    add_lib_type(shared)
endif()

if(BUILD_STATIC OR BUILD_BOTH)
    add_lib_type(static)
endif()

CreateVSDir(${HEADER} ${SOURCE})
GENERATE_EXPORT_HEADER(lui_${LUI_LIBTYPE}
             BASE_NAME LUI
             EXPORT_MACRO_NAME LUI_EXPORT
             EXPORT_FILE_NAME include/LUIExport.hpp
             STATIC_DEFINE LUI_STATIC
)
include_directories("${PROJECT_BINARY_DIR}/include")


# examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
