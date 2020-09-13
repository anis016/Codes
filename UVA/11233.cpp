#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAX 5000

struct List
{
	char str1[MAX];
	char str2[MAX];
}list[MAX];

int sort_function(const void *a, const void *b)
{
	char *s, *t;

	s=((struct List*)a)->str1;
	t=((struct List*)b)->str1;

	return strcmp(s, t);
}

long B_search(char *s, long N)
{
	long high=N-1;
	long low=0;
	long mid=0;
	long found=0;

	while(low<=high)
	{
		mid=(low+high)/2;
		found=strcmp(s, list[mid].str1);
		if(found<0)
			high=mid-1;
		else if(found>0)
			low=mid+1;
		else if(found==0)
			return mid;
	}
	return -1;
}

int main()
{
	char xx[MAX], buf[MAX];
	long i, len, N, kase, num;

	N=0;
	gets(xx);
	sscanf(xx, "%ld %ld", &kase, &num);
	
	while(kase--)
	{
		gets(buf);
		sscanf(buf, "%s %s", list[N].str1, list[N].str2);
		N++;
	}

	qsort((void *)list, N, sizeof(list[0]), sort_function);

	while(num--)
	{
		i=0;
		cin>>buf;
		len=strlen(buf);

		i=B_search(buf, N);
		if(i!=-1)
			puts(list[i].str2);
		
		else if( (buf[len-1]=='y') && !(buf[len-2]=='a' || buf[len-2]=='e' || buf[len-2]=='i' || buf[len-2]=='o' || buf[len-2]=='u') )
		{
			buf[len-1]='\0';
			puts(strcat(buf, "ies"));
		}
		
		else if(buf[len-1]=='o' || buf[len-1]=='s' || (buf[len-1]=='h' && buf[len-2]=='c') || (buf[len-1]=='h' && buf[len-2]=='s') || buf[len-1]=='x')
		{
			puts(strcat(buf, "es"));
		}
		
		else
		{
			puts(strcat(buf, "s"));
		}
	}
	

	return 0;
}