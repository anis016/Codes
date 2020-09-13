#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

long excuse, keyword, max;
char key[MAX][MAX];
char temp[MAX];
char buf[MAX];

struct List
{
	char sentence[MAX];
	char tempo[MAX];
	long counter;
}list[MAX];

long search(char *s)
{
	long high, low, mid, flag;

	high = keyword - 1;
	low = 0;
	while(low <= high)
	{
		mid = (high + low) / 2;
		flag = strcmp(s, key[mid]);

		if(flag == 0)
			return 1;
		else if(flag > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

long _isalpha(char s)
{
	if( s >= 'a' && s <= 'z')
		return 1;
	return 0;
}

void process()
{
	long i, j, flag, len, k;

	max = -0xfffffff;
	for(i=0; i<excuse; i++)
	{
		len = strlen(list[i].tempo);
		for(j=0,k=0; j<len; j++)
		{
			if( _isalpha(list[i].tempo[j]) )
				temp[k++] = list[i].tempo[j];

			else if( !_isalpha(list[i].tempo[j]) )
			{
				temp[k] = '\0';

				if(strlen(temp) != 0)
				{
					flag = search(temp);
					if(flag == 1)
						list[i].counter++;

					if(max < list[i].counter)
						max = list[i].counter;
				}
				k = 0;
			}
		}
	}
	
	return ;
}

int sorting_string(const void *a, const void *b)
{
	return (strcmp( (char *)a, (char *)b ) );
}

int main()
{
//	freopen("in.txt", "r", stdin);
	
	long i, j, len, cnt = 1;

	while(scanf("%ld %ld", &keyword, &excuse)==2)
	{		
		for(i=0; i<keyword; i++)
			scanf("%s", key[i]);

		qsort((void *)key, keyword, sizeof(key[0]), sorting_string);

		getchar();
		for(i=0; i<excuse; i++)
		{
			gets(list[i].sentence);
			len = strlen(list[i].sentence);
			for(j = 0; j < len ; j++)
				list[i].tempo[j] = tolower(list[i].sentence[j]);
			list[i].counter = 0;
		}

		process();

		printf("Excuse Set #%ld\n", cnt++);
		for(i=0; i<excuse; i++)
		{
			if(list[i].counter == max)
				printf("%s\n", list[i].sentence);
		}
		printf("\n");
	}
	return 0;
}