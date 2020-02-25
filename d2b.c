#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* x, int begin, int end)
{
	// recursive reversing
	char c;

	if (begin >= end)
		return;

	c          = *(x+begin);
	*(x+begin) = *(x+end);
	*(x+end)   = c;

	reverse(x, ++begin, --end);
}

char* d2b(int numb) {
	char* text = malloc(sizeof(char) * 100);
	char sign[2];
	
	if (numb == 0) {
		strcpy(text, "0");
		return text;
	}
	// checking for the sign
	if(numb < 0) {
		strcpy(sign, "-");
		numb *= -1;
	} else {
		strcpy(sign,"");
	}
	
	while (numb > 1)
	{
	 	char sym[10];
		sprintf(sym, "%d", numb % 2);
	  	strcat(text,sym);
	 	numb /= 2;
	}
	// the last must always be 1
	strcat(text, "1");
	strcat(text,sign);
	
	reverse(text, 0, strlen(text)-1);
	
	return text;
};

int main(int argc, char** argv) {
	
	int a = atoi(argv[1]);

	char* s = d2b(a);

	printf("%s\n", s);

	return 0;
};
