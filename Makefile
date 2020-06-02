all: main.c
	gcc -c main.c -o main.o
	gcc main.o -o main
	./main
	rm *.o && rm main