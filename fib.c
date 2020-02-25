#include <stdio.h>
#include <stdlib.h>

int rec_fib(int n) {
	
	if(n <= 2) {
		return 1;
	}

	return rec_fib(n-1) + rec_fib(n-2);
}

int main(int argc, char** argv) {
	printf("%d\n",rec_fib(atoi(argv[1])));
	return 0;
}
