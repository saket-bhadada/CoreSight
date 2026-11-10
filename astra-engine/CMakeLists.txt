cmake_minimum_required(VERSION 3.24)
project(astra-engine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

option(ASTRA_SANITIZE "Build with ASan + UBSan" OFF)
if(ASTRA_SANITIZE)
    add_compile_options(-fsanitize=address,undefine -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefine)
endif()

include