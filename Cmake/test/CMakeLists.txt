add_library(libtest STATIC Test.cpp)

target_include_directories(libtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})