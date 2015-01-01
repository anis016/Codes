#include<stdio.h>

int circular[] = {113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};

int main()
{
	int a, b, i, cnt;

	while(scanf("%d", &a)==1)
	{
		if(a < 0)
			break;

		scanf("%d", &b);
		
		cnt = 0;
		for(i = 0; i <= 42; i++)
		{
			if(circular[i] > b)
				break;

			if(circular[i] >= a && circular[i] <= b)
				cnt++;
		}

		if(cnt == 1)
		{
			printf("1 Circular Prime.\n");
		}
		else if(cnt == 0)
		{
			printf("No Circular Primes.\n");
		}
		else
			printf("%d Circular Primes.\n", cnt);
	}
	return 0;
}

/*
//Generate Circular Prime => 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

#define MAX 1000000
#define MAXM 1000576

static char sieve[MAXM];

long J;
struct List
{
	long N;
	long pos;
}list[100];

void make_primes()
{
	register int i, j;

	memset(sieve, 0, sizeof(sieve));

	sieve[0] = sieve[1] = 0; 
	for(i=2; i<=(long)sqrt(MAXM); i++) 
	{	   
		if(sieve[i]==0) 	   
		{ 
			for(j=i*i; j<=MAXM; j=j+i) 
			{ 
				sieve[j]=1;
			}
		} 
	}
}

static int isprime(long n)  // 0 -> prime 1 -> not prime
{
	register int i;

	if (n < MAXM) 
		return (sieve[n]);
	
	for(i=3; i*i<=n; i+=2) 
		if (n%i == 0) 
			return 1;
	return 0;
}

void copy(char *p, queue<char>Q)
{
	while(!Q.empty())
	{
		char ch = Q.front();
		Q.pop();

		*p++ = ch;
	}
	*p = '\0';
}

void generate_circular()
{
	long circular;
	long N, i = 0, cnt = 0, flag;
	long len;
	char str[100], store[100];

	make_primes();

	J = 0;
	for(N = 100; N <= MAX; N++)
	{
		sprintf(str, "%d", N);
		len = strlen(str);
		
		queue<char>Q;
		for(i = 0; i < len; i++)
			Q.push(str[i]);
		
		len = len - 1;
		strcpy(store, str);
		cnt = 0;
		sscanf(store, "%ld", &circular);
		if(isprime(circular) == 1)
			continue;
		cnt++;
		flag = 0;
		while(cnt <= len)
		{
			char ch = Q.front();
			Q.pop();

			Q.push(ch);
			copy(store, Q);
			sscanf(store, "%ld", &circular);
			if(isprime(circular) == 1)
			{
				flag = 1;
				break;
			}
			cnt++;
		}

		if(flag == 0)
		{
			list[J].N = N;
			list[J++].pos = J + 1;
		}
	}
	return ;
}

int main()
{
	int i;

	freopen("out.txt", "w", stdout);

	generate_circular();

	for(i = 0; i < J; i++)
		printf("%ld, ", list[i].N);

	printf("\n%d", J);

	return 0;
}
*/