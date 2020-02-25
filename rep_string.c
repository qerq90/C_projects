#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	char *string = argv[1];
	char l = '!';

	for(size_t i = 0;string[i] != '\0';i++) 
	{
		for(size_t j = i+1;string[j] != '\0';j++)
		{
			if(toupper(string[i]) == toupper(string[j]))
			{
				l = string[i];
				goto stop;
			}
		}
	}

stop:
	printf("%c\n",l);
	return 0;
}
