#include<stdio.h>
#include<string.h>
#define MAX 100000

char in[MAX],in1[MAX], xx[MAX]; 
long len, test, i, it, l, k, test1, ii, len1,j,p, zz;
long count[MAX];

int main()
{
	gets(xx);
	sscanf(xx, "%ld", &test1);
	
	while(test1--)
	{
		gets(in1);
		
		len=test=len1=0;

		for(zz=97; zz<123; zz++)
		{
			count[zz]=0;
			if(zz==122)
				break;
		}

		len1=strlen(in1);
		for(it=0,j=0; it<len1; it++)
		{
			if(in1[it]>='A' && in1[it]<='Z')
			{
				in[j]=in1[it]+32;
				j++;
			}
			else if(in1[it]>='a' && in1[it]<='z')
			{
				in[j]=in1[it];
				j++;
			}
		}

//		in[j]='\0';	
		
		for(i=0; i<j; i++)
			if(in[i]>=97 && in[i]<=122)
				count[in[i]]++;
			
		for(l=97; l<=122; l++)
			if(count[l]>test)
				test=count[l];	
			
		for(k=97; k<=122; k++)
				if(test==count[k])
					printf("%c", k);
				printf("\n");
	}
	return 0;
}
