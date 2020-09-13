#include<stdio.h>

long is_prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 79, 73, 83, 89, 97, 101, 103};
long count[1000];

int main()
{
	long in, i, j, hold, flag, con;
	
	while(scanf("%ld", &in), in)
	{
		i=flag=hold=0;

		printf("%3ld! =", in);
		while(1)
		{
			if(is_prime[i]>in)
				break;
			hold=in;
			while(1)
			{
				hold=hold/is_prime[i];
				
				count[is_prime[i]]+=hold;
				if(hold<is_prime[i])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{		
				i++;
			}
		}
		for(j=0, con=0; j<=in; j++)
		{
			if(count[j]!=0)
			{			
				if(con == 15)
                    printf("\n      "); 
                
                printf("%3d", count[j]);
				count[j]=0;
                con++;
			}
		}
		printf("\n");
	}
	return 0;
}
