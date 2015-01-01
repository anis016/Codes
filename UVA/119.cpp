#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

#define MAX 50

long amount[MAX];
int main()
{
	char xx[20000], list[MAX][MAX], giver[MAX], taker[MAX][MAX], sp, *ch;
	long Case, i, n, j, num, amoun, flag=0;


	while(scanf("%ld",&Case)==1)
	{
		memset(amount,0,sizeof(amount));

		if(flag!=0)
			printf("\n");
		flag=1;

		n=Case;

		for(i=0; i<Case; i++)
			scanf("%s", list[i]);

		while(n--)
		{
			scanf("%s%ld%ld%c", giver, &amoun, &num, &sp);
			if(sp==' ' && num!=0)
			{		
				gets(xx);
				
				i=0;
				ch=strtok(xx, " ");
				while(ch!=NULL)
				{
					strcpy(taker[i], ch);
					i++;
					ch=strtok(NULL, " ");
				}

				long sum=0, amo, sp;
				amo=amoun/num;

				sp=amoun-(amo*num);
				
				for(i=0; i<Case; i++)
					if(strcmp(giver, list[i])==0)
					{
						sum=amoun+amount[i]-sp;
						amount[i]=sum;
						break;
					}

					for(i=0; i<num; i++)
					{
						long sub=0;
						for(j=0; j<Case; j++)
							if(strcmp(list[j], taker[i])==0)				
							{
								sub=amount[j]-amo;
								amount[j]=sub;
								break;
							}
					}
			}
		}

		for(i=0; i<Case; i++)
			printf("%s %ld\n", list[i], -1*amount[i]);
	}
	return 0;
}