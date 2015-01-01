#include<stdio.h>

int main()
{
 long int p, q, a, b;
 long int n, i;

 scanf("%ld", &n);
 for(i=0;i<n;i++)
 {
    scanf("%lld %lld", &p, &q);
  
      if(p>=q && (p+q)%2==0 && (p-q)%2==0)
	{
           a=(p+q)/2;
           b=p-a;
	 printf("%lld %lld\n", a, b);
	}
	
   else
    printf("impossible\n");
 
 }
 
 return 0;
}
