cmake_minimum_required(VERSION 3.27)
project(BeeWork)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use FetchContent to download and build SDL2 if not found
include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.28.5  # Use a specific release version
)

# Check if SDL2 is already available on the system
find_package(SDL2 QUIET)

if(NOT SDL2_FOUND)
    # SDL2 not found, so download and build it
    message(STATUS "SDL2 not found. Downloading and building SDL2 from source...")
    FetchContent_MakeAvailable(SDL2)

    # Set SDL2 variables after fetching
    set(SDL2_INCLUDE_DIRS ${SDL2_SOURCE_DIR}/include)
    set(SDL2_LIBRARIES SDL2)
else()
    message(STATUS "SDL2 found on the system.")
endif()

add_executable(BeeWork
  examples/main.c
  libs/glad/glad.c
)

target_include_directories(BeeWork PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/libs
  ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(BeeWork PRIVATE
  ${SDL2_LIBRARIES}
  cglm_headers
)

add_subdirectory(libs/cglm/ EXCLUDE_FROM_ALL)
