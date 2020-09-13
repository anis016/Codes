#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define MAX 1000
#define MAXR 110

char xxle[MAX], xx[MAX];
char in[MAXR][MAXR];
char store[MAXR][MAXR];
char temp[MAX];
long num[MAX];

long sort(char *ss, long l)
{
	long count;
	char temp;
	long i, j;

	count=0;
	for(i=0; i<(l-1); i++)
		for(j=0; j<(l-1)-i; j++)
			if(ss[j] > ss[j+1])
			{
				temp = ss[j+1];
				ss[j+1] = ss[j];
				ss[j] = temp;
				count++;
			}
	return count;
}

int main()
{
	long line, length, ll, dd;		
	long i, j, hv, t, p, k, l, ch, test,kk;

    scanf("%ld\n", &test);

	for(ll=1; ll<=test; ll++)
	{

	  scanf("%ld %ld\n", &length, &line);

	  hv=dd=0;
	  for(i=0, t=0; i<line; t++, i++)
	  {
		for(j=0, p=0; j<=length; p++, j++)
		{
			scanf("%c", &in[i][j]);
			store[t][p]=in[i][j];
		}
		in[i][j+1]='\0';
		store[t][p+1]='\0';
	  }

	for(t=0, k=0, hv=0; t<line; t++)              //// sorting
	{
		hv=sort(in[t], length);
		num[k]=hv;
		k++;
	}

	for(kk=1; kk<=line; kk++)                  //// length === coloumn
		for(l=1; l<=(line-kk); l++)                   //// line   === row
			if(num[l]<num[l-1])                 //// sort row wise
			{
				ch=num[l];
				strcpy(temp, store[l]);

				num[l]=num[l-1];
				strcpy(store[l], store[l-1]);

				num[l-1]=ch;
				strcpy(store[l-1], temp);
			}
	strcpy(temp, "\0");

	for(t=0; t<line; t++)
	{
		num[t]=0;
		for(p=0; p<=length; p++)
		{
			printf("%c", store[t][p]);
			store[t][p]=in[t][p]='\0';
			num[p]=0;
		}
	}

	if(ll!=test)
		printf("\n");
	}

    return 0;
}
