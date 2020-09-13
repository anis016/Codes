#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100000
#define DIV 240000

struct List
{
	char s[100];
	long h, c, next;
} rec[DIV + 100];

long tab[DIV], n;
char alpha[MAX];
char buf[MAX];

void init_alpha()
{
	alpha['A'] = '2', alpha['B'] = '2', alpha['C'] = '2';
	alpha['D'] = '3', alpha['E'] = '3', alpha['F'] = '3';
	alpha['G'] = '4', alpha['H'] = '4', alpha['I'] = '4';
	alpha['J'] = '5', alpha['K'] = '5', alpha['L'] = '5';
	alpha['M'] = '6', alpha['N'] = '6', alpha['O'] = '6';
	alpha['P'] = '7', alpha['R'] = '7', alpha['S'] = '7';
	alpha['T'] = '8', alpha['U'] = '8', alpha['V'] = '8';
	alpha['W'] = '9', alpha['X'] = '9', alpha['Y'] = '9';
	alpha['Q'] = '0', alpha['Z'] = '0';
}

long hash(char *s)
{
	unsigned long a;

	for (a = 0; *s;)
		a = ((a << 5) | ((a >> 27) & 31)) ^ (*s++ - 'A');

	return (a % DIV);
}

int sort_function( const void *a, const void *b)
{
	char *s, *t;

	s = ((struct List*)a)->s;
	t = ((struct List*)b)->s;

	return strcmp(s,t);
}

void add(char *s)
{
	long i, h;

	for(i = tab[h = hash(s)]; i >= 0; i = rec[i].next) 
    {
        if(rec[i].h == h && strcmp(rec[i].s, s) == 0) 
        {
          	rec[i].c++;
			return;
		}
    }

	i = n++;
	strcpy(rec[i].s, s);
	rec[i].h = h;
	rec[i].next = tab[h];
	tab[h] = i;
	rec[i].c = 1;
}

void init()
{
	long i;

	for(i = 0; i < DIV; i++)
		tab[i] = -1;
}

void inita(long N)
{
	long i, j;

	for(i=0; i<=N; i++)
	{
		rec[i].c = 0;
		rec[i].h = 0;
		rec[i].next = 0;

		for(j=0; j<10; j++)
			rec[i].s[j] = '\0';
	}
	return ;
}

void print()
{
	long flag , i, j;

	
	flag = 0;
	for(i=0; i<n; i++)
	{
		if(rec[i].c > 1)
		{
			long k = 0;
			for(j=0; j<=7; j++)
			{
				if(j == 3)
					printf("-");
				else
				{
					printf("%c", rec[i].s[k]);
					k++;
				}
			}
			printf(" %ld\n", rec[i].c);
			flag = 1;
		}
	}

	if(flag == 0)
		printf("No duplicates.\n");

	return ;
}

void read_input()
{
	long i, N, j;
	char ch;
	static char str[MAX];

	gets(str);
	sscanf(str, "%ld", &N);
	for(i=0; i<N; i++)
	{
		j = 0;
		while(1)
		{
			ch = getchar();

			if(ch == '\n')
				break;

			else
			{
				if(ch == ' ' || ch == '-')
					continue;

				if(ch >= 'A' && ch <= 'Z')
					str[j] = alpha[ch];
				else
					str[j] = ch;

				j++;
			}
		}
		str[j] = '\0';
		add(str);
	}

}

int main()
{
//	freopen("in.txt", "r", stdin);

	long N;

	init_alpha();

	gets(buf);
	sscanf(buf, "%ld", &N);
	getchar();
	while(N--) 
    {
		init();
		read_input();

		qsort(rec, n, sizeof(rec[0]), sort_function);
		
		print();

		if (N > 0)
			printf("\n");
		
		n = 0;
		getchar();
	}

	return 0;
}
