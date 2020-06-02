#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    time_t t0 = time(0);

    int n = rand() % 31;

    int user_size;
    printf("Size:\n");
    scanf("%d", &user_size);
    printf("\n");

    FILE *fp;
    fp = fopen("input.txt", "w");
    
    for(int i = 0; i < n; i++) 
    {
        fprintf(fp, "%ld\n", random() % user_size);
    }

    fclose(fp);

    fp = fopen("input.txt", "r");
    
    int i = 0;
    int numbers[n];

    while(fscanf(fp, "%d", &numbers[i]) != EOF)
    {
        i++;
    }

    fclose(fp);
    fp = fopen("output.txt", "w");

    for(int i = 0; i < n; i++) 
    {
        if(numbers[i] % 7 == 0 && numbers[i] % 5 == 0)
        {
           fprintf(fp, "ПЯТЬСЕМЬ\n"); 
        } else if(numbers[i] % 7 == 0)
        {
            fprintf(fp, "СЕМЬ\n");   
        } else if(numbers[i] % 5 == 0)
        {
            fprintf(fp, "ПЯТЬ\n");
        } else {
            fprintf(fp, "%d\n", numbers[i]);
        }

    }

    fclose(fp);

    i = 0;
    while(i*i < n)
    {
        i++;
    }
    i--;

    int size_of_matrix = i;

    int numbers_matrix[size_of_matrix][size_of_matrix];

    for(int j = 0; j < n; j++)
    {
        numbers_matrix[j / size_of_matrix][j % size_of_matrix] = numbers[j];
    }

    int sum_of_columns[size_of_matrix];
    int main_sum = 0;

    for(int i = 0; i < size_of_matrix; i++)
    {
        sum_of_columns[i] = 0;
    }

    for(int i = 0; i < size_of_matrix; i++)
    {
        int row_sum = 0;
        for(int j = 0; j < size_of_matrix; j++)
        {
            printf("%3d ", numbers_matrix[i][j]);
            main_sum += numbers_matrix[i][j];
            row_sum += numbers_matrix[i][j];
            sum_of_columns[j] += numbers_matrix[i][j]; 
        }
        printf(" %3d\n",row_sum);
    }

    printf("\n");

    for(int i = 0; i < size_of_matrix;i++)
    {
        printf("%3d ", sum_of_columns[i]);
    }

    printf("\n\nSum of all columns/rows = %d\n", main_sum);

    time_t t1 = time(0);
    double time_in_seconds = difftime(t1, t0);
    printf("\nWork time - %.3lf\n", time_in_seconds);

    return 0;
}