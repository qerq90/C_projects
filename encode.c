#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int in_arr(char sym, char *ps)
{
	int i = 0;
	int flag = 0;
	while(ps[i] != '\0')
	{
		if(toupper(sym) == toupper(ps[i]) && flag == 1)
		{
		    return 1;
		} else if(toupper(sym) == toupper(ps[i])) {
			flag = 1;
		}
		i++;
	}

	return 0;
}

char *DuplicateEncoder(char *ps)
{
	int i = 0;

	while(*(ps + i))
	{
		i++;
	}

	char *ps1 = malloc(i);
	strcpy(ps1,ps); 
	i = 0;
	while(ps[i])
	{
		if(in_arr(ps[i],ps))
		{
			ps1[i] = ')';
		} else {
			ps1[i] = '(';
		}
		i++;
	}

  	return ps1;
}


int main() {
	char l[] = "Prespecialized";
	printf("%s\n",DuplicateEncoder(l));
	return 0;  
}