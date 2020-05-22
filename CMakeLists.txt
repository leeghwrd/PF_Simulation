cmake_minimum_required(VERSION 3.7)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PF_Simulation)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

file(GLOB SOURCES "src/*.cpp")

add_executable(PF_Simulation ${SOURCES})

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PF_Simulation ${SDL2_LIBRARIES})