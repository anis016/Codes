#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX  30000
#define DIV  16349

struct List{
	char s[1000];
	int h, c, next;
} rec[16384];

struct buff
{
	char str[1000];
}list[MAX];

int tab[DIV], n, N;

int hash(char *s)
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
	int i, h;

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

	return ;
}

void init(void )
{
	long i;
	for (i = 0; i < DIV; i++)
			tab[i] = -1;
	return ;
}

char x[MAX];

char *delms = " ~!@#$%^&*()_+`1234567890-=[]{}|;\':,.<>/?\\\"\n\t";
void convert(char *buf)
{
	long i, len;
	char *p;
	char s[MAX];

	p=strtok(buf, delms);
	while(p!=NULL)
	{
		if(p)
		{
			strcpy(s, p);

			len=strlen(s);
			for(i=0; i<len; i++)
			{
				if(s[i]>='A' && s[i]<='Z')
				{
					s[i] = s[i]-'A'+'a';
				}
			}
			s[i] = '\0';

			add(s);
		}			
		p=strtok(NULL, delms);
	}
	return ;
}

char buf[1024];

int main()
{
	int i, t, tt, flag;
	
	for(tt = 0; gets(buf) && sscanf(buf, "%ld", &t); tt++)
	{
		init();
		n = N = 0;
		while(gets(buf))
		{
			if(strcmp(buf, "EndOfText")==0)		
				break;

			if(strcmp(buf, " ")==0)
				continue;

			convert(buf);
		}

		qsort(rec, n, sizeof(rec[0]), sort_function);

		if(tt > 0) 
			putchar('\n');

		flag = 0;
		for(i=0; i<n; i++)
		{
			if(rec[i].c == t)
			{
				printf("%s\n", rec[i].s);
				flag = 1;
			}
		}
		if(flag == 0)
			printf("There is no such word.\n");
	}

	return 0;
}
