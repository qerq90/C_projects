#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_length(int * arr)
{   
    int i = 0;
    while(*(arr + i)) i++;
    return i;
}

int main()
{
    int * arr = calloc(100, sizeof(int));

    for(int i = 0; i < 10; i++)
    {
        *(arr + i) = i+1;
    }

    printf("%d \n", get_length(arr));

    return 0;
}