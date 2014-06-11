find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(LOADGL_COMPAT 1)
include (LoadGL/LoadGL)
include_directories(${LOADGL_DIR})

file(GLOB_RECURSE SOURCE *.cpp *.hpp)

add_executable(SDLExample WIN32 ${SOURCE})
target_link_libraries(SDLExample lui_${LUI_LIBTYPE} LoadGL ${SDL2_LIBRARY})
