CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

include_directories(../include)

add_executable(simple simple.cpp)
target_link_libraries(simple engineworks)

add_executable(entities entities.cpp)
target_link_libraries(entities engineworks)

add_executable(managed managed.cpp)
target_link_libraries(managed engineworks)
