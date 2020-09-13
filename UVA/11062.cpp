#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

char str[MAX + MAX];
char token[MAX][100];
long Maxlen;
long I;

int sorting(const void *a, const void *b)
{
	return (strcmp( (char*)a, (char*)b ) );
}

char *delms = " ~!@#$%^&*()_+`1234567890=[]{}|;\':,.<>/?\\\"\n\t";
void tokenize()
{
	char *p;

	p = strtok(str, delms);
	while(p != NULL)
	{
		long len = strlen(p);
		long k = 0;
		long j = 0;
		for(j = 0; j < len; j++)
		{
			if(p[j] >= 'a' && p[j] <= 'z')
				token[I][k++] = p[j];
			else if(p[j] >= 'A' && p[j] <= 'Z')
				token[I][k++] = p[j] + 32;
			else
				token[I][k++] = p[j];
		}
		token[I][k] = '\0';
		p = strtok(NULL, delms);
		I++;
	}
}

void init()
{
	for(long i = 0; i < I; i++)
	{
		long len = strlen(token[i]);
		for(long j = 0; j < len; j++)
			token[i][j] = 0;
	}
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	long j, len;	
	char temp[MAX];

	while(gets(temp))
	{
		Maxlen = I = 0;

		len = strlen(temp);
		if(len == 0)
			continue;

		if(temp[len - 1] == '-')
		{
			temp[len - 1] = '\0';
			strcat(str, temp);
		}

		else
		{
			temp[len] = ' ';
			temp[len + 1]  = '\0';
			strcat(str, temp);
		}
		
		while(gets(temp))
		{
			len = strlen(temp);
			if(len == 0)
				continue;

			if(temp[len - 1] == '-')
			{
				temp[len - 1] = '\0';
				strcat(str, temp);
			}

			else
			{
				temp[len] = ' ';
				temp[len + 1]  = '\0';
				strcat(str, temp);				
			}
		}
		Maxlen = strlen(str);
		tokenize();

		qsort((void *)token, I, sizeof(token[0]), sorting);
		
		puts(token[0]);
		for(j = 1; j < I; j++)
		{
			if( (strcmp(" ", token[j])==0) || strcmp(token[j], token[j - 1]) == 0)
				continue;
			puts(token[j]);
		}
		init();
	}
	return 0;
}