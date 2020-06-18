all: main.c
	gcc -c main.c -o main.o
	gcc main.o -o main
	./main
	rm *.o && rm main

test: test.c
	gcc -c test.c -o test.o
	gcc test.o -o test
	./test
	rm *.o && rm test
