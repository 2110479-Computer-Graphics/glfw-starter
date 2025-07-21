cmake_minimum_required(VERSION 3.10)
project(GLFWProjectStarter)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_library(glad STATIC include/glad/glad.c)

find_package(glfw3 REQUIRED)

add_executable(main src/main.cpp)

file(GLOB SHADER_FILES "src/shader/*")
foreach(SHADER_FILE ${SHADER_FILES})
  configure_file(${SHADER_FILE} ${CMAKE_CURRENT_BINARY_DIR}/shader/ COPYONLY)
endforeach()

target_link_libraries(main PRIVATE glad glfw)