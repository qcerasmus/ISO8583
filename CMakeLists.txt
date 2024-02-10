cmake_minimum_required(VERSION 3.17)

project(iso8583)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)

include_directories(include)
include_directories(${spdlog_cmake_SOURCE_DIR})

file(GLOB HEADERS include/*.h)

add_executable(iso8583 main.cpp ${HEADERS})

if (MSVC)
    target_compile_options(iso8583 PRIVATE /W4 /WX)
else()
    target_compile_options(iso8583 PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
