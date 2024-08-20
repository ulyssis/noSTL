cmake_minimum_required(VERSION 3.26)
project(googleTestTutorial)
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -O2)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#include subdirectories
add_subdirectory(lib)
add_subdirectory(test)


