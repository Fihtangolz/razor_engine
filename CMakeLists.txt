cmake_minimum_required(VERSION 3.9)
project(razor_engine)

set(CMAKE_CXX_STANDARD 17)

# sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
# sudo apt install python3-pip | after pip3 install clang
# sudo apt install libx11-dev
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

file(GLOB_RECURSE source_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.[c,h]pp)
foreach(source_file ${source_files})
    message("Include file to build: " ${source_file})
endforeach()

add_executable(razor_engine ${source_files})
target_link_libraries(razor_engine ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )