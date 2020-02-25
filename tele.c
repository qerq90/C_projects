#include <stdio.h>

char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
	for(int i = 0;i < 14;i++)
	{
		phnum[i] = 'l';	
	}

	phnum[0] = '(';
	phnum[4] = ')';
	phnum[5] = ' ';
	phnum[9] = '-';
	
	int i = 0;
	while(i < 10) 
	{
		int j = 0;
		while(j < 15)
		{
			if(phnum[j] == 'l')
			{
				phnum[j] = nums[i];
				break;
			}

			j++;
		}

		i++;
	}
	phnum[15] = '\0';
	
	return phnum;
}

int main()
{
	char num[15];
	unsigned char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
	create_phone_number(num,arr);
	printf("%s",num);
	return 0;
}
