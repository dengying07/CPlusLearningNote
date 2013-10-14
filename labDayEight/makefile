all:EX1 EX2 EX3 EX4

EX1:ex1.cpp
	g++ -Wall ex1.cpp -o EX1

EX2:ex2.o ex2list.o
	g++ -Wall -g ex2.o ex2list.o  -o EX2

ex2.o:ex2.cpp ex2.h
	g++ -Wall -c ex2.cpp -o ex2.o

ex2list.o:ex2list.cpp ex2.h
	g++ -Wall -c ex2list.cpp -o ex2list.o

EX3:ex3.cpp
	g++ -Wall ex3.cpp -o EX3

EX4:ex4.cpp
	g++ -g -Wall ex4.cpp -o EX4

clean: 
	rm -f *.o EX1 EX2 EX3 EX4
