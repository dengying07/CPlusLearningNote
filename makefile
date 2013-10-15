<<<<<<< HEAD
ex: main.o tube.o
	g++ -Wall -g main.o tube.o -o ex

main.o:main.cpp tube.h
	g++ -Wall -g -c main.cpp -o main.o

tube.o:tube.cpp tube.h
	g++ -Wall  -g -c tube.cpp -o tube.o

clean:
	rm -f *.o ex
=======
TUT2:tut2.cpp
	g++ -Wall tut2.cpp -o TUT2
>>>>>>> 5b649eb733cd4d8c884fda8943b16e2e0c9fd7ed
