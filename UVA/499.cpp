#include<stdio.h>
#include<string.h>

int main()
{
	char in[10000]; 
	long len, test=0, i, l, k;
    long count[500];
	
	while(gets(in))
	{
		test=0;
		len=0;
		
		for(long p=0; p<500; p++)
			count[p]=0;
//		memset(count,0,sizeof(count));    //do not use memset
		
		len=strlen(in);

		for(i=0; i<len; i++)
			if(in[i]>=65 && in[i]<=122)
			count[in[i]]++;
		
		for(l=0; l<500; l++)
			if(count[l]>test)
				test=count[l];
			
		for(k=0; k<500; k++)
				if(test==count[k])
					printf("%c", k);
				printf(" %ld\n",test);
	}
	
	return 0;

}
