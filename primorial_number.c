#include <stdio.h>
#include <stdlib.h>

void get_next_prime(int *p, int i) 
{
    int l = *(p + i);
    while(1) 
    {
        l++;
        
        for(size_t z = 0;z < i;z++) 
        {
            if(l % p[z] == 0) goto exit;
        }
        break;
        exit: continue;
    }

    *(p + i + 1) = l;
}

unsigned long long num_primorial(unsigned n)
{
    int *p = malloc(sizeof(int) * n); 
    
    int l = 0;
    p[0] = 2;
    unsigned long long num = 2;

    for (size_t i = 1; i < n; i++)
    {
        get_next_prime(p,l);
        num *= *(p + l + 1);
        l++;
    }

    free(p);

    return num;
}

int main(int argc,char *argv[])
{
    printf("%llu\n", num_primorial(atoi(argv[1])));

    return 0;
}