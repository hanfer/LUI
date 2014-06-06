find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCE *.cpp *.hpp)

include_directories(${SDL2_INCLUDE_DIR})

add_executable(SDLExample WIN32 ${SOURCE})
target_link_libraries(SDLExample lui_${LUI_LIBTYPE} ${SDL2_LIBRARY})
