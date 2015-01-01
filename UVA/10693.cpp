#include<stdio.h>
#include<math.h>

int main()
{
  long double t, v, volume;
  long int f, L;
  
  for( ; ; )
  {
 
     scanf("%ld %ld", &L, &f);
   
    if(L==0 && f==0)
		  break;
	else
	{
	   v = sqrt(2*f*L);
	   t=v/f;
	   volume=3600/t;

       printf("%.8llf %.8llf\n", v, volume);	
	}
  }
  
  return 0;
}

