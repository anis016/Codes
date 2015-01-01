#include<stdio.h>
#include<string.h>
long test, i, j, s, k, flag,sum,n,tt;
char x[10],temp,lod[10002];

int main()
{

	
	gets(x);
	sscanf(x,"%ld", &test);
	k=1;
	while(test!=0)
	{
		gets(lod);
		n=strlen(lod);
		flag=0;
		sum=0;
		if(n!=0)
		{
			test--;
		printf("Case %ld: ",k++);
		for(i=0;i<n;i++)
		{
			if(lod[i]>='A' && lod[i]<='Z')
			{
				if(flag==0)
				{
					temp=lod[i];
					flag=1;
				}
				else
				{
					tt=sum;
					for(j=0;j<tt;j++)
					{
						printf("%c",temp);
					}
						temp=lod[i];
						sum=0;
				}
			}
			if(lod[i]>='0' && lod[i] <='9')
				sum=(sum*10)+(lod[i]-48);

		}
		for(j=0;j<sum;j++)
		{
			printf("%c",temp);
		}
		printf("\n");
		memset(lod,0,sizeof(lod));
		}
	}
	return 0;
}
