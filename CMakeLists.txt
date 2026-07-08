cmake_minimum_required(VERSION 3.28.2)

project(custom_stl VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set the compilation flags
if (MSVC)
    set(DEFAULT_COMPILE_OPTIONS /W4 /WX)
else()
    set(DEFAULT_COMPILE_OPTIONS -Wall -Wextra -Werror -Wpedantic)
endif()

add_library(custom_stl INTERFACE)
add_library(custom_stl::custom_stl ALIAS custom_stl)

target_include_directories(custom_stl INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(custom_stl INTERFACE ${DEFAULT_COMPILE_OPTIONS})

option(BUILD_TESTING "Build the testing suite" ON)

if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()