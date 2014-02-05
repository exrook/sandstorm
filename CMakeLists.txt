cmake_minimum_required (VERSION 2.6)
project (sandstorm)
add_executable (sandstorm main.cpp Game.cpp Sandstorm.cpp Entity.cpp Level.cpp Platforms.cpp util.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMAGE REQUIRED SDL2_image)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(sandstorm ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
