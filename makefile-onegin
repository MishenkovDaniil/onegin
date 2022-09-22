CC = g++
FLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual



all: main.o text.o sort.o io.o
	g++ main.o sort.o io.o text.o
	a.exe

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

text.o: text.cpp
	$(CC) $(FLAGS) text.cpp

sort.o: sort.cpp
	$(CC) $(FLAGS) sort.cpp

io.o: io.cpp
	$(CC) $(FLAGS) io.cpp

