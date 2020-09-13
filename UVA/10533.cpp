#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4789)
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<ctime>
#include<stack>
using namespace std;

#define eps 1e-8
#define pinf (1<<30)
#define ninf -1*pinf
#define pi (2*acos(0.0))
//typedef long long long long LL;
//typedef __int64   LL;
inline bool iseq(double x,double y){if(fabs(x-y)<eps)return true;return false;}
#define _max(a,b)  ((a) > (b) ? (a) : (b))
#define _min(a,b)  ((a) < (b) ? (a) : (b))


#define Fin freopen("in.txt", "r", stdin)
#define Fout freopen("out.txt", "w", stdout)

#define MAX 1000001
//#define MAX 50

int n, m;

long a[MAX];
struct List
{
	long val;
	long cnt;
}d_prime[MAX];

long d;

long make_digit(long res)
{
	long sum = 0;
	while(res)
	{
		sum += res % 10;
		res /= 10;
	}
	return sum;
}

void generate()
{
	long i,j,k,M;
	
	M=(long)sqrt((double)MAX);
	
	for(i=3;i<=M;i+=2)
		if(a[i]==0)
			for(j=i*i;j<=MAX;j=j+i+i)
				if(j <= MAX)            // carefull or overflow may occur
					a[j]=1;

	d_prime[0].val = 2;
	d_prime[0].cnt = 1;
	d = 1;
	for(k=3; k<=MAX; k=k+2)
		if(a[k]==0)
		{
			long digit = make_digit(k);
			if( ((a[digit] == 0) && (digit == 2)) || ( (a[digit] == 0) && (digit % 2 == 1) ) )
				d_prime[d].val = k, d_prime[d].cnt = d_prime[d-1].cnt + 1, d++;
		}
	d--;	
	return ;
}

int b_search(long key)
{
	long low = 0;
	long high = 30122;
	long mid = 0;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if( key < d_prime[mid].val )
			high = mid - 1;
		else if( key == d_prime[mid].val )
			return d_prime[mid].cnt;
		else if(key > mid)
			low = mid + 1;
	}
	return 0;
}

int main()
{
	long n, m, test;

	generate();

	scanf("%ld", &test);
	while(test--)
	{
		scanf("%ld %ld", &n, &m);
	
		long i;
		long t1 = 0, t2 = 0;
		for(i = n; i <= m; i++)
		{
			t1 = b_search(i);
			if(t1 != 0)
				break;
		}

		for(i = m; i >= n; i--)
		{
			t2 = b_search(i);
			if(t2 != 0)
				break;
		}

		long res = t2 - t1 + 1;
		if( (t2 == 0 && t1 == 0) )
		{
			printf("0\n");
			continue;
		}

		printf("%ld\n", res);
	}

	return 0;
}