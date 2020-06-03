#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    int shift;

    printf("Введите shift length array:\n");
    scanf("%d %d", &shift, &length);

    if(length <= 0)
    {
        printf(" ");
        return 0;
    }

    int *arr = (int *) malloc(sizeof(int) * length);
    
    for(int i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int *new_arr = (int *) malloc(sizeof(int) * length);

    for(int i = 0; i < length; i++)
    {
        int new_index = i + shift;
        if(new_index >= length) new_index %= length;
        if(new_index < 0) new_index += length;

        new_arr[new_index] = arr[i];
    }

    for(int i = 0; i < length; i++)
    {
        printf("%d ",new_arr[i]);
    }

    printf("\n");
    free(arr);
    free(new_arr);

    return 0;
}
