#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 20

long in[MAX];

int main()
{
	char xx[20],test[30];
	long i, k, n, tt;

	for(tt=0; tt<=10; tt++)
			in[tt]=true;	

	while(1)
	{
		gets(test);
		sscanf(test,"%ld", &n);

		if(n==0)
			break;
		else
		{
			gets(xx);

			if(strcmp(xx, "too high")==0)
			{
				for(i=n; i<=10; i++)
					in[i]=false;
			}

			if(strcmp(xx, "too low")==0)
			{
				for(k=n; k>=1;k--)
				{
					in[k]=false;
				}
			}

			if(strcmp(xx, "right on")==0)
				if(in[n]==1)
				{
					printf("Stan may be honest\n");
					for(tt=0; tt<=10; tt++)
						in[tt]=true;
				}
				else
				{
					printf("Stan is dishonest\n");
					for(tt=0; tt<=10; tt++)
						in[tt]=true;
				}
		}
	}
	return 0;
}
