cmake_minimum_required(VERSION 2.8)
project(razor_engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(razor_engine src/main.cpp src/event_manager/event_t.hpp src/ecs/entity_t.hpp src/render_system/render_system_t.hpp src/ecs/system_t.hpp src/utils.hpp src/logging.hpp src/input_system/input_system_t.hpp)