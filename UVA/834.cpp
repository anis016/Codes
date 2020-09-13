#include<stdio.h>

int main()
{
	long up, down, a=0, b=0, i, j,k=0, hold[100], aa[10];

	while(scanf("%ld %ld", &up, &down)!=EOF)
    {
         for(i=0; ;)
	     {
		    {
			   hold[i] = (up/down);
			   aa[0] = hold[0];
			   a = up%down;
			
			   b = down;
         
			   up = b;
			   down = a;
			   i++;
			}
			if(a<=1)
			{				
				break;
			}
	     }
		 printf("[%ld;",aa[0] );

		 for(j=1; j<i; j++)
			 printf("%ld,", hold[j]);
		 printf("%ld]", up);
	 printf("\n");

	}
	
	return 0;
}
