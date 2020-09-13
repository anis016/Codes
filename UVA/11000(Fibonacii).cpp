#include<stdio.h>
#define MAX 80

int main()
{
       long long a,b,d, male, num, fibo[MAX], i, total,c;
 		
	   fibo[0]=0;
	   fibo[1]=1;
	   for(i=2;i<MAX;i++)
	   {
			a=fibo[i-1];
			b=fibo[i-2];
			fibo[i]=a+b;
	   }

	while(1)
	{
        scanf("%lld", &num);

		if(num<0)
			break;
		else if(num==0)
			printf("0 1\n");
		else
		{
    	  	total=0;
     
            d=num+2;
		c=num+3;

            male = fibo[d]-1;
            total = fibo[c] -1;
			printf("%lld %lld\n",male, total);
		}
      
    }
		return 0;
}
