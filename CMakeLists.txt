project(modlist)

cmake_minimum_required(VERSION 3.0)
find_library(IOKIT IOKit)
find_library(CF CoreFoundation)
add_executable(modlist modlist.cpp)
target_compile_features(modlist PRIVATE cxx_range_for)
include_directories(${IOKIT} ${CF})
target_link_libraries(modlist ${IOKIT} ${CF})

