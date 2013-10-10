all:EX1 EX2 EX3 EX4

EX1:ex1.o ex1driver.o
	g++ -g -Wall ex1.o ex1driver.o -o EX1

ex1.o:ex1.cpp ex1.h
	g++ -c -g -Wall ex1.cpp -o ex1.o

ex1driver.o:ex1driver.cpp ex1.h
	g++ -c -g -Wall ex1driver.cpp -o ex1driver.o
 
EX2:ex2.o ex2driver.o
	g++ -g -Wall ex2.o ex2driver.o -o EX2

ex2.o:ex2.cpp ex2.h
	g++ -c -g -Wall ex2.cpp -o ex2.o

ex2driver.o:ex2driver.cpp ex2.h
	g++ -c -g -Wall ex2driver.cpp -o ex2driver.o

EX3:ex3.cpp
	g++ -g -Wall ex3.cpp -o EX3

EX4:ex4.cpp	
	g++ -g -Wall ex4.cpp -o EX4

clean : 
	rm -f *.o EX1 EX2 EX3
