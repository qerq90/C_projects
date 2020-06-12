#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char * data;
  struct node **list;   
  unsigned char color;
} NODE;

NODE * get_node(NODE ** nodes, int node_num, int size)
{
    for(int i = 0; i < size; i++)
    {
        int this_node_num = atoi((*(nodes + i))->data);
   
        if(this_node_num == node_num)
        {
            return *(nodes + i);
        }
    }
}

int get_length(int * arr)
{   
    int i = 0;
    while(*(arr + i)) i++;
    return i;
}

int find_way(NODE * start_node, NODE * finish_node, int * result_arr)
{
    if(atoi(start_node->data) == atoi(finish_node->data)) return 1;
    int arr_length = get_length(result_arr);

    for(int i = 0; *(start_node->list + i); i++)
    {
        if((*(start_node->list + i))->color)
        {
            result_arr[arr_length] = atoi((*(start_node->list + i))->data);
            (*(start_node->list + i))->color = 0;
            
            if(find_way((*(start_node->list + i)), finish_node, result_arr))
            {
                return 1;
            }

            (*(start_node->list + i))->color = 1;
            result_arr[arr_length] = 0;
        }
    }

    return 0;
}

int main()
{
	FILE *fp;
	fp = fopen("graph.txt", "r");
	
    char n;
    int l;

	char* string = malloc(sizeof(char) * 1000);

	NODE ** nodes = malloc(sizeof(NODE *) * 1000);

    int i = 0;
    int j = 0;
	while((n = fgetc(fp)) != EOF)
	{
        if(n == '\n')
        {
            *(string + i) = '\0';

            NODE * node = (NODE *)malloc(sizeof(NODE));
            node->data = (char *)malloc(sizeof(char) * i);
            strcpy(node->data, string);
            node->color = 1;
            *(nodes + j) = node; 
            j++; 

            while(i)
            {
                *(string + i) = '0';
                i--;
            }
        } else {
            *(string + i) = n;     
            i++;
        }
	}

    *(string + i) = '\0';

    NODE * node = (NODE *)malloc(sizeof(NODE));
    node->data = (char *)malloc(sizeof(char) * i);
    strcpy(node->data, string);
    node->color = 0;
    *(nodes + j) = node; 
    j++;

	fclose(fp);

    for(int i = 0;i < j;i++)
    {
        (*(nodes + i))->list = malloc(sizeof(NODE *) * j);
    }

    for(int i = 0;i < j;i++)
    {
        int node_num = atoi((*(nodes + i))->data);
        int k = 0;
        int l = 0;

        while(*((*(nodes + i))->data + k))
        {
            if(*((*(nodes + i))->data + k) == ' ')
            {
                int node_bond = atoi(((*(nodes + i))->data + k + 1));
                *((*(nodes + i))->list + l) = get_node(nodes, node_bond, j);
                
                l++;
            }

            k++;
        }

        sprintf((*(nodes + i))->data, "%d", node_num);
    }

    printf("Выберите две точки из предложенных: ");

    for(int i = 0; i < j; i++)
    {
        printf("%s ", (*(nodes + i))->data);
    }

    printf("\n");

    int start,end;

    scanf("%d %d", &start, &end);

    int * result_arr = calloc(1000, sizeof(int));
    
    node = get_node(nodes, start, j);
    NODE * finish_node = get_node(nodes, end, j);
    node->color = 0;
    *(result_arr) = atoi(node->data);
    
    if(find_way(node, finish_node, result_arr))
    {
        printf("\nResulting way= ");

        for(int i = 0; i < get_length(result_arr); i++)
        {
            printf("%d ", *(result_arr + i));
        }

        printf("\n");
    } else {
        printf("No way to get to the end\n");
    }

	return 0;
}