CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(engineworks)

file(GLOB SOURCES src/*.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(include)

add_library(engineworks ${SOURCES})

install(TARGETS engineworks DESTINATION lib)
install(DIRECTORY include DESTINATION .)
