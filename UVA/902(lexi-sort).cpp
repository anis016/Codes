#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cassert>
#include<algorithm>
using namespace std;

#define MAX 1000100

char *temp[MAX];
char word[MAX];

long n;

bool cmp(const char *a, const char *b) 
{ 
    return memcmp(a, b, n) < 0; 
}

int main()
{
	char *x, *ans;
	
	long i, st, len, count, max;

	while(scanf("%ld %s", &n, word) == 2)
	{
		len=strlen(word);
		st = 0;
		for(i=0; i<len; i++)
		{
			st++;
			temp[i]=word+i;
			if(i==(len-n)+1)
				break;
		}
		sort(temp, temp + st, cmp );
		max=0;
		count=0;
		ans=word;
		for(i=0; i<st; )
		{
			count=0;
			x=temp[i];
			for( ;i<st; )
				if(strncmp(x, temp[i], n)==0)
				{
					i++;
					count++;			
				}
				else
					break;
		    if(count>max)
			{
				ans=x;
				max=count;
			}
		}
		printf("%.*s\n", n, ans);
	}
	return 0;
}
