#include<stdio.h>

int main()
{
 int T, a, b, i, m;
 long double sum;
 long count=1;
 
 scanf("%d", &T);

  for(i=0;i<T;i++)
   {
    scanf("%d %d", &a, &b);
     
	{
      sum=0;
	  if(a<b)
	  {
			for(m=a;m<=b;m++)
			if((m%2)!=0)
			sum+=m;
			printf("Case %ld: %.0llf\n", count++, sum);
         }
	  else
	  {
			for(m=b;m<=a;m++)
			if((m%2)!=0)
			sum+=m;
			printf("Case %ld: %.0llf\n", count++, sum);
	  }
	}

  }
  
  return 0;
}