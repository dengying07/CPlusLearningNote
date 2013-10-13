ex: main.o tube.o
	g++ -Wall main.o tube.o -o ex

main.o:main.cpp tube.h
	g++ -Wall -c main.cpp -o main.o

tube.o:main.cpp tube.h
	g++ -Wall -c tube.cpp -o tube.o

clean:
	rm -f *.o ex
