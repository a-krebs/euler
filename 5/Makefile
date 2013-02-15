solution: solution.o
	gcc -Wall -std=c99 -o solution solution.o

solution.o: solution.c solution.h
	gcc -Wall -std=c99 -c solution.c

clean:
	-rm -f *.o solution core
