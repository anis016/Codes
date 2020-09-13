#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define MOD 16349
long M=0;

struct List
{
	char str[40];
	long occ, hash;
}buff[17000];

int sort_function( const void *a, const void *b)
{
	char *s, *t;

	s = ((struct List*)a)->str; //by changing ->t/s we can get a diffrnt sort
	t = ((struct List*)b)->str; //by changing ->t/s we can get a diffrnt sort

	return strcmp(s,t);
}

void init(void )
{
	long i;

	for(i=0; i<(MOD+100); i++)
	{
		buff[i].occ = 0;
		buff[i].hash = -1;
	}

	return ;
}

long hash_table(char *s) // algo : first do left shift according to a prime number right shift according to a prime number do bitwise anding with 11111 as mod is done with max. 5 digits, and then do bitwise or proceeding with bitwise XOR with each character;
{
	unsigned long a;

	for (a = 0; *s;)
		a = ((a << 5) | ((a >> 27) & 31)) ^ (*s++ - 'A');

	return (a % MOD);
}

void update_string(char *s, long hash)
{
	long i;

	for(i=0; i<M; i++)
	{
		if( (buff[i].hash == hash) && strcmp(s, buff[i].str)==0)
		{	
			buff[i].occ++;
			return ;
		}
	}

	strcpy(buff[M].str, s);
	buff[M].occ++;
	buff[M].hash = hash;
	M++;

	return ;
}

void do_hashing(char *s)
{
	long hash;

	hash = hash_table(s);
	update_string(s, hash);
}

int main()
{
//	freopen("10226.txt", "r", stdin);
	static char in[1524], xx[1524];
	long n, i, Case;
	
	gets(xx);
	sscanf(xx, "%ld", &Case);
	gets(xx);

	while(Case-- > 0)
	{
		init();
		n=0;
		while(gets(in))
		{
			if(strcmp(in, "")==0)
				break;

			do_hashing(in);
			n++;
		}

		qsort(buff, M, sizeof(buff[0]), sort_function);

		for(i=0; i<M; i++)
		{
			printf("%s %.4lf\n", buff[i].str, (double)buff[i].occ * 100.00 / (double)n );
		}
		M=0;

		if(Case > 0)
			printf("\n");
	}	
	return 0;
}


/*

  // best thing i can think of but why WA ???? check later
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define MOD 16349
long M=0;

struct List
{
	char str[40];
	long occ, hash;
}buff[17000];

long check[17000];

int sort_function( const void *a, const void *b)
{
	char *s, *t;

	s = ((struct List*)a)->str; //by changing ->t/s we can get a diffrnt sort
	t = ((struct List*)b)->str; //by changing ->t/s we can get a diffrnt sort
	return strcmp(s,t);
}

void init(void )
{
	long i;

	for(i=0; i<(MOD+100); i++)
	{
		check[i] = -1;
		buff[i].occ = 0;
		buff[i].hash = -1;
	}

	return ;
}

long hash_table(char *s) // algo : first do left shift according to a prime number right shift according to a prime number do bitwise anding with 11111 as mod is done with max. 5 digits, and then do bitwise or proceeding with bitwise XOR with each character;
{
	unsigned long a;

	for (a = 0; *s;)
		a = ((a << 5) | ((a >> 27) & 31)) ^ (*s++ - 'A');

	return (a % MOD);
}

void add_string(char *s, long hash)
{
	strcpy(buff[M].str, s);
	buff[M].occ++;
	buff[M].hash = hash;
	M++;

	return ;
}

void update_string(char *s, long hash)
{
	long i;

	for(i=0; i<M; i++)
	{
		if( (buff[i].hash == hash) && strcmp(s, buff[i].str)==0)
		{	
			buff[i].occ++;
			break;
		}
	}
	return ;
}

void do_hashing(char *s)
{
	long hash;

	hash = hash_table(s);
	if(check[hash] == -1)
	{
		add_string(s, hash);
		check[hash] = hash;
	}
	else
		update_string(s, hash);
}

int main()
{
//	freopen("10226.txt", "r", stdin);
	static char in[1524], xx[1524];
	long n, i, Case;
	
	gets(xx);
	sscanf(xx, "%ld", &Case);
	gets(xx);

	while(Case-- > 0)
	{
		init();
		n=0;
		while(gets(in))
		{
			if(strcmp(in, "")==0)
				break;

			do_hashing(in);
			n++;
		}

		qsort(buff, M, sizeof(buff[0]), sort_function);

		for(i=0; i<M; i++)
		{
			printf("%s %.4lf\n", buff[i].str, (double)buff[i].occ * 100.00 / (double)n );
		}
		M=0;

		if(Case > 0)
			printf("\n");
	}	
	return 0;
}
*/