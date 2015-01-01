#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define MAX 30
#define Sin 130

int fun_name(  const void *a, const void *b )        
{
	long *p = (long *)a;  
	long *q = (long *)b;  
	return *q - *p ;   
}

char alp[MAX][MAX];
char temp[Sin];

long hold[Sin];
long temp_hold[Sin];
long res[Sin];

long MAXC, im;
long R, C, M, N;
long i, j, k, l, g, ans, ii, gg, ll;
long test, temp_C;

int main()
{
	cin>>test;
	while(test--)
	{
		cin>>R>>C>>M>>N;
		
		k=0;
		for(i=0; i<R; i++)
		{
			for(j=0; j<C; j++)
			{
				cin>>alp[i][j];
				temp[k]=alp[i][j];
				k++;
			}
		}
		temp[k+1]='\0';
		
		for(i=0; i<k; i++)
			hold[temp[i]]++;

		for(i=65, l=0; i<91; i++)
		{
			if(hold[i]!=0)
			{
				temp_hold[l]=hold[i];
				l++;
			}
		}

		qsort(temp_hold, l, sizeof(long), fun_name);

		MAXC=im=ans=0;
		for(i=0; i<l; i++)
		{
			if(temp_hold[i]>=MAXC)
			{
				MAXC=temp_hold[i];
				ans+=temp_hold[i]*M;
				temp_hold[i]=0;
			}
			else
			{
				ans+=temp_hold[i]*N;
				temp_hold[i]=0;
			}
		}
	
		printf("Case %ld: %ld\n", ++ii, ans);

		for(i=65; i<91; i++)
		    hold[i]=0;
	}
	return 0;
}