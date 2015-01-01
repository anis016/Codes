#include<stdio.h>
#include<string.h>

#define MAX 10000

char in[MAX], holdc[MAX], ch_temp;
long hold[MAX], holdl[MAX], long_temp;

int main()
{
	long i, len, j, k, flag=0;

//  fill(hold, hold+MAX, 0);

	while(gets(in))
	{
		if(flag==1)
			printf("\n");
		flag=1;
		for(i=0; i<MAX; i++)
			hold[i]=0;

		len=strlen(in);
		
		for(i=0; i<len; i++)
			hold[in[i]]++;
		
		for(i=0, j=0; i<MAX; i++)
		{
			if(hold[i]!=0)
			{
				holdc[j]=i;
				holdl[j]=hold[i];
				j++;
			}
		}
		for(i=0; i<j; i++)
			for(k=0; k<j-1; k++)
				if(holdl[k]>holdl[k+1])
				{
					long_temp=holdl[k];
					ch_temp=holdc[k];
					
					holdl[k]=holdl[k+1];
					holdc[k]=holdc[k+1];

					holdl[k+1]=long_temp;
					holdc[k+1]=ch_temp;
				}
				else if( (holdl[k]==holdl[k+1]) )
				{
					if(holdc[k]<holdc[k+1])
					{
						long_temp=holdl[k];
						ch_temp=holdc[k];
					
						holdl[k]=holdl[k+1];
						holdc[k]=holdc[k+1];

						holdl[k+1]=long_temp;
						holdc[k+1]=ch_temp;
					}
				}

	    for(i=0; i<j; i++)
			printf("%ld %ld\n", holdc[i], holdl[i]);
	}
	return 0;
}
