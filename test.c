#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leftMoreThanRight(unsigned char *string1, unsigned char *string2)
{   
    int i = 0;

    while(*(string1 + i) && *(string2 + i))
    {
        if(*(string1 + i) < *(string2 + i))
        {
            return 0;
        }

        if(*(string1 + i) > *(string2 + i))
        {
            return 1;
        }

        i++;
    }

    return -1;
}

int main()
{
    char string[] = "лбвгд";
    char string2[] = "ла";
    
    printf("%d \n", leftMoreThanRight(string, string2));

    return 0;
}