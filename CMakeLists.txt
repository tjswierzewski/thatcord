cmake_minimum_required(VERSION 3.0.0)
project(LibThatCord VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/9b12f749fa972d08703d8459e9bf3239617491ca.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})

# Main Test
add_executable(
    LibThatCord_Test
    LibThatCord/LibThatCord_Test.cpp
)

target_link_libraries(
    LibThatCord_Test
    gtest_main
)

# Utilty Test
add_executable(
    Request_Test
    LibThatCord/utility/HTTPRequest.cpp
    LibThatCord/utility/HTTPRequest_Test.cpp
)
target_link_libraries(
    Request_Test
    ${Boost_BEAST_LIBRARY}
    gtest_main)

include(GoogleTest)
gtest_discover_tests(
    LibThatCord_Test
)
gtest_discover_tests(
    Request_Test
)

add_library(
    LibThatCord
    LibThatCord/LibThatCord.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
