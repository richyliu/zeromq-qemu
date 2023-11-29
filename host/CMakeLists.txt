cmake_minimum_required(VERSION 3.5)
project(zeromq-wrapper C)

# Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add ZeroMQ library and include directories
find_library(ZMQ_LIB zmq HINTS /opt/homebrew/lib)
include_directories(/opt/homebrew/include)

add_executable(server server.c)
target_link_libraries(server PRIVATE ${ZMQ_LIB})

add_executable(test_client test_client.c)
target_link_libraries(test_client PRIVATE ${ZMQ_LIB})
