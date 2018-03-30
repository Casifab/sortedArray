main: main.o
	g++ main.o -o main

main.o: sortedarray.h main.cpp
	g++ -c main.cpp -o main.o