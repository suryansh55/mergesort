CC = gcc

all: mergesort mergesortparallel

mergesort: mergesort.o
	$(CC) -o mergesort mergesort.o -lm

mergesort.o: mergesort.c
	$(CC) -c mergesort.c

mergesortparallel: mergesortparallel.o
	$(CC) -fopenmp mergesortparallel.o -o mergesortparallel

mergesortparallel.o: mergesortparallel.c
	$(CC) -fopenmp -c mergesortparallel.c

clean:
	rm -f *.o mergesort mergesortparallel
