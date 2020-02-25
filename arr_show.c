#include <stdio.h>
#include <stdlib.h>

void show_arr(int* arr, int arr_size)
{
	for(size_t i = 0;i < arr_size;i++) 
	{
		printf("%d\n",arr[i]);
	}
}

int main(int argc, char** argv) 
{	
	int some_arr[10];
	
	for(int i = 0;i < 10;i++)
	{
		some_arr[i] = i * (i - 4);
	}	

	show_arr(some_arr, 10);

	return 0;
}
