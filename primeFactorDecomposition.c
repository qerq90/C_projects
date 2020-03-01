#include "stdio.h"
#include "stdlib.h"

int check_size(char *string)
{
	int i = 0;
	while(*(string + i) != '\0') i++;
	return i;
}

char *primeFactors(int n) 
{
	char *result = malloc(sizeof(char) * 200);
	int size = 0;
	int fac = 2;

	while(fac <= n) 
	{
		int count = 0;
		while(!(n % fac))
		{
			n /= fac;
			count++;
		}

		if(count)
		{
			if(count == 1)
			{
				*(result + size) = '(';
				size++;
				sprintf((result + size), "%d", fac);
				size = check_size(result);
				*(result + size) = ')';
				size++; 
			} else {
				*(result + size) = '(';
				size++;
				sprintf((result + size), "%d", fac);
				size = check_size(result);
				*(result + size) = '*';
				size++;
				*(result + size) = '*';
				size++;
				sprintf((result + size),"%d",count);
				size = check_size(result);
				*(result + size) = ')';
				size++;
			}
		}

		fac++;
	}
	*(result + size) = '\0'; 
	return result;
}

int main(int argc, char *argv[])
{
	printf("%s\n",primeFactors(86240));
	return 0;
}