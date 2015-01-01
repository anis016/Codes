#include<stdio.h>
#include<math.h>

int main()
{
	double n, l;
	double a, hold, dx, cube_a, square_a;
	long i;

	while(1)
	{
		scanf("%lf", &n);
		if(n==0.0000)
			break;
		else
		{
			for(i=0; i<1000; i++)
            {
               if(pow(i, 3)>n)
               {
                  l=i;
                  break;
               }
            } 
            a=l-1;
            
            cube_a=pow(a, 3);
            square_a=pow(a, 2);
            
            dx = (n-cube_a)/(3*square_a);			
            hold= a+dx;
            
			printf("%.4lf\n", hold);
		}
	}

	return 0;
}


