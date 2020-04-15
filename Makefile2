CC=gcc
AR=ar
FLAGS= -Wall -g

all: main2_1 main2_2 main2_3 main2_4

main: main2_1.c main2_2.c main2_3.c
	$(CC) $(FLAGS) main2_1.c main2_2.c main2_3.c -o main

main2_1: main2_1.c
	$(CC) $(FLAGS) main2_1.c -o main2_1

main2_2: main2_2.c
	$(CC) $(FLAGS) main2_2.c -o main2_2

main2_3: main2_3.c
	$(CC) $(FLAGS) main2_3.c -o main2_3

main2_4: main2_4.c
	$(CC) $(FLAGS) main2_4.c -o main2_4

.PHONY: clean all

clean:
	rm -f *.o *.a *.so main2_1 main2_2 main2_3 main2_4