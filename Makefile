CC = g++
FLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual



all: main.o text/text.o sort/sort.o io/io.o
	g++ main.o sort/sort.o io/io.o text/text.o
	a.exe

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

text/text.o: text/text.cpp
	$(CC) $(FLAGS) text/text.cpp

sort/sort.o: sort/sort.cpp
	$(CC) $(FLAGS) sort/sort.cpp

io/io.o: io/io.cpp
	$(CC) $(FLAGS) io/io.cpp
