#include<stdio.h>
#include<string.h>
#define MAX 100000

char str[MAX];
long prio, maxp;
double cost, minc;

int main()
{
	char xx[MAX], x[MAX];
	long pro, req, i, j, count=0, flag = 0;

	while(1)
	{
		gets(xx);
		sscanf(xx, "%ld %ld", &req, &pro);

		if(req==0 && pro==0)
			break;
		
		for(i=0; i<req; i++)
			gets(xx);

		minc = 999999999999.0 ;
		maxp = -1;
		for(j=0; j<pro; j++)
		{
			gets(str);

			gets(xx);
			sscanf(xx, "%f %ld", &cost, &prio);
			
			for(i=0; i<prio; i++)
				gets(xx);

			if(maxp < prio)
			{
				maxp = prio;
				minc = cost;
				strcpy(x, str);
			}
			else if(prio == maxp)
			{
				if(cost < minc)
				{
					maxp = prio;
					minc = cost;
					strcpy(x, str);
				}
			}
		}

		if(flag==1)
		{
			printf("\n");
		}
		flag=1;

		printf("RFP #%ld\n", ++count);
		printf("%s\n", x);
	}
	return 0;
}
