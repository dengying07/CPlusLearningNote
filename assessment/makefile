ex: main.o tube.o
	g++ -Wall -g main.o tube.o -o ex

main.o:main.cpp tube.h
	g++ -Wall -g -c main.cpp -o main.o

tube.o:tube.cpp tube.h
	g++ -Wall  -g -c tube.cpp -o tube.o

clean:
	rm -f *.o ex
