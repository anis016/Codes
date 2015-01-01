#include<cstdio>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
#define MAXIM 1001

int factor[MAXIM + 100][50];
int a[MAXIM + 100], prime[MAXIM + 100];
bool fact[MAXIM + 100];

void inita()
{
	int i, j, t, k;
	int M = (int)sqrt(MAXIM);

	for(i = 3; i <= M; i+=2)
		if(a[i] == 0)
		{
			for(j = i * i; j <= MAXIM; j += 2 * i)
				a[j] = 1;
		}

	for(k = 3, t = 1; k <= MAXIM; k += 2)
		if(a[k] == 0)
		{
			fact[k] = true;
			prime[t++] = k;
		}
	fact[2] = true;
	prime[0] = 2;
}

void init()
{
	int i;
	for(i = 0; i <= MAXIM; i++)
		factor[i][0] = -1;
}

int find_factor(int N)
{
	int counter = 0;
	int i, MM = (int)sqrt(N);

	if(factor[N][0] == -1)
	{
		for(i = 2; i <= MM; i++)
		{
			if(N % i == 0)
			{
				if(fact[i] == true)
					factor[N][counter++] = i;
				if(fact[N / i] == true && (N / i) != i)
					factor[N][counter++] = N / i;
			}
		}
		return counter;
	}

	else
	{
		for(i = 0; ; i++)
			if(factor[N][i] == 0)
				break;
	}
	return i;
}

int BFS(int source, int dest)
{
	int i, counter = 0;

	bool occurence[MAXIM];
	typedef pair<int, int>ii;
	queue<ii>Q;
	memset(occurence, false, sizeof(occurence));

	Q.push(ii(source, 0));
	while(!Q.empty() )
	{
		ii Top = Q.front();
		Q.pop();

		if(Top.first == dest)
			return Top.second;
		if(occurence[Top.first] == true)
			continue;

		occurence[Top.first] = true;

		int number = find_factor(Top.first);
		for(i = 0; i < number; i++)
		{
			int sum = factor[Top.first][i] + Top.first;
			if( sum <= dest)
			{
				Q.push(ii(sum, Top.second + 1));
			}
		}
		
	}
	return -1;
}

int main()
{
	int Case = 1, n, m;

	inita();
	init();
	while(scanf("%d %d", &n, &m) == 2)
	{
		if(!n && !m)
			break;
		
		int counter = BFS(n, m);

		printf("Case %d: %d\n", Case++, counter);
	}
	return 0;
}