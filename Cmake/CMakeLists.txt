# CMake可以自动找到.h头文件依赖 不需要指定 #

# 会去执行子目录里的CMake
add_subdirectory(test)

#[[
    cmake -B build 生成构建目录
    cmake --build build 执行构建
    ./build/xxx
#]]
add_executable(test main.cpp)

target_link_libraries(test libtest)

