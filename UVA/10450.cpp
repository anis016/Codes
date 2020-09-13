#include<stdio.h>
#define MAX 52

int main()
{
       long a,b,d, find, num, fibo[MAX], i, test, j;
 		
	   fibo[0]=0;
	   fibo[1]=1;
	   for(i=2;i<MAX;i++)
	   {
			a=fibo[i-1];
			b=fibo[i-2];
			fibo[i]=a+b;
		}
	
		scanf("%ld", &test);
		for(j=1; j<=test; j++)
		{
          scanf("%ld", &num);
     
           d=num+2;
           find = fibo[d];
        
		   printf("Scenario #%ld:\n%ld\n\n",j , find);
		}
    
		return 0;
}
