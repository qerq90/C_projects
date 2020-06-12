#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int x;
    int y;
} POINT;

int rotate(POINT *A, POINT *B, POINT *C)
{
  return (B->x - A->x)*(C->y - B->y)-(B->y - A->y)*(C->x - B->x);
}

int main()
{
	FILE *fp;
	fp = fopen("grakhams.txt", "r");

    POINT **points = malloc(sizeof(POINT *) * 1000);
    int points_length = 0;
    int num, x, y;
	
    while(fscanf(fp, "%d %d %d", &num, &x, &y) != EOF)
    {
        POINT *point = malloc(sizeof(POINT));
        point->num = num;
        point->x = x;
        point->y = y;

        *(points + points_length) = point;

        points_length++;

    }

    fclose(fp);

    // #1
    for (int i = 0; i < points_length; i++)
    {
        if((*points)->x > (*(points + i))->x)
        {
            POINT * temp = *points;
            *points = *(points + i);
            *(points + i) = temp;
        }
    }

    // #2
    for (int i = 2;i < points_length; i++)
    {
        int j = i;
        while(j > 1 && rotate(*(points), *(points + j - 1), *(points + j)) < 0)
        {
            POINT * temp = *(points + j - 1);
            *(points + j - 1) = *(points + j);
            *(points + j) = temp;

            j--;
        }
    }

    POINT **points_result = malloc(sizeof(POINT *) * 1000);
    *(points_result) = *(points);
    *(points_result + 1) = *(points + 1);
    int points_result_length = 2;

    // #3 
    for(int i = 2; i < points_length; i++)
    {
        while(rotate(*(points_result + points_result_length - 2), *(points_result + points_result_length - 1), *(points + i)) < 0)
        {
            *(points_result + points_result_length) = NULL;
            points_result_length--;
        }

        *(points_result + points_result_length) = *(points + i);

        points_result_length++;
    }

    for (int i = 0; i < points_result_length; i++)
    {
        printf("%d ", (*(points_result + i))->num);
    }

    printf("\n");
    
	return 0;
}