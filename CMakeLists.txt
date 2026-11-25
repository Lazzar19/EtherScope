cmake_minimum_required(VERSION 3.16)

project(ping
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(ping
    src/main.c
    src/utils.c
)

target_include_directories(ping PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ping PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
