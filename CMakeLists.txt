cmake_minimum_required(VERSION 3.20.0)

set(lib xdts)
set(${lib}_libtype PUBLIC PARENT_SCOPE)

file(GLOB SRCSC "./*.c")
file(GLOB SRCSH "./*.h")
add_library(${lib} ${${lib}_libtype} ${SRCSH} ${SRCSC})
set_target_properties(${lib} PROPERTIES LINKER_LANGUAGE C)

target_link_libraries(${lib} PUBLIC zephyr_interface)
target_include_directories(${lib} PUBLIC ./)

