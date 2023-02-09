CFLAGS = -Wall -g

all: main.o
	gcc -o main main.o $(CFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

clean:
	rm *.o main
