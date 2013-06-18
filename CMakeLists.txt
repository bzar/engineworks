CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(engineworks)

file(GLOB SOURCES src/**/*.cpp)
list(APPEND CMAKE_CXX_FLAGS -std=c++11)
include_directories(include)

add_library(engineworks ${SOURCES})

install(TARGETS engineworks DESTINATION lib)
install(DIRECTORY include DESTINATION .)

add_subdirectory(test)
