// if(ch==' '||ch=='?'||ch=='!'||ch==','||ch=='.')

#include<stdio.h>
#include<string.h>
#define MAX 1000

char str[MAX];
int store[MAX];

int maximum, minimum;
char delms[] = {" ?!,."};
void find_word()
{
	char *p;
	int i = 0, j = 0;

	p = strtok(str, delms);
	while(p != NULL)
	{
		int len = strlen(p);
		for(i = 0; i < len; i++)
		{
			if( (p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z') )
				j++;
		}
		p = strtok(NULL, delms);

		if(j < minimum)
			minimum = j;

		if(j > maximum)
			maximum = j;

		store[j]++;
		j = 0;
	}
}

void init(int Tlen)
{
	for(int i = 0; i <= Tlen; i++)
	{
		store[i] = 0;
		str[i] = 0;
	}
	return ;
}

int main()
{
//	freopen("in.txt", "r", stdin);

	char temp[MAX];
	int len = 0;
	int Tlen = 0;

	while(gets(temp))
	{
		len = strlen(temp);
		if(len == 0)
			continue;

		if(strcmp("#", temp)==0)
			break;

		if(temp[len - 1] == '-')
			strcat(str, temp);
		else
		{
			temp[len] = ' ';
			temp[len + 1] = '\0';
			strcat(str, temp);
		}

		while(gets(temp))
		{
			len = strlen(temp);
			if(len == 0)
				continue;

			if(strcmp("#", temp)==0)
				break;

			if(temp[len - 1] == '-')
				strcat(str, temp);
			else
			{
				temp[len] = ' ';
				temp[len + 1] = '\0';
				strcat(str, temp);
			}
		}

		Tlen = strlen(str);

		maximum = -1;
		minimum = 0xfffffff;

		find_word();
		for(int i = minimum; i <= maximum; i++)
		{
			if(store[i] != 0)
				printf("%ld %ld\n", i, store[i]);
		}
		printf("\n");
		init(Tlen);
	}
	return 0;
}

