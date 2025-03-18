cmake_minimum_required(VERSION 3.27)
project(BeeWork)

set(CMAKE_C_STANDARD 99)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(BeeWork
  examples/main.c
  libs/glad/glad.c
)

target_include_directories(BeeWork PUBLIC
 ${CMAKE_CURRENT_SOURCE_DIR}/libs
)

target_link_directories(ChessbutBad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw/libglfw3.a)

target_link_libraries(ChessbutBad PRIVATE
    glfw
    m
    dl
    pthread
)

target_link_libraries(BeeWork PRIVATE
  cglm_headers)

add_subdirectory(libs/cglm/ EXCLUDE_FROM_ALL)

