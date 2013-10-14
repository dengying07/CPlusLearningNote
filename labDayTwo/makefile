EX31:ex31.o ex31imp.o
	g++ ex31.o ex31imp.o -o EX31

ex31.o:conversions.cpp conversions.h
	g++ -c conversions.cpp -o ex31.o

ex31imp.o:RobMillerEA3-2.cpp conversions.h
	g++ -c RobMillerEA3-2.cpp -o ex31imp.o

Ex2:ex2.o ex2imp.o
	g++ ex2.o ex2imp.o -o Ex2

ex2imp.o:ex2imp.cpp ex2.h
	g++ -c ex2imp.cpp -o ex2imp.o

ex2.o:ex2.cpp ex2.h
	g++ -c ex2.cpp -o ex2.o 

ex3.o:ex3.cpp
	g++ -Wall -c ex3.cpp -o ex3.o

ex3imp.o:ex3imp.cpp 	g++ -Wall -c ex3imp.cpp -o ex3imp.o

Ex3: ex3.o ex3imp.o
	g++ -Wall ex3.o ex3imp.o -o Ex3

Statistics:statistics.cpp 
	g++ -Wall statistics.cpp -o Statistics
clean: 
	rm -f execute *.o
