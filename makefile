ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif

all: main.o rand.o
	$(CC) -o test main.o rand.o

main.o: main.c rand.h
	$(CC) -c main.c

rand.o: rand.c rand.h
	$(CC) -c rand.c

run:
	./test

memcheck:
	valgrind --leak-check=yes ./test

clean:
	rm *.o
	rm *~
