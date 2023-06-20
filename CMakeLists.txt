cmake_minimum_required(VERSION 3.0.0)
project(libthatcord VERSION 0.1.0 LANGUAGES C CXX)

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
    libthatcord_test
    libthatcord/libthatcord_test.cpp
)

target_link_libraries(
    libthatcord_test
    gtest_main
)

# Utilty Test
add_executable(
    request_test
    libthatcord/utility/HTTPRequest.cpp
    libthatcord/utility/HTTPRequest_Test.cpp
)
target_link_libraries(
    request_test
    ${Boost_BEAST_LIBRARY}
    gtest_main)

include(GoogleTest)
gtest_discover_tests(
    libthatcord_test
)
gtest_discover_tests(
    request_test
)

add_library(
    libthatcord
    libthatcord/libthatcord.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
