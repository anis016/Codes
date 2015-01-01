#include<stdio.h>
#include<string.h>

#define MAX 100000

char in[MAX],  hold[MAX], takec[MAX], ch[MAX], tempch; 
char xx[100];
long count[MAX], takel[MAX];

int main()
{
	long n, i, j, len, t,  lena, d, max=0, l, temp;
	
	for(i=0; i<MAX; i++)
		count[i]=0;

	gets(xx);
	sscanf(xx, "%ld", &n);

	t=0;
	for(i=0; i<n; i++)
	{
		len=0;
		gets(in);
		
		len=strlen(in);
		for(j=0; j<len; j++)
		{
			if( (in[j]>='a' && in[j]<='z') )
			{
				hold[t]=in[j]-'a'+'A';
				t++;
			}
			else if( (in[j]>='A' && in[j]<='Z') )
			{
				hold[t]=in[j];
				t++;
			}
		}
	}

	lena=strlen(hold);
	
	for(d=0; d<lena; d++)
		count[hold[d]]++;

	for(d=0, l=0; d<MAX; d++)
	{
		if(count[d]!=0)
		{
			takec[l]=d;
			takel[l]=count[d];
			l++;
		}
	}

	for(i=0; i<l; i++)
		for(j=0; j<l-1; j++)
			if(takel[j]<takel[j+1])
			{
				temp=takel[j];
				tempch=takec[j];

				takel[j]=takel[j+1];
				takec[j]=takec[j+1];

				takel[j+1]=temp;
				takec[j+1]=tempch;
			}

	for(i=0; i<l; i++)
		printf("%c %ld\n", takec[i], takel[i]);
		
    return 0;
}