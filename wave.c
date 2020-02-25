#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void wave(char *y, char **target)
{
  char *p = y;
  for (char i = 0; *p; ++p) {
    if (*p != ' ') {
      strcpy(target[i], y);
      target[i][p - y] = toupper(*p);
      i++;
    }
  }
}

int main()
{
	char *y = "some";
	char **target = malloc(sizeof(char*) * 4);

	for(int i = 0;i < 4;i++) 
	{
		target[i] = malloc(sizeof(char) * 5);
	}
	wave(y,target);

	for(int i = 0;i < 4;i++)
	{
		printf("%s\n",target[i]);
	}

	for(int i = 0;i < 4;i++) 
	{
		free(target[i]);
	}

	free(target);


	return 0;
}
