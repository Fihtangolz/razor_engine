cmake_minimum_required(VERSION 3.9)
project(razor_engine)

set(CMAKE_CXX_STANDARD 17)

# sudo apt install libx11-dev
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.[c,h]pp)
foreach(source_file ${source_files})
    message("Include file to build: " ${source_file})
endforeach()

add_executable(razor_engine ${source_files})