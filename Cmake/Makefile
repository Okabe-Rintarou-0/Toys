# 2021年了 还是用CMake吧~
CC := gcc
CXX := g++

# 伪目标
.PHONY: all
all: test

# .o文件们
objects := main.o Test.o

# .o文件可以自动推断依赖的同名.cpp文件
# 但是需要制定.h依赖，如果将来Test.h发生更改，可以重新编译
# Makefile不能自动识别.h依赖
main.o: test/Test.h

# 本来需要这么写，但是没必要，可以简化成上面那样
main.o: test/Test.h
	$(CXX) -c main.o main.cpp # -c 只编译 不链接 只生成中间文件(.o)

Test.o: test/Test.h

# target name: dependencies
#	commands
# $@ 自动推断target名字
# 这段代码不用修改，只需修改objects即可
test: $(objects)
	$(CXX) -o $@ $(objects)

.PHONY: clean
clean:
	rm -f test $(objects)