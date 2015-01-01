#include<stdio.h>

int main()
{
	double H, M, A_H, A_M, diff, final;
      char c;
	while(scanf("%lf%c%lf", &H,&c,&M)!=EOF)
	{
		if(H==0 && M==0)
			break;
		{
		diff=0;
		   A_H=((H*60)+M)/2;
		   A_M=6*M;

	       diff=(A_H-A_M);
		   if(diff<0)
		   final=diff*-1;
		   else final=diff;
	
		  // final=abs(diff);
			if(final>180)
				final=360-final;
		printf("%.3lf\n", final);
		}
	}

	return 0;
	
}

			
