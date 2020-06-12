#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	int qu[1000];
	int rear, frnt;
} queue;

void init(queue *q)
{
	q->frnt = 1;
	q->rear = 0;
}

void insert(queue *q, int x) {
	if(q->rear < 999) 
	{
		q->rear++;
		q->qu[q->rear]=x;
	}
}

int isempty(queue *q) {
	return q->rear < q->frnt;
}

int remove_(queue *q) {
  int x, h;
  
  x = q->qu[q->frnt];
  
  for(h = q->frnt; h < q->rear; h++) {
    q->qu[h] = q->qu[h+1];
  }

  q->rear--;
  return x;
}

int main()
{
	int N;
	int M;
	char nothing;

	FILE *fp;
	fp = fopen("lab.txt", "r");

	fscanf(fp, "%d", &N);
	fscanf(fp, "%d", &M);
	fscanf(fp, "%c", &nothing);

	char *arr = malloc(sizeof(char) * N * M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			fscanf(fp, "%c", (arr + i * M + j));
		}
		fscanf(fp, "%c", &nothing);
	}

	fclose(fp);

	for(int i = 0; i < N; i++)	
	{
		for(int j = 0; j < M; j++)
		{
			printf("%c", *(arr + i*M + j));
		}
		printf("\n");
	}

	printf("\n");

	int *num_arr = malloc(sizeof(int) * N * M);

   for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(*(arr + i*M + j) == '.')
			{
				*(num_arr + i*M + j) = INT_MAX;
			} else {
				*(num_arr + i*M + j) = -1;
			}
		}
	}

	int nc = 0;

	queue *Q1 = (queue *)malloc(sizeof(queue));
	queue *Q2 = (queue *)malloc(sizeof(queue));

	remove_(Q1);
	remove_(Q2);
	insert(Q1, 0);

	*(num_arr) = nc;

	nc++; 

	while(!isempty(Q1))
	{
		while(!isempty(Q1))
		{

			int i = remove_(Q1);

			int k = i / M;
			int j = i % M;

			if(k < N-1 && *(num_arr + (k + 1)*M + j) > nc)
			{
				*(num_arr + (k + 1)*M + j) = nc;
				insert(Q2, (k+1)*M + j);
			}

			if(j < M-1 && *(num_arr + k*M + j + 1) > nc)
			{
				*(num_arr + k*M + j + 1) = nc;
				insert(Q2, k*M + j+1);
			}

			if(k > 0 && *(num_arr + (k - 1)*M + j) > nc)
			{
				*(num_arr + (k - 1)*M + j) = nc;
				insert(Q2, (k-1)*M + j);
			}

			if(j > 0 && *(num_arr + k*M + j - 1) > nc)
			{
				*(num_arr + k*M + j - 1) = nc;
				insert(Q2, k*M + j-1);
			}

		}

		while(!isempty(Q2))
		{
			int i = remove_(Q2);
			insert(Q1, i);
		}

		nc++;

	}

	if(*(num_arr + N*M - 1) != INT_MAX)
	{
		int j = M;
		int k = N-1;

		while(nc)
		{
			nc--;

			if(k < N-1 && *(num_arr + (k+1)*M + j) == nc)
			{
				k++;
				*(arr + k*M + j)  = '+';
				continue;
			}

			if(j < M-1 && *(num_arr + k*M + j+1) == nc)
			{
				j++;
				*(arr + k*M + j)  = '+';
				continue;
			}

			if(k > 0 && *(num_arr + (k-1)*M + j) == nc)
			{
				k--;
				*(arr + k*M + j)  = '+';
				continue;
			}

			if(j > 0 && *(num_arr + k*M + j-1) == nc)
			{
				j--;
				*(arr + k*M + j) = '+';
				continue;
			}
		}

	} else {
		printf("Лабиринт непроходим.\n");
	}

	free(Q1);
	free(Q2);

	for(int i = 0; i < N; i++)	
	{
		for(int j = 0; j < M; j++)
		{
			printf("%c", *(arr + i*M + j));
		}
		printf("\n");
	} 

	free(arr);
	free(num_arr);
	return 0;
}