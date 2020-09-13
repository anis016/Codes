#include<stdio.h>
#include<string.h>
#define MAX 256

struct List
{
	char find[82];
	char replace[82];
}list[MAX];
char trans[MAX];

int N;

void read_input()
{
	int i;
	for(i = 0; i < N; i++)
	{
		gets(list[i].find);
		gets(list[i].replace);
	}
	return ;
}

bool find_string(int &st, int &en, char *s)
{
	bool flag = false;
	int i, j, k, c;
	char temp[MAX];

	char ch = s[0];
	for(i = 0; trans[i]; i++)
	{
		if(trans[i] == ch)
		{
			int len = strlen(s);
			int t = 0;
			for(j = i, k = 0, c = 0; c < len; c++, k++, j++)
			{
				if(s[k] != trans[j])
				{
					temp[t] = '\0';
					break;
				}
				else
					temp[t++] = trans[j];
			}
			temp[t] = '\0';
			if(strcmp(temp, s)==0)
			{
				st = i;
				en = j - 1;
				return true;
			}
		}
	}
	return false;
}

char tempo[MAX];

void init()
{
	for(int i = 0; i < 256; i++)
		tempo[i] = 0;
}

void replace_string(int pos, int st, int en, char *s)
{
	char temp1st[MAX], temp2nd[MAX];
	int i = 0;
	int j = 0;

	for(i = 0, j = 0; trans[i] && i < st; i++)
		temp1st[j++] = trans[i];
	temp1st[j] = '\0';

	for(i = en + 1, j = 0; trans[i]; i++)
		temp2nd[j++] = trans[i];
	temp2nd[j] = '\0';

	init();
	strcat(tempo, temp1st);
	strcat(tempo, list[pos].replace);
	strcat(tempo, temp2nd);
	strcpy(trans, tempo);
}

void calcul()
{
	int i = 0;
	int st, en;
	while(i < N)
	{
		bool f = find_string(st, en, list[i].find);
		if(f == true)
			replace_string(i, st, en, list[i].replace);
		else if(f == false)
			i++;
	}
}

int main()
{
//	freopen("in.txt", "r", stdin);
	
	char xx[MAX];
	while(gets(xx))
	{
		sscanf(xx, "%d", &N);
		if(N == 0)
			break;
		
		read_input();
		gets(trans);

		calcul();
		printf("%s\n", trans);
	}	
	return 0;
}