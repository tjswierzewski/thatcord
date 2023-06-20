cmake_minimum_required(VERSION 3.0.0)
project(libthatcord VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    libthatcord_test
    libthatcord/libthatcord_test.cpp
)
target_link_libraries(
    libthatcord_test
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(libthatcord_test)
add_library(libthatcord libthatcord/libthatcord.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)