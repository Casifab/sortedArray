CXXFLAGS = -Wall -pedantic -Wextra -pedantic-errors -DNDEBUG
CXXFLAGS_DEBUG = -Wall -pedantic -Wextra -pedantic-errors -g

BASIC_FLAGS = -DNDEBUG

main: main.o
	g++ main.o -o main

main.o: sortedarray.h main.cpp
	g++ -c main.cpp -o main.o