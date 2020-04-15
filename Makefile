CC = gcc
FLAGS = -Wall -g
LIBFLAGS = -Wall -Werror -g -shared

all: task1.1 task1.2 task1.3

task1.1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) main1_1.o hello_Ariel.o -o task1.1

task1.2: main1_2.o hello_Ariel.so
	$(CC) $(FLAGS) main1_2.o -o task1.2 -Wl,-rpath=. hello_Ariel.so

task1.3: main1_3.o hello_Ariel.so
	$(CC) $(FLAGS) main1_3.o -fPIC -ldl -o task1.3

hello_Ariel.so: hello_Ariel.o hello_Ariel.h
	$(CC) $(LIBFLAGS) hello_Ariel.o -o hello_Ariel.so

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_2.o: main1_2.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_2.c

main1_3.o: main1_3.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_3.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so task1.1 task1.2 task1.3