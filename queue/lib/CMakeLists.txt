# lib/CMakeLists.txt
add_library(simpleVector INTERFACE)
target_include_directories(simpleVector
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR})
